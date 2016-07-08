#include <iostream>

using namespace std;

struct ListNode {
    int value;
    ListNode *next;
};

void delete_node(ListNode **head, ListNode *deleted)
{
    if(head == NULL || deleted == NULL)
        return;
    
    if(deleted->next != NULL)
    {//要删除的节点不是尾节点
        ListNode *next = deleted->next;
        deleted->value = next->value;
        deleted->next = next->next;

        delete next;
        next = NULL;
    }
    else if(*head == deleted)
    {//链表只有一个节点，删除头结点
        delete deleted;
        deleted = NULL;
        *head = NULL;
    }
    else
    {//链表有多个节点，删除尾节点
        ListNode *node = *head;
        while(node->next != deleted)
        {
            node = node->next;
        }
        node->next = NULL;
        delete deleted;
        deleted = NULL;
    }
}