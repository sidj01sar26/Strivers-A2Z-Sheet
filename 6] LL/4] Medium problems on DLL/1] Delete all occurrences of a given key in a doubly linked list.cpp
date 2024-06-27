// https://www.naukri.com/code360/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list_8160461?utm_source=youtube&utm_medium=affiliate&utm_campaign=Codestudio_Linkedlistseries&leftPanelTabValue=PROBLEM

// https://www.geeksforgeeks.org/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list

#include <bits/stdc++.h>
using namespace std;

//  Definition of doubly linked list:

class Node
{
public:
    int data;   // The value stored in the node
    Node *prev; // Pointer to the previous node in the list
    Node *next; // Pointer to the next node in the list
    Node()
    {
        this->data = 0;    // Default value for data
        this->prev = NULL; // Default previous pointer is NULL
        this->next = NULL; // Default next pointer is NULL
    }
    Node(int data)
    {
        this->data = data; // Initialize data with the given value
        this->prev = NULL; // Initialize previous pointer to NULL
        this->next = NULL; // Initialize next pointer to NULL
    }
    Node(int data, Node *next, Node *prev)
    {
        this->data = data; // Initialize data with the given value
        this->prev = prev; // Initialize previous pointer with the given node
        this->next = next; // Initialize next pointer with the given node
    }
};

Node *deleteAllOccurrences(Node *head, int k)
{
    Node *temp = head; // Initialize a temporary pointer to traverse the list

    // Traverse the list until the end
    while (temp != NULL)
    {
        // If the current node's data matches k
        if (temp->data == k)
        {
            // If the current node is the head
            if (temp == head)
            {
                head = temp->next; // Update the head to the next node
            }
            Node *nextNode = temp->next; // Pointer to the next node
            Node *prevNode = temp->prev; // Pointer to the previous node

            // If the next node is not NULL
            if (nextNode != NULL)
            {
                nextNode->prev = prevNode; // Update next node's previous pointer to skip the current node
            }

            // If the previous node is not NULL
            if (prevNode != NULL)
            {
                prevNode->next = nextNode; // Update previous node's next pointer to skip the current node
            }
            free(temp);      // Free the memory of the current node
            temp = nextNode; // Move to the next node
        }
        else
        {
            temp = temp->next; // Move to the next node if data does not match k
        }
    }

    return head; // Return the updated head of the list
}