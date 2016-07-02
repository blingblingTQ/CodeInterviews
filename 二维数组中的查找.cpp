#include <iostream>

/* 解法一：
 * M行N列的矩阵，对每一行进行二分查找，平均时间复杂度是O(Mlog(N))
 **/

/* 解法二：
 * 采用二分查找法，每个子矩阵中，左上角最小，右下角最大。
 * 按照对角线的顺序进行二分搜索
 * 参考《程序员面试金典》P260
 */

/* 解法三：
 * 从右上角开始搜索
 */
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
