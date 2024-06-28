// https://leetcode.com/problems/rotate-list/description/

// https://www.naukri.com/code360/problems/rotate-linked-list_920454?utm_source=youtube&utm_medium=affiliate&utm_campaign=Codestudio_Linkedlistseries&leftPanelTabValue=PROBLEM

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
    ListNode *rotateRight(ListNode *head, int k)
    {
        // Check edge cases: empty list, single node list, or zero rotation
        if (!head || !head->next || k == 0)
        {
            return head;
        }

        // Step 1: Calculate the length of the list and find the current tail
        int length = 1; // Initialize length to 1 (since head is not nullptr)
        ListNode *tail = head;
        while (tail->next)
        {
            tail = tail->next; // Move tail to the last node
            length++;          // Increment length for each node traversed
        }

        // Step 2: Connect the current tail to the head to form a circular linked list
        tail->next = head;

        // Step 3: Calculate the effective rotations needed (k % length)
        k = k % length;

        // Step 4: Find the new tail node which will be at (length - k - 1) position
        ListNode *newTail = head;
        for (int i = 0; i < length - k - 1; i++)
        {
            newTail = newTail->next; // Move newTail to the node before the new head
        }

        // Step 5: The new head node is the node next to the new tail
        ListNode *newHead = newTail->next;

        // Step 6: Break the circular link by setting newTail's next to nullptr
        newTail->next = nullptr;

        // Step 7: Return the new head of the rotated list
        return newHead;
    }
};