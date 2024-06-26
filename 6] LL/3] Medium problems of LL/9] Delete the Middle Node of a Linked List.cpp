// https://www.naukri.com/code360/problems/delete-middle-node_763267?leftPanelTabValue=PROBLEM

// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/

#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *deleteMiddle(ListNode *head)
    {
        // If the list is empty or has only one node, return NULL
        if (head == NULL || head->next == NULL)
        {
            return NULL;
        }

        ListNode *slow = head; // Initialize slow pointer to head
        ListNode *fast = head; // Initialize fast pointer to head

        // Move fast pointer two steps ahead initially
        fast = head->next->next;

        // Traverse the list with slow moving one step and fast moving two steps
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;       // Move slow pointer one step
            fast = fast->next->next; // Move fast pointer two steps
        }

        // slow now points to the node before the middle node
        slow->next = slow->next->next; // Remove the middle node by skipping it

        return head; // Return the head of the modified list
    }
};