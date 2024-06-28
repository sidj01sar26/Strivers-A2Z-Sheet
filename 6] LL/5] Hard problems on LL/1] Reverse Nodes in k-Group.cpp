// https://leetcode.com/problems/reverse-nodes-in-k-group/description/

#include <bits/stdc++.h>
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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *cursor = head; // Initialize a cursor to traverse the list

        // Check if there are at least k nodes remaining in the list
        for (int i = 0; i < k; i++)
        {
            if (!cursor)
                return head;       // If fewer than k nodes are left, return the current head
            cursor = cursor->next; // Move cursor to the next node
        }

        ListNode *prev = nullptr; // Pointer to store the previous node during reversal
        ListNode *curr = head;    // Pointer to the current node

        // Reverse the first k nodes
        for (int i = 0; i < k; i++)
        {
            ListNode *next = curr->next; // Store the next node
            curr->next = prev;           // Reverse the current node's pointer to the previous node
            prev = curr;                 // Move prev to curr
            curr = next;                 // Move curr to next
        }

        // Recursively reverse the rest of the list in groups of k
        head->next = reverseKGroup(curr, k); // Link the head to the reversed sublist's head
        return prev;                         // Return the new head of the reversed sublist
    }
};

// or

// striver

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;           // The value stored in the node
 *     ListNode *next;    // Pointer to the next node in the list
 *     ListNode() : val(0), next(nullptr) {}           // Default constructor initializes val to 0 and next to nullptr
 *     ListNode(int x) : val(x), next(nullptr) {}      // Constructor initializes val to x and next to nullptr
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}  // Constructor initializes val to x and next to given next node
 * };
 */

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *temp = head;     // Initialize temp to traverse the list
        ListNode *prevLast = NULL; // Pointer to the last node of the previous reversed group

        // Iterate over the list
        while (temp != NULL)
        {
            ListNode *kThNode = getKthNode(temp, k); // Get the k-th node from temp

            if (kThNode == NULL)
            { // If there are less than k nodes left
                if (prevLast)
                {
                    prevLast->next = temp; // Connect the last reversed group with the remaining nodes
                }
                break; // Exit the loop
            }

            ListNode *nextNode = kThNode->next;          // Store the node after k-th node
            kThNode->next = NULL;                        // Disconnect k-th node from the rest of the list
            ListNode *newHead = reverseLinkedList(temp); // Reverse the k nodes starting from temp

            if (temp == head)
            {                   // If this is the first group
                head = newHead; // Update the head to newHead
            }
            else
            {
                prevLast->next = newHead; // Connect the last node of the previous group to the new head
            }

            prevLast = temp; // Update prevLast to the last node of the current reversed group
            temp = nextNode; // Move temp to the next node to process
        }

        return head; // Return the new head of the modified list
    }

private:
    // Function to reverse a linked list
    ListNode *reverseLinkedList(ListNode *head)
    {
        ListNode *temp = head; // Initialize temp to traverse the list
        ListNode *prev = NULL; // Initialize prev to keep track of the previous node

        while (temp != NULL)
        {                                 // Traverse the list
            ListNode *front = temp->next; // Store the next node
            temp->next = prev;            // Reverse the current node's pointer
            prev = temp;                  // Move prev to the current node
            temp = front;                 // Move temp to the next node
        }

        return prev; // Return the new head of the reversed list
    }

    // Function to get the k-th node from the given node
    ListNode *getKthNode(ListNode *temp, int k)
    {
        k -= 1; // Decrement k by 1 to get the correct k-th node

        while (temp != NULL && k > 0)
        {                      // Traverse the list until k nodes are traversed
            k--;               // Decrement k
            temp = temp->next; // Move temp to the next node
        }

        return temp; // Return the k-th node or NULL if there are less than k nodes
    }
};