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

ListNode *add_numbers(ListNode *head1, ListNode *head2)
{
    ListNode *p1 = head1;
    ListNode *p2 = head2;
    ListNode *node1 = new ListNode();
    node1->val = 0;
    ListNode *temp = node1;
    ListNode *head3 = temp;
    int sum = 0, carry = 0, x, y;
    while (p1 != NULL || p2 != NULL)
    {
        if (p1 == NULL && p2 != NULL)
        {
            x = 0;
            y = p2->val;
            p2 = p2->next;
        }
        else if (p1 != NULL && p2 == NULL)
        {
            x = p1->val;
            y = 0;
            p1 = p1->next;
        }
        else
        {
            x = p1->val;
            y = p2->val;
            p1 = p1->next;
            p2 = p2->next;
        }
        sum = (carry + x + y) % 10;
        carry = (carry + x + y) / 10;
        // cout << "Sum = " << sum << " "
        //      << "Carry = " << carry << endl;
        ListNode *node = new ListNode();
        node->val = sum;
        node->next = NULL;
        temp->next = node;
        temp = temp->next;
    }
    if (carry > 0)
    {
        ListNode *node = new ListNode();
        node->val = carry;
        node->next = NULL;
        temp->next = node;
        temp = temp->next;
    }
    return head3->next;
}
ListNode *add_numbers2(ListNode *head1, ListNode *head2)
{
    ListNode *p1 = head1;
    ListNode *p2 = head2;
    ListNode *node1 = new ListNode();
    node1->val = 0;
    ListNode *temp = node1;
    ListNode *head3 = temp;
    int sum = 0, carry = 0;
    while (p1 != NULL && p2 != NULL)
    {
        sum = (carry + p1->val + p2->val) % 10;
        carry = (carry + p1->val + p2->val) / 10;
        p1 = p1->next;
        p2 = p2->next;
        ListNode *node = new ListNode();
        node->val = sum;
        node->next = NULL;
        temp->next = node;
        temp = temp->next;
    }
    while (p1 != NULL)
    {
        sum = (carry + p1->val) / 10;
        carry = (carry + p1->val) % 10;
        p1 = p1->next;
        ListNode *node = new ListNode();
        node->val = sum;
        node->next = NULL;
        temp->next = node;
        temp = temp->next;
    }
    while (p2 != NULL)
    {
        sum = (carry + p2->val) / 10;
        carry = (carry + p2->val) % 10;
        p2 = p2->next;
        ListNode *node = new ListNode();
        node->val = sum;
        node->next = NULL;
        temp->next = node;
        temp = temp->next;
    }
    if (carry > 0)
    {
        ListNode *node = new ListNode();
        node->val = carry;
        node->next = NULL;
        temp->next = node;
    }
    return head3->next;
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
    ListNode *head1 = NULL;
    ListNode *head2 = NULL;
    ListNode *head3 = NULL;
    int choice, new_val, pos;
    head1 = push_start(head1, 9);
    head1 = push_start(head1, 5);
    head1 = push_start(head1, 5);
    head2 = push_start(head2, 7);
    head2 = push_start(head2, 6);
    head2 = push_start(head2, 3);
    printList(head1);
    printList(head2);
    head3 = add_numbers2(head1, head2);
    printList(head3);

    return 0;
}