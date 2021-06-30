#pragma once

template <class T>
class Stack
{
public:
    virtual T top() = 0;
    virtual void pop() = 0;
    virtual void push(const T& data) = 0;
    virtual void clear() = 0;
    virtual bool empty() const = 0;
};
