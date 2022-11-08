#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

Node *push_start(Node *head, int new_data)
{
    Node *node = new Node();
    node->data = new_data;
    node->next = head;
    head = node;
    return head;
}

int list_sum(Node *head) // 40 30 200 10
{
    Node *p = head;
    int sum = 0;
    while (p != NULL)
    {
        sum = sum + p->data;
        p = p->next;
    }
    return sum;
}
int list_max(Node *head)
{
    Node *p = head;
    int mx = p->data;
    while (p != NULL)
    {
        if (p->data > mx)
        {
            mx = p->data;
        }
        p = p->next;
    }
    return mx;
}
int list_min(Node *head)
{
    Node *p = head;
    int mn = p->data;
    while (p != NULL)
    {
        if (p->data < mn)
        {
            mn = p->data;
        }
        p = p->next;
    }
    return mn;
}

void printList(Node *head)
{
    Node *p = head;
    while (p->next != NULL)
    {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("%d\n", p->data);
}

int main()
{
    Node *head = NULL;
    int choice, new_data, pos;
    head = push_start(head, 10);
    head = push_start(head, 200);
    head = push_start(head, 30);
    head = push_start(head, 40);
    printList(head);
    printf("Max = %d\n", list_max(head));
    printf("Min = %d\n", list_min(head));
    printf("Sum = %d\n", list_sum(head));
    return 0;
}