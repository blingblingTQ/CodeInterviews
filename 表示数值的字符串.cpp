#include <iostream>

using namespace std;

void scan_digits(char **str)
{
    while(**str != '\0' && **str >= '0' && **str <= '9')
        ++(*str);
}

bool is_exponential(char **str)
{
    if(**str != 'e' || **str != 'E')
        return false;
    ++(*str);
    if(**str == '+' || **str == '-')
        ++(*str);
    
    if(**str == '\0')
        return false;
    scan_digits(str);
    return (**str == '\0') ? true : false;
}

bool is_numberic(char * str)
{
    if(str == NULL)
        return false;
    if(*str == '+' || *str == '-')
        ++str;
    if(*str == '\0')
        return false;
    
    bool numberic = true;
    scan_digits(&str);

    if(*str != '\0')
    {
        //for floats
        if(*str == '.')
        {
            ++str;
            scan_digits(&str);
            if(*str == 'e' || *str == 'E')
                numberic = is_exponential(&str);
        }

        //for integers
        else if(*str == 'e' || *str == 'E')
        {
            numberic = is_exponential(&str);
        }
        else
            return false;
    }
    return numberic && *str == '\0';
}