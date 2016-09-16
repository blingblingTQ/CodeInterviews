#include <iostream>
#include <string>
#include <vector>
using namespace std;


void printCore(vector<vector<string>>& result, int n, vector<string>& one_solution, int curr_index, string pre1, string pre2)
{
    if(curr_index == n)
    {
        result.push_back(one_solution);
        return;
    }
    
    if(pre1 == pre2 && pre1 == "红")
    {
        one_solution.push_back("黑");
        printCore(result, n, one_solution, curr_index + 1, "红", "黑");
        one_solution.pop_back();
    }
    else if(pre1 == pre2 && pre1 == "黑")
    {
        one_solution.push_back("红");
        printCore(result, n, one_solution, curr_index + 1, "黑", "红");
        one_solution.pop_back();
    }
    else
    {
        one_solution.push_back("红");
        printCore(result, n, one_solution, curr_index + 1, pre2, "红");
        one_solution.pop_back();
        one_solution.push_back("黑");
        printCore(result, n, one_solution, curr_index + 1, pre2, "黑");
        one_solution.pop_back();
    }
}

vector<vector<string>> print(int n)
{
    vector<string> one_solution;
    vector<vector<string>> result;
    printCore(result, n, one_solution, 0, "", "");
    return result;
}


int main()
{
    vector<vector<string>> result = print(10);
    for(auto v: result)
    {
        for(auto s: v)
        {
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}



