#pragma once

template <typename T>
class Deque
{
public:
    virtual void pop_front() = 0;
    virtual void pop_back() = 0;
    virtual void push_front(const T&) = 0;
    virtual void push_back(const T&) = 0;
    virtual void erase() = 0;

    virtual const T& front() const = 0;
    virtual const T& back() const = 0;
    virtual bool empty() const = 0;
    virtual int size() const = 0;
};
