// https://leetcode.com/problems/sort-list/description/

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
    // Function to find the middle of the linked list
    ListNode *findMiddle(ListNode *head)
    {
        ListNode *slow = head;       // Slow pointer
        ListNode *fast = head->next; // Fast pointer starts one step ahead

        // Move slow by 1 step and fast by 2 steps until fast reaches the end
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;       // Move slow pointer one step
            fast = fast->next->next; // Move fast pointer two steps
        }

        // Slow is now at the middle node
        return slow;
    }

    // Function to merge two sorted linked lists
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *dummyNode = new ListNode(-1); // Dummy node to simplify edge cases
        ListNode *temp = dummyNode;             // Pointer to build the new list

        // Merge nodes from both lists in sorted order
        while (list1 != NULL && list2 != NULL)
        {
            if (list1->val < list2->val)
            {
                temp->next = list1;  // Attach list1 node
                temp = list1;        // Move temp to list1
                list1 = list1->next; // Move list1 to the next node
            }
            else
            {
                temp->next = list2;  // Attach list2 node
                temp = list2;        // Move temp to list2
                list2 = list2->next; // Move list2 to the next node
            }
        }

        // Attach the remaining nodes of list1 or list2
        if (list1)
        {
            temp->next = list1;
        }
        else
        {
            temp->next = list2;
        }

        return dummyNode->next; // Return the merged list (skipping dummy node)
    }

    // Function to sort the linked list using merge sort
    ListNode *sortList(ListNode *head)
    {
        // Base case: if the list is empty or has one node, it's already sorted
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        // Find the middle of the list
        ListNode *middle = findMiddle(head);
        ListNode *right = middle->next; // Right half starts after the middle
        middle->next = NULL;            // Split the list into two halves
        ListNode *left = head;          // Left half starts from the head

        // Recursively sort the left and right halves
        left = sortList(left);
        right = sortList(right);

        // Merge the sorted halves
        return mergeTwoLists(left, right);
    }
};