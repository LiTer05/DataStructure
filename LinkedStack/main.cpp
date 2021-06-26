#include <iostream>

#include "L_Stack.hpp"

int main()
{
    LStack<int> st;
    st.push(3);
    st.push(7);
    st.push(9);
    st.push(1);

    while(!st.empty())
    {
        std::cout << st.top() << " ";
        st.pop();
    }
    std::cout << std::endl;
}

