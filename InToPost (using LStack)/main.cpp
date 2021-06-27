#include <iostream>
#include <string>

#include "L_Stack.hpp"

bool isOperand(const char& c)
{
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
}

bool isOperation(const char& c)
{
    switch (c)
    {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            return true;
        default:
            return false;
    }
}

int priority(const char& c)
{
    switch (c)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            assert(false);
            return -1;
    }
}

int main()
{
    std::string infix;
    std::cin >> infix;

    LStack<char> st;

    for (int i = 0; i < infix.size(); ++i)
    {
        if (isOperand(infix[i]))
        {
            std::cout << infix[i];
        }        
        else if (isOperation(infix[i]))
        {
            while (!st.empty() && (isOperation(st.top())) && (priority(infix[i]) <= priority(st.top())))           
            {
                std::cout << st.top();
                st.pop();
            }
            st.push(infix[i]);
        }
        else if (infix[i] == '(')
        {
            st.push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                std::cout << st.top();
                st.pop();
            }
            if (!st.empty())
            {
                st.pop();
            }
        }
    }
    while (!st.empty())
    {
        std::cout << st.top();
        st.pop();
    }
    std::cout << std::endl;
}

