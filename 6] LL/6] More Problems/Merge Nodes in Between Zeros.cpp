// https://leetcode.com/problems/merge-nodes-in-between-zeros/description/

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
    ListNode *mergeNodes(ListNode *head)
    {
        ListNode *temp = head;        // Initialize temp to the head of the list
        ListNode *temp2 = head->next; // Initialize temp2 to second node of the list
        int sum = 0;                  // Initialize sum to 0 to keep track of sum of values between zeros

        // Traverse the list starting from the second node
        while (temp2)
        {
            // If the current node's value is 0
            if (temp2->val == 0)
            {
                temp->next = new ListNode(sum);
                // Create a new node with sum and link it to next of temp
                temp->next->next = temp2->next;
                // Link newly created node to node after temp2
                temp = temp->next;
                // Move temp to the newly created node
                sum = 0;
                // Reset sum to 0 for the next sequence
            }
            sum += temp2->val;   // Add the value of temp2 to sum
            temp2 = temp2->next; // Move temp2 to the next node
        }

        return head->next; // Return the modified list, starting from the node after the original head
    }
};