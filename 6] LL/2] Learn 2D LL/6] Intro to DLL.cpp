// https://www.geeksforgeeks.org/problems/introduction-to-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=introduction-to-doubly-linked-list

#include <iostream>
#include <vector>
using namespace std;

#include <iostream>
#include <vector>
using namespace std;

// Definition of the Node class
class Node
{
public:
    Node *prev; // Pointer to the previous node
    int data;   // Data stored in the node
    Node *next; // Pointer to the next node

    // Default constructor
    Node()
    {
        prev = NULL; // Initialize prev to NULL
        data = 0;    // Initialize data to 0
        next = NULL; // Initialize next to NULL
    }

    // Constructor with data initialization
    Node(int value)
    {
        prev = NULL;  // Initialize prev to NULL
        data = value; // Initialize data with the given value
        next = NULL;  // Initialize next to NULL
    }
};

class Solution
{
public:
    // Function to construct a doubly linked list from a vector of integers
    Node *constructDLL(vector<int> &arr)
    {
        if (arr.empty()) return NULL; // If the input array is empty, return NULL

        Node *head = new Node(arr[0]); // Create head node with 1st element of array
        Node *current = head;          
        // Pointer to keep track of current node as we construct the list

        // Loop through the remaining elements of the array
        for (int i = 1; i < arr.size(); i++)
        {
            // Create a new node with current element of array
            Node *newNode = new Node(arr[i]);
            current->next = newNode; // Link the current node's next to the new node
            newNode->prev = current; // Link the new node's prev to the current node
            current = newNode;       // Move the current pointer to the new node
        }

        // Return the head of the constructed doubly linked list
        return head;
    }
};

// Function to print the doubly linked list
void printDLL(Node *head)
{
    // Pointer to traverse the list starting from the head
    Node *current = head;

    // Traverse the list until the end
    while (current != NULL)
    {
        // Print the data of the current node
        cout << current->data << " ";

        // Move to the next node
        current = current->next;
    }

    // Print a newline at the end
    cout << endl;
}

int main()
{
    // Input array to construct the doubly linked list
    vector<int> arr = {1, 2, 3, 4, 5};

    // Create an object of the Solution class
    Solution solution;

    // Construct the doubly linked list from the input array
    Node *head = solution.constructDLL(arr);

    // Print the constructed doubly linked list
    cout << "Doubly Linked List: ";
    printDLL(head);

    return 0; // Indicate that the program ended successfully
}