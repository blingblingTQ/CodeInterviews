#include <iostream>

using namespace std;


/*
 *  注意！！！！
 *  这种写法可能会出现死循环，因为右移最高位补符号位
 */
int numberof1_wrong(int n)
{
    int count = 0;
    while(n)
    {
        if(n & 1)
            count ++;
        n >>= 1;
    }
    return count;
}


/*
 * 一般的思路
 */
int numberof1_correct(int n)
{
    int count = 0;
    int mask = 1;
    while(mask)
    {
        if(n & mask)
            count ++;
        mask <<= 1;
    }
    return count;
}


/*
 * 较好的思路
 * n&(n-1) 将n的最右边的一个1置0
 */
int numberof1_surprise(int n)
{
    int count = 0;
    while(n)
    {
        count ++;
        n = n & (n-1);
    }
    return count;
}