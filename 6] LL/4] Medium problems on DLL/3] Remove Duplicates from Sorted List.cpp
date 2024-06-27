// https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/

// https://www.naukri.com/code360/problems/remove-duplicates-from-a-sorted-doubly-linked-list_2420283?utm_source=youtube&utm_medium=affiliate&utm_campaign=Codestudio_Linkedlistseries&leftPanelTabValue=PROBLEM

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;                                                
    // The value stored in the node
    ListNode *next;                                         
    // Pointer to the next node in the list
    ListNode() : val(0), next(nullptr) {}                   
    // Default constructor initializes val to 0 and next to nullptr
    ListNode(int x) : val(x), next(nullptr) {}              
    // Constructor initializes val to x and next to nullptr
    ListNode(int x, ListNode *next) : val(x), next(next) {} 
    // Constructor initializes val to x and next to given next node
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *temp = head; // Start with the head of the list

        // Traverse the list until reaching the end
        while (temp != NULL && temp->next != NULL)
        {
            ListNode *nextNode = temp->next; // Get the next node

            // Check for duplicates
            while (nextNode != NULL && nextNode->val == temp->val)
            {
                ListNode *duplicate = nextNode; // Point to the duplicate node
                nextNode = nextNode->next;      // Move to the next node
                delete duplicate;               // Delete the duplicate node
            }

            temp->next = nextNode; // Link the current node to the next distinct node
            temp = temp->next;     // Move to the next node in the list
        }

        return head; // Return the modified list
    }
};