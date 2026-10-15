#pragma once

#include <iostream>
#include <string>

typedef int elem;

using namespace std;

class noobVector{
    private:
        int capacity;
        int n;
        elem* arr;
    public:
        // constructor
        noobVector();
        // overloading constructor
        noobVector(int cap, int n, const elem& val);
        // destructor
        ~noobVector();
        
        // copy construcotr
        noobVector(const noobVector& v);
        // copy assignment
        noobVector& operator=(const noobVector& v);

        // move constructor
        noobVector(noobVector&& v);
        // move assignment
        noobVector& operator=(noobVector&& v);

        int size();
        bool empty();
        void insert(int idx, const elem& val);
        void erase(int idx);
        void set(int idx, const elem& val);
        elem& at(int idx);
        elem& operator[](int idx);
        void reserve(int num);
        void push_back(const elem& val);
        void pop_back();
};