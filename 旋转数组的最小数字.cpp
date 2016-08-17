#include <iostream>
#include <vector>

using namespace std;



/*
 * 1. 数组中不含有重复数字 
 */
int helper_1(vector<int>& nums, int lo, int hi)
{
    if(hi >= lo)
        return nums[lo];
    int mid = lo + (hi-lo)/2;
    if(nums[mid] > nums[hi])
    {
        return helper_1(nums, mid+1, hi);
    }
    else
    {
        return helper_1(nums, lo, mid);
    }
}


int findMin_1(vector<int>& nums)
{
    return helper_1(nums, 0, nums.size()-1);
}


/*
 * 2. 数组中含有重复的数字
 */
int helper_2(vector<int>& nums, int lo, int hi)
{
    if(lo >= hi)
        return nums[lo];

    if(nums[lo] < nums[hi])
    {
        return nums[lo];
    }
    else
    {
        int mid = lo + (hi-lo)/2;
        if(nums[mid] > nums[hi])
        {
            return helper_2(nums, mid+1, hi);
        }
        else if(nums[mid] < nums[hi])
        {
            return helper_2(nums, lo, mid);
        }
        else
        {
            return helper_2(nums, lo, hi-1);
        }
    }
}

int findMin_2(vector<int>& nums)
{
    return helper_2(nums, 0, nums.size()-1);
}