#ifndef MYVECTOR_H
#define MYVECTOR_H

// Declare a MyVector class (interface)
class MyVector {
    public:
        // Class member variables
        int* data;
        int n_allocated;
        int n_items;

        // Class constructors and destructor
        MyVector(); // Constructor
        ~MyVector(); // Destructor

        // Class member functions
        void push_back(int v);
        void pop_back();
        void reallocate(int new_size);
        int& operator[](int i);
        int& at(int i);
};

#endif // MYVECTOR_H
