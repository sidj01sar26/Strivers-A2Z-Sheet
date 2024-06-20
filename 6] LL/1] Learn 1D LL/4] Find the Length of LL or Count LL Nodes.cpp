// https://www.geeksforgeeks.org/problems/count-nodes-of-linked-list/0?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=count-nodes-of-linked-list

#include <iostream>
using namespace std;

// Define a structure for a Node in a linked list
struct Node
{
    int data;   // Data stored in the node
    Node *next; // Pointer to the next node in the list

    // Constructor to initialize a node with data x
    Node(int x)
    {
        data = x;
        next = NULL; // Initialize next pointer to NULL
    }
};

// Define a class named Solution
class Solution
{
public:
    // Method to count the number of nodes in a linked list
    int getCount(struct Node *head)
    {
        int count = 0;        // Initialize count to 0
        Node *current = head; // Start from the head of the list

        // Traverse the list until the end (NULL pointer)
        while (current != NULL)
        {
            count++;                 // Increment count for each node
            current = current->next; // Move to the next node
        }
        return count; // Return the total count of nodes
    }
};

// Main function where execution begins
int main()
{
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node *head = new Node(1);                   // Create first node with data 1
    head->next = new Node(2);                   // Create second node with data 2
    head->next->next = new Node(3);             // Create third node with data 3
    head->next->next->next = new Node(4);       // Create fourth node with data 4
    head->next->next->next->next = new Node(5); // Create fifth node with data 5

    // Create an instance of the Solution class
    Solution solution;
    // Call getCount method to get the number of nodes in the list
    int count = solution.getCount(head);

    // Output the number of nodes in the linked list
    cout << "Number of nodes in the linked list: " << count << endl;

    return 0; // Return 0 to indicate successful execution
}
