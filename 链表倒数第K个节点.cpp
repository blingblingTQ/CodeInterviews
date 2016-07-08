#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
};


/*
 * 重点注意代码的鲁棒性
 */
ListNode *find_kth_to_tail(ListNode *head, int k)
{
    if(head == NULL || k <= 0)
        return NULL;
    
    ListNode *first = head;
    ListNode *second = head;
    for(int i = 0; i < k - 1; i++)
    {
        if(first->next != NULL)
        {
            first = first->next;
        }
        else
        {
            return NULL;
        }
    }

    while(first->next != NULL)
    {
        first = first->next;
        second = second->next;
    }
    return second;
}