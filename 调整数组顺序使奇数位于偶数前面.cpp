#include <iostream>
using namespace std;

void swap(int *nums, int a, int b)
{
    int tmp = nums[a];
    nums[a] = nums[b];
    nums[b] = tmp;
}


/*
 * 解法：首尾相向遍历，遇到前面是偶数后面是奇数则交换
 * 这个框架是一个统一的模式，只需修改前后数字的判断函数即可
 */
void reorder_odd_even(int *nums, int length)
{
    int start = 0, end = length - 1;
    while(start < end)
    {//类似于快排的写法
        while(start < end && (nums[start] & 0x01) != 0)
            start ++;
        while(start < end && (nums[end] & 0x01) == 0)
            end --;
        swap(nums, start, end);
    }
}