#include <iostream>
#include <stack>
using namespace std;

class Solution{
private:
    stack<int> s1, s2;
public:
    /* 入队列，总是向第一个栈入 */
    void enqueue(int x)
    {
        s1.push(x);
    }

    /* 出队列，如果s2是空，就把s1的元素全部灌入到s2中，最后总是从s2中出队列 */
    int dequeue()
    {
        if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int val = s2.top();
        s2.pop();
        return val;
    }
};