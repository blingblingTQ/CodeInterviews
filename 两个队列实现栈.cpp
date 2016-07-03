#include <iostream>
#include <queue>

using namespace std;

class Solution{
private:
    queue<int> q1, q2;
public:

    /* 注意：两个队列永远有一个有数据，另一个是空的 */

    void push(int x)
    {
        if(!q1.empty())
        {
            q1.push(x);
        }
        else
        {
            q2.push(x);
        }
    }

    void pop()
    {
        int val;
        if(!q1.empty())
        {
            int size = q1.size();
            for(int i = 1; i < size; i++)
            {
                q2.push(q1.front());
                q1.pop();
            }
            //last number to be poped
            q1.pop();
        }
        else
        {
            int size = q2.size();
            for(int i = 1; i < size; i++)
            {
                q1.push(q2.front());
                q2.pop();
            }
            //last number to be poped
            q2.pop();
        }
    }
};