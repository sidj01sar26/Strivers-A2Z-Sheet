// https://www.naukri.com/code360/problems/add-two-numbers-as-linked-lists_1170520?leftPanelTabValue=PROBLEM

// https://leetcode.com/problems/add-two-numbers/description/

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(); // Create a dummy node to simplify handling edge cases
        ListNode *temp = dummy;           // Pointer to traverse and build the result list
        int carry = 0;                    // Initialize carry to 0

        // Iterate through both lists and process carry until both lists are processed and carry is zero
        while (l1 != NULL || l2 != NULL || carry)
        {
            int sum = 0;

            // Add values from l1 if it exists
            if (l1 != NULL)
            {
                sum += l1->val;
                l1 = l1->next;
            }

            // Add values from l2 if it exists
            if (l2 != NULL)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            // Add carry from the previous calculation
            sum += carry;
            carry = sum / 10;                        // Determine the carry for the next calculation
            ListNode *node = new ListNode(sum % 10); // Create a new node with the sum % 10
            temp->next = node;                       // Link the new node to the result list
            temp = temp->next;                       // Move the temp pointer forward
        }

        return dummy->next; // Return the next node after the dummy node, which is the head of the result list
    }
};