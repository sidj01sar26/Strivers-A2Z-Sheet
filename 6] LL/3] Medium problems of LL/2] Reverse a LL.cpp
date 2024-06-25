// https://www.naukri.com/code360/problems/reverse-linked-list_920513?leftPanelTabValue=PROBLEM

// https://leetcode.com/problems/reverse-linked-list/

#include <iostream>
#include <vector>
using namespace std;

// Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

Node *reverseLinkedList(Node *head)
{
    Node *prev = NULL; // Initialize prev pointer to NULL

    // Traverse the list
    while (head)
    {
        Node *next = head->next; // Store the next node
        head->next = prev;       // Reverse the next pointer of the current node
        prev = head;             // Move prev to the current node
        head = next;             // Move head to the next node
    }

    // At the end of the loop, prev will be the new head of the reversed list
    return prev;
}

// or

// Striver

Node *reverseLinkedList(Node *head)
{
    // Base case: if the list is empty or has only one node, return the head
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // Recursive call to reverse the rest of the list starting from the second node
    Node *newHead = reverseLinkedList(head->next);

    Node *front = head->next; // Get the next node
    front->next = head;       // Reverse the next pointer of the next node to point to the current node
    head->next = NULL;        // Set the next pointer of the current node to NULL

    return newHead; // Return the new head of the reversed list
}