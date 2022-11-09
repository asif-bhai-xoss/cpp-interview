#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
};

ListNode *head = NULL;
// stack push, pop, top
ListNode *stack_push(int new_data)
{
    ListNode *node = new ListNode();
    node->val = new_data;
    node->next = head;
    head = node;
    return head;
}
int stack_top()
{
    return head->val;
}

ListNode *stack_pop()
{
    ListNode *temp = head;
    head = head->next;
    return temp;
}

void print_stack()
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
    ListNode *pop_node = NULL;
    head = stack_push(10);
    head = stack_push(20);
    head = stack_push(30);
    print_stack();
    cout << "Top =" << stack_top() << endl;
    pop_node = stack_pop();
    cout << "Pop = " << pop_node->val << endl;
    print_stack();
    return 0;
}