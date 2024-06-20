// Leetcode
// https://leetcode.com/problems/delete-node-in-a-linked-list/

#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct ListNode
{
    int val;                                // Value stored in the node
    ListNode *next;                         // Pointer to the next node in linked list
    ListNode(int x) : val(x), next(NULL) {} // Constructor to initialize the node
};

class Solution
{
public:
    // Function to delete the given node (except the tail) from the linked list
    void deleteNode(ListNode *node)
    {
        node->val = node->next->val;   // Copy the value of the next node to the current node
        node->next = node->next->next; // Link the current node to the node after the next node
    }
};

// Function to print the linked list
void printList(ListNode *head)
{
    ListNode *current = head; // Start from the head of the list
    while (current != NULL)
    {                                // Traverse until the end of the list
        cout << current->val << " "; // Print the current node's value
        current = current->next;     // Move to the next node
    }
    cout << endl; // Print a newline at the end
}

// Main function to demonstrate the deleteNode operation
int main()
{
    // Create a linked list: 4 -> 5 -> 1 -> 9
    ListNode *head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);

    // Print the original list
    cout << "Original list: ";
    printList(head); // Output: 4 5 1 9

    Solution solution; // Create an object of the Solution class

    // Delete the node with value 5 (which is the second node in the list)
    solution.deleteNode(head->next);

    // Print the list after deletion
    cout << "List after deleting node with value 5: ";
    printList(head); // Output: 4 1 9

    return 0; // Indicate that the program ended successfully
}