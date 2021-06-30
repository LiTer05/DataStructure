#include <iostream>
#include <string>
#include <cctype>
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
    std::getline (std::cin, postfix);

    LStack<int> st;

    int i = 0; 
    while (i < postfix.size())
    {
        while (postfix[i] == ' ') 
        {
            i++;
        }

        if (isOperand(postfix[i]))
        {
            int num = 0;
            while (isOperand(postfix[i]))
            {
                num = 10*num + (postfix[i] - '0');
                i++;
            }
            st.push(num);
        }        
        else 
        {
            int tmp1, tmp2;
            getOperands(tmp1, tmp2, st);
            evaluate(tmp1, tmp2, postfix[i], st);
            i++;
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
