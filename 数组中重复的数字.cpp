#include <iostream>
#include <vector>

using namespace std;

int duplicate_number(vector<int>& nums)
{
    int size = nums.size();
    if(size == 0)
        return -1;
    int duplicate = -1; //error
    for(int i = 0; i < size; i++)
    {
        while(nums[i] != i)
        {
            if(nums[i] == nums[nums[i]])
            {
                return nums[i];
            }

            int tmp = nums[i];
            nums[i] = nums[tmp];
            nums[tmp] = tmp;
        }
    }
    return duplicate;
}