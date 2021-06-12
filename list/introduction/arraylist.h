#pragma once

#include "linearlist.h"
#include<iostream>

template <class T>
class ArrayList: public LinearList
{
private:
    T *data;
    int max_size;
    int length;

protected:
    void checkIndex(int index) const ;

public:
    ArrayList(int initCapacity);
    ArrayList(const ArrayList<T>&);
    ~ArrayList();

    bool is_empty() const;
    unsigned int size() const;
    T& get(int index) const;
    unsigned int capacity() const;

    int index_of(const T& element) const;
    void insert();
    void erase();

    operator << (std::ostream &os) const;
};