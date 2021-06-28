#pragma once

#include "Stack.hpp"
#include "Node.hpp"

#include <assert.h>

template <class T>
class LStack : public Stack<T>
{
public:
    LStack()
        : m_top(nullptr)
    {}
    
    T top() ;
    void pop();
    void push(const T& data);
    void clear();
    bool empty() const;

private:
    Node<T>* m_top;
};

template <class T>
T LStack<T>::top()
{
    assert(m_top != nullptr);
    return m_top->data;
}

template <class T>
void LStack<T>::pop()
{
    Node<T>* tmp = m_top; // new չենք արել։ ինչ ենք ջնջում
    m_top = m_top->next;
    delete tmp;
}

template <class T>
void LStack<T>::push(const T& data)
{
    m_top = new Node<T>(data, m_top); 
}

template <class T>
bool LStack<T>::empty() const
{
    return m_top == nullptr;
}

template <class T>
void LStack<T>::clear()
{
    while(!empty()){
        pop();
    }
}



