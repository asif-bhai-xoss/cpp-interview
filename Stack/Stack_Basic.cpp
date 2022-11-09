#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
};

// stack push, pop, top
ListNode *stack_push(ListNode *head, int new_data)
{
    ListNode *node = new ListNode();
    node->val = new_data;
    node->next = head;
    head = node;
    return head;
}
int stack_top(ListNode *head)
{
    return head->val;
}

ListNode *stack_pop(ListNode *head)
{
    ListNode *temp = head;
    cout << "Pop value = " << temp->val << endl;
    head = head->next;
    return head;
}

void print_stack(ListNode *head)
{
    if (head == NULL)
    {
        printf("Stack is empty");
        return;
    }
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
    head = stack_push(head, 10);
    head = stack_push(head, 20);
    head = stack_push(head, 30);
    print_stack(head);
    cout << "Top =" << stack_top(head) << endl;
    head = stack_pop(head);
    print_stack(head);
    return 0;
}