// https://www.geeksforgeeks.org/problems/introduction-to-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=introduction-to-linked-list

#include <iostream>
#include <vector>

using namespace std;

// Define the Node class to represent each node in the linked list
class Node
{
public:
    int data;   // Data stored in the node
    Node *next; // Pointer to the next node in the linked list

    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }

    // Parameterized Constructor to initialize the node with a given value
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Define the Solution class that contains the method to construct a linked list
class Solution
{
public:
    // Method to construct the linked list from a given array
    Node *constructLL(vector<int> &arr)
    {
        // If the array is empty, return NULL (no linked list to create)
        if (arr.empty())
        {
            return NULL;
        }

        // Create the head node with the first element of the array
        Node *head = new Node(arr[0]);
        Node *current = head; // Pointer to keep track of the current node

        // Loop through the rest of the array to create and link nodes
        for (int i = 1; i < arr.size(); i++)
        {
            Node *newNode = new Node(arr[i]); // Create a new node for each element
            current->next = newNode;          // Link the current node to the new node
            current = newNode;                // Move the current pointer to new node
        }

        // Return the head of the constructed linked list
        return head;
    }
};

// Helper function to print the linked list
void printLinkedList(Node *head)
{
    Node *current = head; // Pointer to traverse the linked list
    while (current != NULL)
    {
        cout << current->data << " "; // Print the data of each node
        current = current->next;      // Move to the next node
    }
    cout << endl;
}

// Main function for testing
int main()
{
    Solution solution;                      // Create an instance of the Solution class
    vector<int> arr = {1, 2, 3, 4, 5};      // Example array to create the linked list
    Node *head = solution.constructLL(arr); // Construct the linked list from the array
    printLinkedList(head);                  // Print the linked list; Output should be: 1 2 3 4 5

    return 0;
}
