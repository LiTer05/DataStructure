#include <iostream>
#include <string>
#include <cmath>

#include "L_Stack.hpp"

bool isOperand(const char& c)
{
    return (c >= '0' && c <= '9');
}

void getOperands(int& tmp1, int& tmp2, LStack<int>& st)
{
    tmp1 = st.top();
    st.pop();
    tmp2 = st.top();
    st.pop();
}

void evaluate(int& op1, int& op2, char& op, LStack<int>& st)
{
    switch (op)
    {
        case '+':
            st.push(op2 + op1);
            break;
        case '-':
            st.push(op2 - op1);
            break;
        case '*':
            st.push(op2 * op1);
            break;
        case '/':
            st.push(op2 / op1);
            break;
        case '^':
            st.push(pow(op2,op1));
            break;
    }
}

int main()
{
    std::string postfix;
    std::cout << "Postfix: ";
    std::cin >> postfix;

    LStack<int> st;

    for (int i = 0; i < postfix.size(); ++i)
    {
        if (isOperand(postfix[i]))
        {
            st.push(postfix[i] - '0');
        }        
        else 
        {
            int tmp1, tmp2;
            getOperands(tmp1, tmp2, st);
            evaluate(tmp1, tmp2, postfix[i], st);
        }
    }
    
    int result = st.top();
    st.pop();

    if (!st.empty())
    {
        std::cerr << "Error Input" << std::endl;
        return 0;
    }

    std::cout << "Result: " << result << std::endl;
    return 0;
}

