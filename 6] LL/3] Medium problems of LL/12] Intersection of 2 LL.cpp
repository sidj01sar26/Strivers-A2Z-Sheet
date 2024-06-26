// https://leetcode.com/problems/intersection-of-two-linked-lists/description/

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        // Initialize two pointers to traverse the lists
        ListNode *pointerA = headA;
        ListNode *pointerB = headB;

        // If either head is NULL, there can be no intersection
        if (pointerA == NULL || pointerB == NULL)
            return NULL;

        // Traverse both lists simultaneously
        while (pointerA != NULL && pointerB != NULL && pointerA != pointerB)
        {
            pointerA = pointerA->next;
            pointerB = pointerB->next;

            // If pointers collide or reach end together without collision, return any one of the pointers
            if (pointerA == pointerB)
                return pointerA;

            // If pointerA reaches the end, move it to the beginning of list B
            if (pointerA == NULL)
                pointerA = headB;

            // If pointerB reaches the end, move it to the beginning of list A
            if (pointerB == NULL)
                pointerB = headA;
        }

        // Return the intersection node or NULL if no intersection
        return pointerA;
    }
};