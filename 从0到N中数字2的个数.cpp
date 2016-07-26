#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <math.h>

using namespace std;

//n = 61523, d = 3 ==> digit = 1
int count2sinrangeatdigit(int n, int d)
{
    int powerof10 = (int)pow(10, d); // 1000
    int nextpowerof10 = powerof10 * 10;  //10000
    int right = n % powerof10;           //  523
    
    int rounddown = n - n % nextpowerof10;   //61523 - 61523 % 10000 = 60000
    int roundup = rounddown + nextpowerof10; //60000 + 10000 = 70000
    
    int digit = (n / powerof10) % 10;  //1
    if(digit < 2)
    {
        return rounddown / 10;
    }
    else if (digit == 2)
    {
        return rounddown / 10 + right + 1;
    }
    else
    {
        return roundup / 10;
    }
}

int count2sinrange(int n)
{
    int count = 0;
    size_t len;
    stringstream ss;
    string str;
    
    ss << n;
    str = ss.str();
    len = str.size();
    
    for(int digit = 0; digit < len; digit ++)
    {
        count += count2sinrangeatdigit(n, digit);
    }
    return count;
}

int main(void)
{
    cout << count2sinrange(61523) << endl;
    return 0;
}