#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
    int value;
    ListNode *next;
};

/* 迭代倒序打印链表 */
void print_list_reversingly_iteratively(ListNode *head)
{
    if(head == NULL)
        return;
    stack<ListNode *> nodes;
    ListNode *pnode = head;
    while(pnode != NULL)
    {
        nodes.push(pnode);
        pnode = pnode->next;
    }
    while(!nodes.empty())
    {
        pnode = nodes.top();
        cout << pnode->value << endl;
        nodes.pop();
    }
}

/* 递归倒序打印链表 */
void print_list_reversingly_recursively(ListNode *head)
{
    if(head == NULL)
        return;
    /* 先输出后一个节点 */
    print_list_reversingly_iteratively(head->next);
    cout << head->value << endl;
}