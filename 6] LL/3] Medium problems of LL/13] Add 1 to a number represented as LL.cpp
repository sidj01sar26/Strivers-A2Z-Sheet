// https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=add-1-to-a-number-represented-as-linked-list

// https://www.naukri.com/code360/problems/add-one-to-linked-list_920557?leftPanelTabValue=PROBLEM

#include <iostream>
#include <vector>
using namespace std;

//  Definition of linked list:

class Node
{
public:
    int data;   // The value stored in the node
    Node *next; // Pointer to the next node in the list
    Node()
    {
        this->data = 0;    // Default value for data
        this->next = NULL; // Default next pointer is NULL
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

int addHelper(Node *temp)
{
    // Base case: if temp is NULL, we are at the end of the list
    if (temp == NULL)
    {
        return 1; // Return 1 to represent the "carry" from the addition
    }

    // Recursive case: process the next node first
    int carry = addHelper(temp->next);

    // Add the carry to the current node's data
    temp->data += carry;

    // If the current node's data is less than 10, no carry is needed
    if (temp->data < 10)
    {
        return 0; // No carry needed, return 0
    }

    // If the current node's data is 10 or more, set current node's data to 0 and return 1 as carry
    temp->data = 0;
    return 1; // Carry over to the previous node
}

Node *addOne(Node *head)
{
    // Start the helper function from the head of the list
    int carry = addHelper(head);

    // If there's still a carry after processing the entire list, add a new node at the beginning
    if (carry == 1)
    {
        Node *newNode = new Node(1); // Create a new node with data 1
        newNode->next = head;        // Point the new node's next to the current head
        head = newNode;              // Update the head to be the new node
    }

    // Return the potentially new head of the list
    return head;
}
