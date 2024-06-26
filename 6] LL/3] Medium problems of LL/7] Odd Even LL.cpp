// https://leetcode.com/problems/odd-even-linked-list/description/

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
    ListNode *oddEvenList(ListNode *head)
    {
        // If the list is empty or has only one node, return it as is
        if (!head || !head->next) return head;

        // Initialize pointers for odd and even nodes
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *evenHead = even; // Keep the head of the even nodes

        // Loop until there are no more even nodes and even nodes' next nodes
        while (even && even->next)
        {
            odd->next = even->next; // Link odd node to the next odd node
            odd = odd->next;        // Move the odd pointer to the next odd node
            even->next = odd->next; // Link even node to the next even node
            even = even->next;      // Move the even pointer to the next even node
        }

        odd->next = evenHead; // Link the last odd node to the head of the even nodes
        return head;          // Return the modified list
    }
};