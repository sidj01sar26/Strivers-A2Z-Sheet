// https://leetcode.com/problems/palindrome-linked-list/description/

// https://www.naukri.com/code360/problems/check-if-linked-list-is-palindrome_985248?leftPanelTabValue=PROBLEM

#include <iostream>
#include <vector>
using namespace std;

//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    // Function to reverse a linked list
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head; // Base case: if list is empty or has one node
        }
        ListNode *newHead = reverseList(head->next); // Recursive call to reverse the rest of the list
        ListNode *nextNode = head->next;             // Next node in the list
        nextNode->next = head;                       // Reverse the current node
        head->next = NULL;                           // Set current node's next to null
        return newHead;                              // Return the new head of the reversed list
    }

    // Function to check if a linked list is a palindrome
    bool isPalindrome(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return true; // Base case: if list is empty or has one node
        }

        ListNode *slow = head; // Slow pointer
        ListNode *fast = head; // Fast pointer

        // Move slow to the middle of the list and fast to the end
        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *secondHalf = reverseList(slow->next); // Reverse the second half of the list
        ListNode *firstHalf = head;                     // First half starts at the head
        ListNode *checkHalf = secondHalf;               // Pointer to iterate through the reversed second half

        // Compare the first half and the reversed second half
        while (checkHalf != NULL)
        {
            if (firstHalf->val != checkHalf->val)
            {
                reverseList(secondHalf); // Restore the original list before returning
                return false;            // Not a palindrome
            }
            firstHalf = firstHalf->next;
            checkHalf = checkHalf->next;
        }

        reverseList(secondHalf); // Restore the original list
        return true;             // List is a palindrome
    }
};