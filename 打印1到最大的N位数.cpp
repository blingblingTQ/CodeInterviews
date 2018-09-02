#include <iostream>
#include <string.h>

using namespace std;

void print_number(char *number)
{
    bool is_beginning0 = true;
    size_t length = strlen(number);
    for(auto i = 0; i < length; i++)
    {
        if(is_beginning0 && number[i] != '0')
        {
            is_beginning0 = false;
        }
        
        if(!is_beginning0)
        {
            printf("%c", number[i]);
        }
    }
    printf("\n");
}

void print_1_to_max_of_n_digits_recurisively(char *number, int length, int index)
{
    if(index == length)
    {
        print_number(number);
        return;
    }
    for(int i = 0; i < 10; i++)
    {
        number[index] = i + '0';
        print_1_to_max_of_n_digits_recurisively(number, length, index + 1);
    }
}

void print_1_to_max_of_n_digits(int n)
{
    if(n <= 0)
        return;
    char *number = new char[n+1];
    number[n] = '\0';
    print_1_to_max_of_n_digits_recurisively(number, n, 0);
    delete[] number;
}

int main(void)
{
    print_1_to_max_of_n_digits(3);
    return 0;
}
