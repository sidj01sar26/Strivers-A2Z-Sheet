// https://www.naukri.com/code360/problems/delete-kth-node-from-end-in-linked-list_799912?leftPanelTabValue=PROBLEM

// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *fast = head; // Pointer that moves n steps ahead of slow pointer
        ListNode *slow = head; // Pointer that will be behind the node to be deleted

        // Move fast pointer n steps ahead
        for (int i = 0; i < n; i++)
        {
            fast = fast->next;
        }

        // If fast pointer becomes NULL, it means the node to delete is the first node
        if (fast == NULL)
        {
            return head->next; // Return head->next which is the new head after removal
        }

        // Move slow and fast pointers until fast reaches the end of the list
        while (fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }

        // Now slow points to the node just before the node to be deleted
        ListNode *delNode = slow->next; // Node to be deleted
        slow->next = slow->next->next;  // Skip the node to be deleted
        delete delNode;                 // Free memory of the deleted node

        return head; // Return the head of the modified list
    }
};