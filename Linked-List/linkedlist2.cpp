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

Node *reverse_list_loop(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *prev = head;
    Node *curr = head->next;
    head = head->next;
    prev->next = NULL;
    int i = 0;
    while (head != NULL)
    {
        head = head->next;
        curr->next = prev;
        prev = curr;
        curr = head;
        // cout << "prev " << prev->data << ", curr " << curr->data << ", head " << head->data << endl;
        i++;
    }
    head = prev;
    // cout << "last = " << prev->data << endl;
    return head;
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
    head = push_start(head, 20);
    head = push_start(head, 30);
    head = push_start(head, 40);
    printList(head);
    head = reverse_list_loop(head);
    printList(head);
    while (1)
    {
        printf("\n1. Push Start\n");
        printf("2. Reverse with loop\n");
        printf("3. Reverse with recursion\n\n");
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
            head = reverse_list_loop(head);
            cout << head << endl;
            printList(head);
            break;
        case 3:
            printList(head);
            break;
        default:
            break;
        }
    }
    printList(head);
    return 0;
}