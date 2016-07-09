#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
};


/*
 * 方法一：迭代写法
 **/
ListNode * merge_sorted_list_iteratively(ListNode *l1, ListNode *l2)
{
    if(l1 == NULL)
        return l2;
    if(l2 == NULL)
        return l2;
    
    ListNode *head = NULL, *curr = NULL;
    if(l1->val < l2->val)
    {
        head = l1;
    }
    else
    {
        head = l2;
    }

    curr = head;
    while(l1 != NULL && l2 != NULL)
    {
        if(l1->val < l2->val)
        {
            curr->next = l1;
            curr = l1;
            l1 = l1->next;
        }
        else
        {
            curr->next = l2;
            curr = l2;
            l2 = l2->next;
        }
    }
    if(l1 != NULL)
    {
        curr->next = l1;
    }
    if(l2 != NULL)
    {
        curr->next = l2;
    }
    return head;
}

/*
 * 递归解法
 **/
ListNode *merge_sorted_list_recurisively(ListNode *l1, ListNode *l2)
{
    if(l1 == NULL)
        return l2;
    if(l2 == NULL)
        return l1;
    if(l1->val < l2->val)
    {
        l1->next = merge_sorted_list_recurisively(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = merge_sorted_list_recurisively(l1, l2->next);
        return l2;
    }
}