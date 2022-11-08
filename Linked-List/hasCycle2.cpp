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

ListNode *create_circular(ListNode *head, int start)
{
    ListNode *p = head;
    ListNode *start_node;
    ListNode *end_node;
    while (p != NULL)
    {
        if (p->val == start)
        {
            start_node = p;
        }
        else if (p->next == NULL)
        {
            end_node = p;
            break;
        }
        p = p->next;
    }
    end_node->next = start_node;
    return head;
}

ListNode *hasCycle_optimize2(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    int flag = 0;
    if (head == NULL)
    {
        return NULL;
    }
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        return NULL;
    }
    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

void printList(ListNode *head)
{
    ListNode *p = head;
    for (int i = 0; i < 12; i++)
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
    head = push_start(head, 10);
    head = push_start(head, 200);
    head = push_start(head, 30);
    head = push_start(head, 40);
    head = push_start(head, 50);
    head = push_start(head, 29);
    // printList(head);
    head = create_circular(head, 30);
    printList(head);
    cout << hasCycle_optimize2(head)->val << endl;

    return 0;
}