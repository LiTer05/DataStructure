#include <iostream>
#include <iomanip>

#include "ldeque.h"

int main()
{
    LDeque<int> ldeq;

    std::cout << "1. pop_front\n2. pop_back\n3. push_front\n4. push_back\n5. empty\n6. size\n7. erase\n8. front\n9. back\n";

    int n;
    do
    {
        std::cout << "Enter number: ";
        std::cin >> n;

        switch(n)
        {
            case 1:
                {   
                    if (ldeq.empty())
                    {
                        std::cout << "Can't remove!";
                    }
                    else
                    {
                        ldeq.pop_front(); 
                    }
                    break;
                }
            case 2:
                {
                    if (ldeq.empty())
                    {
                        std::cout << "Can't remove!";
                    }
                    else
                    {
                        ldeq.pop_back(); 
                    }
                    break;
                }
            case 3: 
                {
                    int d;
                    std::cin >> d;
                    ldeq.push_front(d);
                    break;
                }
            case 4: 
                {
                    int d;
                    std::cin >> d;
                    ldeq.push_back(d);
                    break;
                }
            case 5:
                {
                    std::cout << "Empty: "
                              << std::boolalpha 
                              << ldeq.empty()
                              << std::endl;
                    break;
                }
            case 6: 
                {
                    std::cout << "Size: "
                              << ldeq.size()
                              << std::endl;
                    break;
                }
            case 7: 
                {
                    std::cout << "Erase Deque!" 
                              << std::endl;
                    ldeq.erase();
                    break;
                }
            case 8:
                {
                    if (ldeq.empty())
                    {
                        std::cout << "Deque is Empty!" << std::endl;
                    }
                    else
                    {
                        std::cout << ldeq.front() << std::endl; 
                    }
                    break;
                }
            case 9:
                {
                    if (ldeq.empty())
                    {
                        std::cout << "Deque is Empty!" << std::endl;
                    }
                    else
                    {
                        std::cout << ldeq.back() << std::endl; 
                    }
                    break;
                }

        }
    }
    while (n > 0 && n < 10);

    return 0;
}
