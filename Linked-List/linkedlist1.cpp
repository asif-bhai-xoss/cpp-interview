#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

Node *push_end(Node *head, int new_data)
{
    if (head == NULL)
    {
        Node *node = new Node();
        node->data = new_data;
        node->next = NULL;
        head = node;
        return head;
    }
    Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    Node *node = new Node();
    node->data = new_data;
    node->next = NULL;
    p->next = node;
    return head;
}

Node *push_start(Node *head, int new_data)
{
    Node *node = new Node();
    node->data = new_data;
    node->next = head;
    head = node;
    return head;
}

Node *push_nth(Node *head, int pos, int new_data)
{
    Node *node = new Node();
    node->data = new_data;

    if (head == NULL || pos == 1)
    {
        node->next = head;
        head = node;
        return head;
    }
    pos = pos - 3;
    Node *p = head;
    for (int i = 0; i <= pos; i++)
    {
        p = p->next;
    }
    node->next = p->next;
    p->next = node;
    return head;
}

Node *delete_by_pos(Node *head, int pos)
{
    Node *temp;
    if (head == NULL || pos == 1)
    {
        temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node *p = head;
    pos = pos - 3;
    for (int i = 0; i <= pos; i++)
    {
        p = p->next;
    }
    temp = p->next;
    p->next = p->next->next;
    free(temp);
    return head;
}

Node *delete_by_value(Node *head, int value)
{
    Node *p = head;
    Node *temp;
    if (p->next == NULL || p->data == value)
    {
        temp = p;
        free(temp);
        head = head->next;
        return head;
    }
    while (p->next->next != NULL)
    {
        if (p->next->data == value)
        {
            break;
        }
        p = p->next;
    }
    temp = p;
    temp = p->next;
    p->next = p->next->next;
    free(temp);
    return head;
}

Node *reverse_list(Node *head)
{
    Node *p = head;
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
    while (1)
    {
        printf("\n1. Push Start\n");
        printf("2. Push End\n");
        printf("3. Push nth position\n");
        printf("4. Remove By position\n");
        printf("5. Remove By value\n\n");
        printf("Enter choice: ");
        cin >> choice;
        if (choice == 0)
        {
            break;
        }
        switch (choice)
        {
        case 1:
            printf("Enter new data: ");
            cin >> new_data;
            head = push_start(head, new_data);
            printList(head);
            break;
        case 2:
            printf("Enter new data: ");
            cin >> new_data;
            head = push_end(head, new_data);
            printList(head);
            break;
        case 3:
            printf("Enter position: ");
            cin >> pos;
            printf("Enter new data: ");
            cin >> new_data;
            head = push_nth(head, pos, new_data);
            printList(head);
            break;
        case 4:
            printf("Enter position: ");
            cin >> pos;
            head = delete_by_pos(head, pos);
            printList(head);
            break;
        case 5:
            int value;
            printf("Enter value: ");
            cin >> value;
            head = delete_by_value(head, value);
            printList(head);
            break;
        default:
            break;
        }
    }
    printList(head);
    return 0;
}