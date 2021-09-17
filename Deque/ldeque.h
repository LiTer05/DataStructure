#pragma once

#include <assert.h>

#include "node.h"
#include "deque.h"

template <typename T>
class LDeque: public Deque<T>
{
public:
    LDeque();
    ~LDeque();

    virtual void pop_front();
    virtual void pop_back();
    virtual void push_front(const T&);
    virtual void push_back(const T&);
    virtual void erase();
    
    virtual const T& front() const;
    virtual const T& back() const;
    virtual bool empty() const;
    virtual int size() const;

private:
    Node<T>* m_rear;
    Node<T>* m_front;
    int m_size;
};

template <typename T>
LDeque<T>::LDeque()
    : m_rear(nullptr)
    , m_front(nullptr)
    , m_size(0)
{}

template <typename T>
LDeque<T>::~LDeque()
{
    erase();
}

template <typename T>
void LDeque<T>::pop_front()
{
    assert(!empty());

    if (m_front == m_rear)
    {
        delete m_front;
        m_front = m_rear = nullptr;
    }
    else
    {
        m_front = m_front->prev;
        delete m_front->next;
        m_front->next = nullptr;
    }
    --m_size;

}
template <typename T>
void LDeque<T>::pop_back()
{
    assert(!empty());
    
    if (m_front == m_rear)
    {
        delete m_front;
        m_front = m_rear = nullptr;
    }
    else
    {
        m_rear = m_rear->next;
        delete m_rear->prev;
        m_rear->prev = nullptr;
    }
    --m_size;
}

template <typename T>
void LDeque<T>::push_front(const T& data)
{
    Node<T>* tmp = new Node<T>(data);
    if(empty())
    {
        m_front = tmp;
        m_rear = tmp;
    }
    else
    {
        m_front->next = tmp;
        tmp->prev = m_front;
        m_front = tmp;
    }
    ++m_size;
}

template <typename T>
void LDeque<T>::push_back(const T& data)
{
    Node<T>* tmp = new Node<T>(data);
    if(empty())
    {
        m_front = tmp;
        m_rear = tmp;
    }
    else
    {
        m_rear->prev = tmp;
        tmp->next = m_front;
        m_rear = tmp;
    }
    ++m_size;
}

template <typename T>
const T& LDeque<T>::front() const
{
    assert(!empty());
    return m_front->data;
}

template <typename T>
const T& LDeque<T>::back() const
{
    assert(!empty());
    return m_rear->data;
}

template <typename T>
bool LDeque<T>::empty() const
{
    return m_front == nullptr;
}

template <typename T>
int LDeque<T>::size() const
{
    return m_size;
}

template <typename T>
void LDeque<T>::erase()
{
    while(!empty())
    {
        pop_front();
    }
}





