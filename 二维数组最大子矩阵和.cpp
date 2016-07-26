#include <iostream>
#include <vector>
using namespace std;

int max_subarray(vector<int>& v)
{
    int sum = 0, size = v.size();
    int max_sum = INT_MIN;
    for(int i = 0; i < size; i++)
    {
        sum += v[i];
        max_sum = max(max_sum, sum);
        if(sum < 0)
        {
            sum = 0;
        }
    }
    return max_sum;
}

void clean_array(vector<int>& array)
{
    int size = array.size();
    for(int i = 0; i < size; i++)
    {
        array[i] = 0;
    }
}

int max_sub_matrix(vector<vector<int> > matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    int max_sum = INT_MIN;

    vector<int> array(cols, 0);
    for(int row_start = 0; row_start < rows; row_start ++)
    {
        clean_array(array);
        for(int row_end = row_start; row_end < rows; row_end ++)
        {
            for(int i = 0; i < cols; i ++)
            {
                array[i] += matrix[row_end][i];
            }
            int tmpsum = max_subarray(array);
            max_sum = max(max_sum, tmpsum);
        }
    }
}