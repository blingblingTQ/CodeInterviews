#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

//产生lo-hi(包含)的随机数
int rand(int lo, int hi)
{
    return lo + rand() % (hi - lo + 1);
}

/*
 * 完美洗牌算法
 */
void shuffle_array_interatively(vector<int>& cards)
{
    srand((int)time(0));
    for(int i = 0; i < cards.size(); i++)
    {
        int k = rand(0, i);
        int tmp = cards[k];
        cards[k] = cards[i];
        cards[i] = tmp;
    }
}

/*
 * 从大小为n的数组中随机选出m个整数
 */
vector<int> pick_m_iteratively(vector<int>& original, int m)
{
    int n = original.size();
    if(n < m)
        return vector<int>();
    vector<int> subset(m);
    srand((int)time(0));
    for(int i = 0; i < m; i++)
    {
        subset[i] = original[i];
    }

    for(int i = m; i < n; i++)
    {
        int k = rand(0, i);
        if(k < m)
        {
            subset[k] = original[i];
        }
    }
    return subset;
}

/*
 * 给定rand5(),实现rand7()
 */
int rand7()
{
    while(true)
    {
        int num = 5 * rand5() + rand5();
        if(num < 21)
            return num % 7;
    }
}