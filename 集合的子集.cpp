#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums)
    {
        vector<vector<int> > result;
        vector<int> one_solution;
        subsets(result, nums, one_solution, 0);
        return result;
    }
private:
    void subsets(vector<vector<int> >& result, vector<int>& nums, vector<int>& one_solution, int index)
    {
        if(index == nums.size())
        {
            result.push_back(one_solution);
            return;
        }
        subsets(result, nums, one_solution, index + 1); //不选
        one_solution.push_back(nums[index]);
        subsets(result, nums, one_solution, index + 1); //选
        one_solution.pop_back();
        return;
    }
};