#include <iostream>
#include <stdexcept>

#include "noobvector.h"

using namespace std;

// default constructor
noobVector::noobVector()
    : capacity{0},
    n {0},
    arr {NULL}
{}

// constructor overload
noobVector::noobVector(int cap, int n, const elem& val)
    : capacity {cap}, 
    n {n},
    arr{new elem[cap]}
{
    for (int i = 0; i < n; i++){
        arr[i] = val;
    }
}

// destructor
noobVector::~noobVector(){
    delete[] arr;
}

// copy constructor
noobVector::noobVector(const noobVector& v){
    capacity = v.capacity;
    n = v.n;

    arr = new elem[capacity];

    for (int i = 0; i < n; i++){
        arr[i] = v.arr[i];
    }
}

// copy assignment
noobVector& noobVector::operator=(const noobVector& v){
    if (this == &v){
        return *this;
    }

    elem* temp = new elem[v.capacity];

    for (int i = 0; i < v.n; i++){
        temp[i] = v.arr[i];
    }

    delete[] arr;
    arr = temp;
    capacity = v.capacity;
    n = v.n;

    return *this;
}

// move constructor
noobVector::noobVector(noobVector&& v)
    : capacity {v.capacity},
    n {v.n},
    arr {v.arr}
{
    v.capacity = 0;
    v.n = 0;
    v.arr = nullptr;
}


noobVector& noobVector::operator=(noobVector&& v){
    if (this == &v){
        return *this;
    }

    delete[] arr;

    capacity = v.capacity;
    n = v.n;
    arr = v.arr;
    v.capacity = 0;
    v.n = 0;
    v.arr = nullptr;

    return *this;
}

int noobVector::size(){
    return n;
}

bool noobVector::empty(){
    return n == 0;
}

void noobVector::insert(int idx, const elem& num){
    if (idx >= capacity){
        cout << "vector is full" << endl;
        return;
    }

    if (idx < 0 || idx > n){
        cout << "out of range" << endl;
        return;
    }

    // shift everything right 1
    for (int i = n; i > idx; i--){
        arr[i] = arr[i-1];
    }
    // set the idx and increment
    arr[idx] = num;
    n++;
}

void noobVector::erase(int idx){
    // check if its out of range
    if (idx >= n){
        cout << "out of range" << endl;
        return;
    }

    // shift everything left 1
    for (int i = idx; i < n-1; i++){
        arr[i] = arr[i+1];
    }
    // decrement n
    n--;
}

void noobVector::set(int idx, const elem& val){
    if (idx < 0 || idx >= n){
        throw out_of_range("Index out of range");
    }

    arr[idx] = val;
}

elem& noobVector::at(int idx){
    if (idx < 0 || idx >= n){
        throw out_of_range("Index out of range");
    }

    return arr[idx];
}

elem& noobVector::operator[](int idx){
    if (idx < 0 || idx >= n){
        throw out_of_range("Index out of range");
    }

    return arr[idx];
}

void noobVector::reserve(int num){
    if (num <= capacity){
        return;
    }

    // otherwise need bigger array
    elem* temp = new elem[num];

    for (int i = 0; i < n; i++){
        temp[i] = arr[i];
    }

    delete[] arr;
    arr = temp;
    capacity = num;
}

void noobVector::push_back(const elem& num){
    if (n == 0){
        reserve(1);
    }
    if (n == capacity){
        reserve(capacity * 2);
    }

    arr[n] = num;
    n++;
}

void noobVector::pop_back(){
    if (n == 0){
        return;
    }

    n--;
    arr[n] = 0;
}