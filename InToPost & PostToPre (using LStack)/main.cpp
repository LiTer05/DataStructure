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

void InToPre(std::string& infix, std::string& postfix)
{
    LStack<char> st;

    for (int i = 0; i < infix.size(); ++i)
    {
        if (isOperand(infix[i]))
        {
            postfix.push_back(infix[i]);
        }        
        else if (isOperation(infix[i]))
        {
            while (!st.empty() && (isOperation(st.top())) && (priority(infix[i]) <= priority(st.top())))           
            {
                postfix.push_back(st.top());
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
                postfix.push_back(st.top());
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
        postfix.push_back(st.top());
        st.pop();
    }
}

void PostToPre(std::string& postfix, std::string& prefix)
{
    LStack<char> st;

    for(int i = 0; i < postfix.size(); ++i)
    {
        st.push(postfix[i]);
    }

    while(!st.empty())
    {
        prefix.push_back(st.top());
        st.pop();
    }
}

int main()
{
    std::string infix;
    std::cout << "Infix: ";
    std::cin >> infix;
    
    std::string postfix;
    InToPre(infix, postfix);
    std::cout << "Postfix: " << postfix << std::endl;

    std::string prefix;
    PostToPre(postfix, prefix);
    std::cout << "Prefix: " << prefix << std::endl;
}
