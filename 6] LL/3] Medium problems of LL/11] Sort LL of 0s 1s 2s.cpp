// https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=given-a-linked-list-of-0s-1s-and-2s-sort-it

// https://www.naukri.com/code360/problems/sort-linked-list-of-0s-1s-2s_1071937?leftPanelTabValue=PROBLEM

#include <iostream>
#include <vector>
using namespace std;

// Following is the class structure of the Node class :

class Node
{
public:
    int data;   // Stores the value of the node
    Node *next; // Pointer to the next node in the list
    Node()
    {
        this->data = 0; // Default value for data
        next = NULL;    // Default next pointer is NULL
    }
    Node(int data)
    {
        this->data = data; // Initialize data with the given value
        this->next = NULL; // Initialize next pointer to NULL
    }
    Node(int data, Node *next)
    {
        this->data = data; // Initialize data with the given value
        this->next = next; // Initialize next pointer with the given node
    }
};

Node *sortList(Node *head)
{
    // If the list is empty or has only one node, return the head as it is already sorted
    if (!head || !head->next)
    {
        return head;
    }

    // Create dummy nodes to act as the heads of three separate lists: for 0s, 1s, and 2s
    Node *zeroHead = new Node(-1); // Dummy node for the list of 0s
    Node *oneHead = new Node(-1);  // Dummy node for the list of 1s
    Node *twoHead = new Node(-1);  // Dummy node for the list of 2s

    // Pointers to the current last node of each respective list
    Node *zero = zeroHead; // Pointer to the last node in the 0s list
    Node *one = oneHead;   // Pointer to the last node in the 1s list
    Node *two = twoHead;   // Pointer to the last node in the 2s list
    Node *temp = head;     // Pointer to traverse the original list

    // Traverse the original list and distribute the nodes into the three lists based on their data values
    while (temp)
    {
        // If the current node's data is 0, add it to the 0s list
        if (temp->data == 0)
        {
            zero->next = temp; // Link the node to the end of the 0s list
            zero = zero->next; // Move the zero pointer to this node
        }
        // If the current node's data is 1, add it to the 1s list
        else if (temp->data == 1)
        {
            one->next = temp; // Link the node to the end of the 1s list
            one = one->next;  // Move the one pointer to this node
        }
        // If the current node's data is 2, add it to the 2s list
        else
        {
            two->next = temp; // Link the node to the end of the 2s list
            two = two->next;  // Move the two pointer to this node
        }
        temp = temp->next; // Move to the next node in the original list
    }

    // Connect the three lists to form a single sorted list
    // Connect the end of the 0s list to the beginning of the 1s list if it exists, otherwise to the 2s list
    zero->next = (oneHead->next) ? (oneHead->next) : (twoHead->next);
    // Connect the end of the 1s list to the beginning of the 2s list
    one->next = twoHead->next;
    // Ensure the end of the 2s list points to NULL
    two->next = NULL;

    // The new head of the sorted list is the first node after the zeroHead dummy node
    Node *newHead = zeroHead->next;

    // Delete the dummy nodes to free up memory
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    // Return the head of the sorted list
    return newHead;
}