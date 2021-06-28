#include <iostream>
#include <string>

#include "L_Stack.hpp"

bool isOpeningScope(const char& c)
{
    return (c == '(' || c == '{' || c == '[');
}

bool isClosingScope(const char& c)
{
    return (c == ')' || c == '}' || c == ']');
}

int priority(const char& c)
{
    switch (c)
    {
        case '(':
        case ')': 
            return 1;
        case '{': 
        case '}':
            return 2;
        case '[':
        case ']':
            return 3;
        default:
            return 4;
    }
}
    
void balancedScopes(std::string& expr)
{
    LStack<char> st;

    for (int i = 0; i < expr.size(); ++i)
    {
        if (isOpeningScope(expr[i]))
        {
            st.push(expr[i]);
        }
        else if (isClosingScope(expr[i]))
        {
            if (priority(st.top()) == priority(expr[i]))
            {
                st.pop();
            }
        }
    }

    std::cout << "Has the expression balanced scopes?" << std::endl;
    std::string str = st.empty()? "Yes" :"No"; 
    std::cout << str << std::endl;
}

int main()
{
    std::string expr;
    std::cout << "Scope Expression: ";
    std::cin >> expr;
    
    balancedScopes(expr);

    return 0;
}
