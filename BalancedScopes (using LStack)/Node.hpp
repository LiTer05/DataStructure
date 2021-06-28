#pragma once

template <class T>
class Node
{
public:
    Node(const T& d, Node<T>* n = nullptr)
        : data(d)
        , next(n)
    {}

    T data;
    Node<T>* next;
};
