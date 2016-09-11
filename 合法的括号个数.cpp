#include <iostream>
#include <string>
#include <vector>
using namespace std;


void core(vector<string>& res, string& one_solution, int left, int right)
{
    if(left < 0 || right < left)
        return;
    if(left == 0 && right == 0)
    {
        res.push_back(one_solution);
        return;
    }
    
    if(left > 0)
    {
        one_solution.push_back('(');
        core(res, one_solution, left - 1, right);
        one_solution.pop_back();
    }
    
    if(right > left)
    {
        one_solution.push_back(')');
        core(res, one_solution, left, right - 1);
        one_solution.pop_back();
    }
}



vector<string> get_patterns(int n)
{
    vector<string> res;
    string one_solution;
    core(res, one_solution, n, n);
    return res;
}

int main()
{
    vector<string> res;
    res = get_patterns(3);
    for(auto s: res)
    {
        cout << s << endl;
    }
    
    return 0;
}