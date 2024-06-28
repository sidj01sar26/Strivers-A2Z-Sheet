// https://www.naukri.com/code360/problems/nth-node-from-end_920751

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *nthNodeFromEnd(Node *head, int n)
{
    Node *p1 = head; // Pointer 1 starts from the head
    Node *p2 = head; // Pointer 2 also starts from the head

    // Move p2 n nodes ahead of p1
    while (n > 1)
    {
        p2 = p2->next; // Move p2 forward by one node
        n--;           // Decrement n to track how many nodes ahead p2 is from p1
    }

    // Move both pointers until p2 reaches the end of the list
    while (p2->next != NULL)
    {
        p1 = p1->next; // Move p1 forward by one node
        p2 = p2->next; // Move p2 forward by one node
    }

    return p1; // Return p1, which is now pointing to the nth node from the end
}