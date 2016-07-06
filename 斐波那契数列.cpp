#include <iostream>

using namespace std;

/*
 * 递归写法，效率低下
 * 1, 1, 2, 3, 5, 8...
 */
long long fibonacci_recursively(unsigned int n)
{
    if(n <= 0)
        return 0;
    if(n == 1)
        return 1;
    return fibonacci_recursively(n-1) + fibonacci_recursively(n-2);
}

/*
 * 迭代写法，效率较高
 * 1, 1, 2, 3, 5, 8...
 */
long long fibonacci_iteratively(unsigned int n)
{
    if(n <= 0)
        return 0;
    if(n == 1)
        return 1;

    long long pre1 = 0;
    long long pre2 = 1;
    long long sum;
    for(unsigned int i = 2; i <= n; i++)
    {
        sum  = pre1 + pre2;
        pre1 = pre2;
        pre2 = sum;
    }
    return sum;
}
