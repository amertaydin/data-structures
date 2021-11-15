//
// Created by Mert Aydın on 15.11.2021.
//

#include <iostream>

using namespace std;

struct Rectangle {
    int length;
    int breadth;
};

void callByValue(Rectangle r) {
    r.length = 29;
    cout << "Length: " << r.length << endl << "Breadth: " << r.breadth << endl;
}

void callByAddress(Rectangle *r) {
    r->length = 29;
    cout << "Length: " << r->length << endl << "Breadth: " << r->breadth << endl;
}

Rectangle *fun() {
    Rectangle *p;
    p = new Rectangle;
    // p = (struct Rectangle *)malloc(sizeof(struct Rectangle));

    p->length = 15;
    p->breadth = 7;

    return p;
}

int main() {
    Rectangle r = {10,5};

    callByValue(r);

    cout << "Length : " << r.length << endl << "Breadth : " << r.breadth << endl;

    callByAddress(&r);

    cout << "Length : " << r.length << endl << "Breadth : " << r.breadth << endl;

    Rectangle *ptr = fun();

    cout << "Length: " << ptr->length << endl <<"Breadth: " << ptr->breadth << endl;

    return 0;

}
