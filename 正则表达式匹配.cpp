#include <iostream>
#include <string>

using namespace std;

bool match_core(char *str, char *pattern)
{
    if(*str == '\0' && *pattern == '\0')
        return true;
    if(*str != '\0' && *pattern == '\0')
        return false;
    
    if(*(pattern + 1) == '*')
    {
        if(*pattern == *str || (*pattern == '.' && *str != '\0'))
            return match_core(str + 1, pattern + 2) //move on next state
                || match_core(str + 1, pattern)     //stay on current state
                || match_core(str, pattern + 2);    //ignore a '*'
        else
            return match_core(str, pattern + 2);
    }

    if(*str == *pattern || (*pattern == '.' && *str != '\0'))
        return match_core(str + 1, pattern + 1);
}

bool match(char *str, char *pattern)
{
    if(str == NULL || pattern == NULL)
    {
        return false;
    }
    return match_core(str, pattern);
}

