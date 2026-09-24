#include <iostream>

int foo(int a)
{
    return (a + 1) > a;
}

int main()
{
    int a;
    std::cout << (a + !a);
    return 0;
}