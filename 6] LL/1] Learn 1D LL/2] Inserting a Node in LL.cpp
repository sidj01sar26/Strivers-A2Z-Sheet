// https://www.geeksforgeeks.org/problems/linked-list-insertion-1587115620/0?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=linked-list-insertion

#include <iostream>
using namespace std;

/* Structure of the linked list node is as follows */
struct Node
{
    int data;          // Data stored in the node
    struct Node *next; // Pointer to the next node in the linked list

    Node(int x)
    {                // Constructor to initialize the node
        data = x;    // Set the node's data
        next = NULL; // Initialize the next pointer to NULL
    }
};

class Solution
{
public:
    // Function to insert a node at the beginning of the linked list
    Node *insertAtBegining(Node *head, int x)
    {
        Node *newNode = new Node(x); // Create a new node with the given value x
        newNode->next = head;        // Point the new node's next to the current head
        return newNode;              // Return the new node as the new head of the list
    }

    // Function to insert a node at the end of the linked list
    Node *insertAtEnd(Node *head, int x)
    {
        Node *newNode = new Node(x); // Create a new node with the given value x
        if (head == NULL)
        {                   // If the list is empty
            return newNode; // The new node is now the head of the list
        }
        Node *current = head; // Start from the head of the list
        while (current->next != NULL)
        {                            // Traverse to the end of the list
            current = current->next; // Move to the next node
        }
        current->next = newNode; // Link the last node to the new node
        return head;             // Return the unchanged head of the list
    }
};

// Function to print the linked list
void printList(Node *head)
{
    Node *current = head; // Start from the head of the list
    while (current != NULL)
    {                                 // Traverse until the end of the list
        cout << current->data << " "; // Print the current node's data
        current = current->next;      // Move to the next node
    }
    cout << endl; // Print a newline at the end
}

// Main function to demonstrate the insertion operations
int main()
{
    Solution solution; // Create an object of the Solution class
    Node *head = NULL; // Initialize the head of the list as NULL

    // Insert nodes at the beginning
    head = solution.insertAtBegining(head, 10); // List: 10
    head = solution.insertAtBegining(head, 20); // List: 20 -> 10
    head = solution.insertAtBegining(head, 30); // List: 30 -> 20 -> 10

    // Print the list
    cout << "List after inserting at the beginning: ";
    printList(head); // Output: 30 20 10

    // Insert nodes at the end
    head = solution.insertAtEnd(head, 40); // List: 30 -> 20 -> 10 -> 40
    head = solution.insertAtEnd(head, 50); // List: 30 -> 20 -> 10 -> 40 -> 50

    // Print the list
    cout << "List after inserting at the end: ";
    printList(head); // Output: 30 20 10 40 50

    return 0; // Indicate that the program ended successfully
}