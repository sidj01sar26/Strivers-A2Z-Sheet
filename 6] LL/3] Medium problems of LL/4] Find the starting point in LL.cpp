// Linked list Cycle II

// https://www.naukri.com/code360/problems/detect-the-first-node-of-the-loop_1112628?leftPanelTabValue=PROBLEM

// https://leetcode.com/problems/linked-list-cycle-ii/description/

#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

Node *firstNode(Node *head)
{
    Node *slow = head; // Initialize slow pointer to head
    Node *fast = head; // Initialize fast pointer to head

    // Traverse the list
    while (fast && fast->next)
    {
        slow = slow->next;       // Move slow pointer one step
        fast = fast->next->next; // Move fast pointer two steps

        // If slow pointer and fast pointer meet, there is a cycle
        if (slow == fast)
        {
            slow = head; // Move slow pointer to the head

            // Move both pointers one step at a time until they meet
            // The meeting point is the start of the cycle
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }

            return slow; // Return the node where the cycle begins
        }
    }

    // If no cycle is found, return NULL
    return NULL;
}