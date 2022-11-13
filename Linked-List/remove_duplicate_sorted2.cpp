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

ListNode *remove_duplicate2(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    ListNode *temp = new ListNode();
    temp->val = 0;
    temp->next = head;
    ListNode *slow = temp;
    ListNode *fast = head;
    while (fast != NULL)
    {
        if (fast->next != NULL && fast->next->val == fast->val)
        {
            while (fast->next != NULL && fast->next->val == fast->val)
            {
                fast = fast->next;
            }
            slow->next = fast->next;
        }
        else
        {

            slow = slow->next;
        }
        fast = fast->next;
    }
    return temp->next;
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
    head1 = push_start(head1, 4);
    head1 = push_start(head1, 4);
    head1 = push_start(head1, 4);
    head1 = push_start(head1, 2);
    head1 = push_start(head1, 1);

    printList(head1);
    head1 = remove_duplicate2(head1);
    printList(head1);

    head2 = push_start(head2, 70);
    head2 = push_start(head2, 80);
    head2 = push_start(head2, 90);
    head2 = push_start(head2, 90);

    printList(head2);
    head2 = remove_duplicate2(head2);
    printList(head2);

    head3 = push_start(head3, 100);
    head3 = push_start(head3, 100);
    head3 = push_start(head3, 100);
    head3 = push_start(head3, 200);
    head3 = push_start(head3, 300);

    printList(head3);
    head3 = remove_duplicate2(head3);
    printList(head3);
    return 0;
}