#include <iostream>
#include <utility>

#include "noobvector.h"

using namespace std;

int main(){

    noobVector a(5, 5, 0);
    noobVector b(3, 1, 3);
    noobVector c(0, 0, 0);

    a.push_back(10);
    a.insert(2, 5);
    cout << a.size() << endl;
    cout << a.empty() << endl;

    cout << "a vector" << endl;
    for (int i = 0 ; i < a.size(); i++){
        cout << a[i] << endl;
    }

    b = a;

    c = std::move(a);
    cout << "c vector" << endl;
    for (int i = 0; i < c.size(); i++){
        cout << c[i] << endl;
    }
    noobVector d(std::move(c));

    cout << "a vector" << endl;
    for (int i = 0; i < a.size(); i++){
        cout << a[i] << endl;
    }
    cout << "b vector" << endl;

    for (int i = 0; i < b.size(); i++){
        cout << b.at(i) << endl;
    }

    cout << "d vector" << endl;

    for (int i = 0; i < d.size(); i++){
        cout << d[i] << endl;
    }
}