#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
};

ListNode *push_start(ListNode *head, int new_val)
{
    ListNode *node = new ListNode();
    node->val = new_val;
    node->next = head;
    head = node;
    return head;
}

ListNode *reverseList(ListNode *head)
{
    ListNode *p = head;
    ListNode *head2 = NULL;
    while (p != NULL)
    {
        ListNode *node = new ListNode();
        node->val = p->val;
        node->next = head2;
        head2 = node;
        p = p->next;
    }
    head = head2;
    return head;
}

void printList(ListNode *head)
{
    ListNode *p = head;
    while (p->next != NULL)
    {
        printf("%d -> ", p->val);
        p = p->next;
    }
    printf("%d\n", p->val);
}

int main()
{
    ListNode *head = NULL;
    int choice, new_val, pos;
    printList(head);
    return 0;
}