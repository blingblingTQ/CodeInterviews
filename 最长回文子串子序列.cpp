#include <iostream>
#include <string>

using namespace std;

/*
 * 1、最长回文子序列
 * 2、翻转字符串，求最长公共子序列LCS
 */
int lps(string str)
{
    size_t length = str.size();
    int dp[length][length];
    memset(dp, 0, sizeof(dp));

    for(int i = 0; i < length; i++)
    {
        dp[i][i] = 1;
    }

    for(int i = 1; i < length; i++)
    {
        //对于每个长度为i+1的子串, 该字符串为str[j, j+i];
        for(int j = 0; j + i < length; j++)
        {
            if(str[j] == str[j + i])
            {
                dp[j][j + i] = dp[j + 1][j + i - 1] + 2; 
            }
            else
            {
                dp[j][j + i] = max(dp[j + 1][j + i], dp[j][j + i - 1]);
            }
        }
    }
    return dp[0][length-1];
}

/*
 * 2、最长回文子串
 * （1）暴力
 * （2）中心扩展
 * （3）DP
 * （4）Manacher算法
 */

bool is_palindrome(string str, int start, int end)
{
    while(start < end)
    {
        if(str[start] != str[end])
            return false;
        start ++;
        end --;
    }
    return true;
}

//暴力法 O(n^3)
int lpsub_str_bf(string str)
{
    int length = str.size();
    if(length == 0)
        return 0;
    int max_length = 1; //每个字符都是一个回文串
    for(int i = 2; i < length; i++)
    {
        //对于每个起始位置为j, 长度为i的子串
        for(int j = 0; j + i - 1 < length; j++)
        {
            if(is_palindrome(str, j, j + i - 1))
            {
                max_length = max(max_length, i);
            }
        }
    }
    return max_length;
}



int expand_around_center(string s, int c1, int c2)
{
    int l = c1, r = c2;
    int n = s.size();
    while(l >= 0 && r <= n - 1 && s[l] == s[r])
    {
        l --;
        r ++;
    }
    return r - l - 1;
}

//中心扩展法 时间复杂度O(n^2)，空间复杂度O(1)
int lpsub_str_middle_expand(string str)
{
    int length = str.size();
    if(length == 0)
        return 0;
    int max_length = 1;
    for(int i = 0; i < length - 1; i++)
    {
        int len1 = expand_around_center(str, i, i);
        int len2 = expand_around_center(str, i, i+1);
        max_length = max(max_length, max(len1, len2));
    }
    return max_length;
}


//动态规划法
//时间复杂度为O(n^2)，空间复杂度为O(n^2)
int lpsub_str_dp(string str)
{
    int length = str.size();
    if(length == 0)
        return 0;
    
    int dp[length][length];  //dp[i][j]表示子串(i,j)是否是一个回文串
    memset(dp, 0, sizeof(dp));
    int max_length = 1;

    //每个字符都是一个回文串
    for(int i = 0; i < length; i++)
    {
        dp[i][i] = 1;
    }

    //相邻的字符如果相同，则是一个回文子串，长度为2
    for(int i = 0; i < length - 1; i++)
    {
        if(str[i] == str[i + 1])
        {
            dp[i][i + 1] = 1;
            max_length = 2;
        }
    }

    for(int len = 3; len < length; len ++)
    {//每个长度的子串
        for(int i = 0; i < length - len + 1; i++)
        {
            int j = i + len - 1;
            if(str[i] == str[j] && dp[i + 1][j - 1])
            {
                dp[i][j] = 1;
                max_length = len;
            }
        }
    }
    return max_length;
}

