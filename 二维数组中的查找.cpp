#include <iostream>

bool find(int *matrix, int rows, int columns, int number)
{
    if(matrix == NULL || rows <= 0 || columns <= 0)
        return false;

    /* 从右上角开始搜索 */
    int row = 0, column = columns - 1;
    while(row < rows && column >= 0)
    {
        if(matrix[row*columns + column] == number)
        {
            /* 找到 */
            return true;
        }
        else if(matrix[row*columns + column] > number)
        {
            column --;
        }
        else
        {
            row ++;
        }
    }
    return false;
}
