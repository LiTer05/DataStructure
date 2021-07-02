#include "L_Stack.hpp"

#include <iostream>
#include <string>

int main()
{
    std::string num;
    std::cout << "Number: ";
    std::getline (std::cin, num);

    LStack<int> st;

    int n = num.size() / 2, i = 0; 
    for (i = 0; i < n; ++i)
    {
        st.push(num[i] - '0');
    }

    if (num.size() % 2) // նիշերի քանակը կենտ ա 
    {
        i++;
    }

    while  ((i < num.size()) && (st.top() == num[i] - '0'))
    {
       st.pop();
       i++;
    }

    if (st.empty())
    {
        std::cout << num << "is palindrome." << std::endl;
    }
    else
    {
        std::cout << num << "is not palindrome." << std::endl;
    }

    return 0;
}
