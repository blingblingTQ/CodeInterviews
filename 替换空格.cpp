#include <iostream>

/* 解法一：
 * 从头到尾遍历，遇到空格，将空格后面的字符依次后移，然后插入"%20"
 * 时间复杂度为O(N^2)
 */


/* 解法二：
 * 先计算最终长度，从尾部遍历，这样可以省去移动字符串的开销
 * 时间复杂度为O(N)
 */
//length 为字符数组string的总容量
void replace_blank(char string[], int length)
{
    if(string == NULL || length <= 0)
        return;
    
    /* 根据字符串原长度，计算变化后的长度 */
    int original_length = 0, blank_num = 0, new_length = 0;
    char *str = string;
    while(*str != '\0')
    {
        original_length ++;
        if(*str == ' ')
        {
            blank_num ++;
        }
    }
    new_length = original_length + 2 * blank_num;
    /* 超出容量 */
    if(new_length > length)
        return;
    
    int index_original = original_length;
    int index_new = new_length;
    while(index_original >= 0 && index_new > index_original)
    {
        if(string[index_original] == ' ')
        {
            string[index_new --] = '0';
            string[index_new --] = '2';
            string[index_new --] = '%';
        }
        else
        {
            string[index_new --] = string[index_original];
        }
        index_original --;
    }
}