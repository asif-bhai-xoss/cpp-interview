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

ListNode *remove_duplicate1(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    ListNode *slow = head;
    ListNode *fast = head->next;
    ListNode *temp = NULL;
    while (slow->next != NULL || fast != NULL)
    {
        if (slow->val == fast->val)
        {
            temp = fast;
            fast = fast->next;
            slow->next = fast;
            delete temp;
        }
        else
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
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
    ListNode *head1 = NULL;
    ListNode *head2 = NULL;
    ListNode *head3 = NULL;
    head1 = push_start(head1, 9);
    head1 = push_start(head1, 5);
    head1 = push_start(head1, 5);
    head1 = push_start(head1, 5);
    head1 = push_start(head1, 5);
    head1 = push_start(head1, 6);
    head1 = push_start(head1, 6);
    head1 = push_start(head1, 7);

    printList(head1);
    head1 = remove_duplicate1(head1);
    printList(head1);

    head2 = push_start(head2, 70);
    head2 = push_start(head2, 80);
    head2 = push_start(head2, 90);
    head2 = push_start(head2, 90);

    printList(head2);
    head2 = remove_duplicate1(head2);
    printList(head2);

    head3 = push_start(head3, 100);
    head3 = push_start(head3, 100);
    head3 = push_start(head3, 100);
    head3 = push_start(head3, 200);
    head3 = push_start(head3, 300);

    printList(head3);
    head3 = remove_duplicate1(head3);
    printList(head3);
    return 0;
}