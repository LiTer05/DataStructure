#pragma once

template <typename T>
struct Node
{
    Node(const T& d, Node<T>* p = nullptr, Node<T>* n = nullptr)
        : data(d)
        , prev(p)
        , next(n)
    {}

    T data;
    Node<T>* prev;
    Node<T>* next; 
}; 
