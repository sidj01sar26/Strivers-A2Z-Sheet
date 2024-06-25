// https://www.geeksforgeeks.org/problems/insert-a-node-in-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=insert-a-node-in-doubly-linked-list

#include <iostream>
#include <vector>
using namespace std;

/* a Node of the doubly linked list */
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
    Node(int x)
    {
        data = x;
        next = prev = NULL;
    }
};

// Function to insert a new node at given position in doubly linked list.
void addNode(Node *head, int pos, int data)
{
    // Create a new node with the given data
    Node *newnode = new Node(data);

    // Traverse to the node just before the position where we want to insert
    Node *temp = head;
    for (int i = 0; i < pos; ++i)
    {
        temp = temp->next;
    }

    // Link the new node to the next node
    newnode->next = temp->next;

    // If the next node is not null, update its previous link to the new node
    if (temp->next)
    {
        temp->next->prev = newnode;
    }

    // Link the previous node to the new node
    temp->next = newnode;

    // Link the new node back to the previous node
    newnode->prev = temp;
}