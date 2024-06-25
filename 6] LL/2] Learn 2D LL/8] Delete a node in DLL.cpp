// https://www.geeksforgeeks.org/problems/delete-node-in-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=delete-node-in-doubly-linked-list

#include <iostream>
#include <vector>
using namespace std;

/* Structure of Node */
struct Node
{
    int data;
    Node *next;
    Node *prev;

    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

class Solution
{
public:
    Node *deleteNode(Node *head, int x)
    {
        // If the list is empty, return NULL
        if (head == NULL)
        {
            return head;
        }

        Node *temp = head;

        // Deleting the first node
        if (x == 1)
        {
            head = temp->next; // Move head to the next node
            if (head != NULL)
            {
                head->prev = NULL; // Set the new head's previous to NULL
            }
            delete temp; // Delete the old head node
            return head;
        }

        // Find the node to be deleted
        for (int i = 1; temp != NULL && i < x; i++)
        {
            temp = temp->next; // Move to the next node
        }

        // If the node to be deleted is not present
        if (temp == NULL)
        {
            return head; // Return the original head
        }

        // If the node to be deleted is the last node
        if (temp->next == NULL)
        {
            temp->prev->next = NULL; // Set the previous node's next to NULL
            delete temp;             // Delete the last node
            return head;
        }

        // If the node to be deleted is in the middle
        temp->prev->next = temp->next; // Link the previous node to the next node
        temp->next->prev = temp->prev; // Link the next node to the previous node
        delete temp;                   // Delete the node

        return head; // Return the updated head
    }
};