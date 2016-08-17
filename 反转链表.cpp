#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
};

ListNode *reverse_list(ListNode *head)
{
    ListNode *curr = head;
    ListNode *prev = NULL;

    while(curr)
    {
        ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next; 
    }
    return prev;
}

ListNode *reverse_list_recursive(ListNode *head)
{
    if(head == NULL || head->next == NULL)
        return head;
    ListNode *new_head = reverse_list_recursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return new_head;
}