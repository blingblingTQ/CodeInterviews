#include <iostream>

void swap(int *nums, int a, int b)
{
    int tmp = nums[a];
    nums[a] = nums[b];
    nums[b] = tmp;
}

/***********************************************************
 * 1. 选择排序
 * (1)运行时间和输入无关
 * (2)数据移动最少
 ***********************************************************/
void select_sort(int *nums, int length)
{
    for(int i = 0; i < length; i++)
    {
        int min = i;
        /* 从后面找到最小的数，与当前的数交换 */
        for(int j = i+1; j < length; j++)
        {
            if(nums[j] < nums[min])
            {
                min = j;
            }
        }
        swap(nums, i, min);
    }
}


/***********************************************************
 * 2. 插入排序
 * 插入排序需要交换的次数和数据中倒置的数量相同
 * 适合于部分有序数组或者小规模数组
 ***********************************************************/
void insert_sort(int *nums, int length)
{
    for(int i = 1; i < length; i++)
    {
        /* 每来一个数，从后往前插入到合适的位置 */
        for(int j = i; j > 0 && nums[j] < nums[j-1]; j--)
        {
            swap(nums, j, j-1);
        }
    }
}


/***********************************************************
 * 3. 冒泡排序
 ***********************************************************/
void bubble_sort(int *nums, int length)
{
    for(int i = 0; i < length; i++)
    {
        for(int j = 0; j < length-i-1; j++)
        {
            if(nums[j] > nums[j+1])
            {
                swap(nums, j, j+1);
            }
        }
    }
}

/***********************************************************
 * 4. 希尔排序
 * 它是针对插入排序对于大规模的数据排序很慢的改进，它适用于大型数组
 ***********************************************************/
void shell_sort(int *nums, int length)
{
    int h = 1;
    while(h < length/3)
        h = 3*h+1;    //1, 4, 13, 40, 121, 364...
    while(h >= 1)
    {
        //将数组变成h有序
        for(int i = h; i < length; i++)
        {
            for(int j = i; j >= h && nums[j] < nums[j-h]; j -= h)
            {
                swap(nums, j, j-h);
            }
        }
        h = h/3;
    }
}


/***********************************************************
 * 5. 归并排序
 * 改进方法：
 *（1）对于小规模数组使用插入排序
 *（2）测试数组是否已经有序：如果nums[mid]小于等于nums[mid+1]，则
      认为数组已经有序，并可以跳过merge()
 *（3）不将元素复制到数组
 ***********************************************************/
void merge(int *nums, int length, int lo, int mid, int hi)
{   //将nums[lo...mid]和nums[mid+1...hi]归并
    int i = lo, j = mid+1;
    int aux[length];  //归并使用的辅助数组
    for(int k = lo; k <= hi; k++)
    {
        aux[k] = nums[k];
    }

    for(int k = lo; k <= hi; k++)
    {
        if(i > mid)
            nums[k] = aux[j++];
        else if(j > hi)
            nums[k] = aux[i++];
        else if(aux[j] < aux[i])
            nums[k] = aux[j++];
        else
            nums[k] = aux[i++];
    }
}

void sort_helper(int *nums, int length, int lo, int hi)
{
    if(hi <= lo)
        return;
    int mid = lo + (hi-lo)/2;
    sort_helper(nums, length, lo, mid);     //将左半边排序
    sort_helper(nums, length, mid+1, hi);   //将右半边排序
    merge(nums, length, lo, mid, hi);       //归并结果
}

void merge_sort(int *nums, int length)
{
    sort_helper(nums, length, 0, length-1);
}



/***********************************************************
 * 6. 快速排序
 * 改进方法：
 *（1）对于小规模数组使用插入排序
 *（2）三取样切分：使用子数组的一小部分元素的中位数来切分数组
 *（3）三向切分
 *（4）排序前先随机打乱数组
 ***********************************************************/
int partition(int *nums, int lo, int hi)
{   //将数组切分成nums[lo...i-1], nums[i], nums[i+1...hi]
    int i = lo, j = hi+1;  //左右扫描指针
    int guard = nums[lo];  //切分元素
    while(true)
    {
        while(nums[++i] < guard)
        {
            if(i == hi)
                break;
        }
        while(guard < nums[--j])
        {
            if(j == lo)
                break;
        }
        if(i >= j)
            break;
        swap(nums, i, j);
    }
    swap(nums, lo, j);
    return j;
}

void quick_sort_helper(int *nums, int lo, int hi)
{
    if(hi <= lo)
        return;
    int j = partition(nums, lo, hi);
    quick_sort_helper(nums, lo, j-1);
    quick_sort_helper(nums, j+1, hi);
}

void quick_sort(int *nums, int length)
{
    quick_sort_helper(nums, 0, length-1);
}