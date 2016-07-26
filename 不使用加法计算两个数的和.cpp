#include <iostream>

int add(int a, int b)
{
    if(b == 0)
        return a;
    int sum = a ^ b;  //相加不进位
    int carry = (a & b) << 1; //进位，不相加
    return add(sum, carry);
}