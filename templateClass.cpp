//
// Created by Mert Aydın on 15.11.2021.
//

#include <iostream>

using namespace std;

template<class T>
class Arithmetic {
private:
    T a;
    T b;

public:
    Arithmetic(T a, T b);
    T add();
    T sub();
    ~Arithmetic();
};

template<class T>
Arithmetic<T>::Arithmetic(T a, T b) {
    this->a = a;
    this->b = b;
}

template<class T>
T Arithmetic<T>::add() {
    T c;
    c = a + b;
    return c;
}

template<class T>
T Arithmetic<T>::sub() {
    T c;
    c = a - b;
    return c;
}

template<class T>
Arithmetic<T>::~Arithmetic() {}


int main() {
    Arithmetic<float> a1(10.3,5.8);
    Arithmetic<int> a2(10,5);

    cout <<"Addition: " << a1.add() << endl;
    cout <<"Subtraction: " << a1.sub() << endl;

    cout <<"Addition: " << a2.add() << endl;
    cout <<"Subtraction: " << a2.sub() << endl;

    return 0;
}
