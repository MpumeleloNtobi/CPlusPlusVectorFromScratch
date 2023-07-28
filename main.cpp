// Standard header files
#include <iostream>

// Custom header files
#include "MyVector.h"

using namespace std;

// Define the default constructor
MyVector::MyVector() {
    data = nullptr;
    n_allocated = 0;
    n_items = 0;
}

MyVector::~MyVector() {
    if (n_allocated == 0) {
        delete data;
    }
    else {
        delete [] data;
    }
    data = nullptr;
}

int MyVector::size() {
    return n_items;
}

void MyVector::push_back(int v) {
    if (n_items == n_allocated) {
        if (n_items == 0) {
            data = new int[1];
        }
        else {
            reallocate(n_allocated * 2);
        }
    }
    *(data + n_items) = v; // ~ data[n_items] = v;
    n_items++;
}

void MyVector::pop_back() {
    if (n_items != 0) {
        n_items--;
        if (n_items < (n_allocated / 4)) {
            reallocate(n_allocated / 2);
        }
    }
}

void MyVector::reallocate(int new_size) {
    int* new_buffer = new int[new_size];
    n_allocated = new_size;
    for (int i = 0; i < n_items; i ++) {
        *(new_buffer + i) = *(data + i);
    }
    data = new_buffer;
    delete [] new_buffer;
    new_buffer = nullptr;
}

int& MyVector::operator[](int i) {
    return *(data + i);
}

int& MyVector::at(int i) {
    if ((i >= n_items) && (i < n_items)) {
        return *(data + i);
    }
    throw out_of_range("Index out of bounds.");
}

int main()
{
    MyVector vec;

    vec.push_back(3);
    vec.push_back(5);
    vec.push_back(8);

    cout << vec[0] << endl;
    cout << vec[1] << endl;
    cout << vec[2] << endl;

    return 0;
}
