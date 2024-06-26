// https://www.naukri.com/code360/problems/find-length-of-loop_8160455?utm_source=youtube&utm_medium=affiliate&utm_campaign=Codestudio_Linkedlistseries&leftPanelTabValue=PROBLEM

// https://www.geeksforgeeks.org/problems/find-length-of-loop/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-length-of-loop

// Definition of linked list:

#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

int findLength(Node *slow, Node *fast)
{
    int count = 1;     // Initialize count to 1 since slow and fast are initially the same
    fast = fast->next; // Move fast to the next node
    while (slow != fast)
    {
        count++;           // Increment count for each node in the loop
        fast = fast->next; // Move fast to the next node
    }
    return count; // Return the length of the loop
}

int lengthOfLoop(Node *head)
{
    Node *slow = head; // Initialize slow pointer to head
    Node *fast = head; // Initialize fast pointer to head

    // Traverse the list to find the cycle
    while (fast && fast->next)
    {
        slow = slow->next;       // Move slow pointer one step
        fast = fast->next->next; // Move fast pointer two steps

        // If slow pointer and fast pointer meet, there is a cycle
        if (slow == fast)
        {
            return findLength(slow, fast); // Find and return the length of the loop
        }
    }

    // If no cycle is found, return 0
    return 0;
}
