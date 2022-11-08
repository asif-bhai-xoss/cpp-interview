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

Node *create_circular(Node *head, int start)
{
    Node *p = head;
    Node *start_node;
    Node *end_node;
    while (p != NULL)
    {
        if (p->data == start)
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

bool hasCycle_normal(Node *head)
{
    printf("Creating an array with the list value, then check every value that if it is in the array, jodi array te oi value pawa jay tahole cycle ase\n");
    return true;
}

bool hasCycle_optimize(Node *head)
{
    Node *fast = head;
    Node *slow = head;
    if (head == NULL)
    {
        // ekhane jehetu cycle hote at least 2 ta node lage tai at least 2 ta node check kora lagbe
        return false;
    }
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}

void printList(Node *head)
{
    Node *p = head;
    for (int i = 0; i < 5; i++)
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
    head = push_start(head, 50);
    head = push_start(head, 29);
    // printList(head);
    // head = create_circular(head, 30);
    printList(head);
    cout << hasCycle_optimize(head) << endl;

    return 0;
}