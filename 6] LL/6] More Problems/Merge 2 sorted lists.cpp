// https://leetcode.com/problems/merge-two-sorted-lists/description/

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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // If either list1 or list2 is nullptr, return the other list (base cases)
        if (list1 == nullptr)
        {
            return list2;
        }
        if (list2 == nullptr)
        {
            return list1;
        }

        // Compare the values of the current nodes of list1 and list2
        if (list1->val <= list2->val)
        {
            // If list1's value is smaller or equal, set list1's next to the merged result of remaining list1 and list2
            list1->next = mergeTwoLists(list1->next, list2);
            return list1; // Return list1 as it becomes the merged list with updated connections
        }
        else
        {
            // Otherwise, set list2's next to the merged result of list1 and remaining list2
            list2->next = mergeTwoLists(list1, list2->next);
            return list2; // Return list2 as it becomes the merged list with updated connections
        }
    }
};