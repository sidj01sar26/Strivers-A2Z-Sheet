// https://www.geeksforgeeks.org/problems/search-in-linked-list-1664434326/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=search-in-linked-list-1664434326

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
    // Function to search for a key in a linked list
    bool searchKey(int n, Node *head, int key)
    {
        Node *current = head; // Start from the head of the list

        // Traverse up to n nodes or until the end of the list (NULL pointer)
        while (current != NULL && n > 0)
        {
            if (current->data == key)
            {
                return true; // Key found, return true
            }
            current = current->next; // Move to the next node
            n--;                     // Decrement count of remaining nodes
        }
        return false; // Key not found within the specified number of nodes
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

    // Search for a key in the linked list up to 3 nodes
    int key = 3;
    int n = 3; // Search up to 3 nodes
    bool found = solution.searchKey(n, head, key);

    // Output the result
    if (found)
    {
        cout << "Key " << key << " found within the first " << n << " nodes of the linked list." << endl;
    }
    else
    {
        cout << "Key " << key << " not found within the first " << n << " nodes of the linked list." << endl;
    }

    return 0; // Return 0 to indicate successful execution
}

// OR

// class Solution
// {
// public:
//     // Function to search for a key in a linked list
//     bool searchKey(Node *head, int key)
//     {
//         Node *current = head; // Start from the head of the list

//         // Traverse the list until the end (NULL pointer)
//         while (current != NULL)
//         {
//             if (current->data == key)
//             {
//                 return true; // Key found, return true
//             }
//             current = current->next; // Move to the next node
//         }
//         return false; // Key not found, return false
//     }
// };