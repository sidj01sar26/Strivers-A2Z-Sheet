// https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=reverse-a-doubly-linked-list

#include <iostream>
#include <vector>
using namespace std;

/* Structure of Node */
struct Node
{
    int data;   // Data part of the node
    Node *next; // Pointer to the next node
    Node *prev; // Pointer to the previous node

    Node(int x)
    { // Constructor to initialize the node
        data = x;
        next = NULL; // Initially, next is set to NULL
        prev = NULL; // Initially, prev is set to NULL
    }
};

class Solution
{
public:
    Node *reverseDLL(Node *head)
    {
        // If the list is empty or has only one node, return the head
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        Node *current = head;  // Start from the head of the list
        Node *prevNode = NULL; // This will become the new head of the reversed list
        Node *nextNode = NULL; // Temporary pointer to store the next node

        // Traverse the list
        while (current != NULL)
        {
            nextNode = current->next;      // Store the next node
            current->next = current->prev; // Reverse the next pointer
            current->prev = nextNode;      // Reverse the prev pointer
            prevNode = current;            // Move prevNode to the current node
            current = nextNode;            // Move to the next node in the list
        }

        head = prevNode; // Update the head to the new head (last non-null node)
        return head;     // Return the new head of the reversed list
    }
};
