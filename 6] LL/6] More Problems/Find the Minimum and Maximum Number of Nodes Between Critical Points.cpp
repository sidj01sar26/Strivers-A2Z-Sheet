// https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/description/

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
    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {
        vector<int> ans = {-1, -1}; // Initialize result vector with {-1, -1} representing no valid distances initially
        ListNode *prev = head;      // Initialize previous pointer to head of the list
        if (!prev)
            return ans;              // If the list is empty, return {-1, -1}
        ListNode *curr = head->next; // Initialize current pointer to the second node
        if (!curr)
            return ans;                   // If there's only one node, return {-1, -1}
        ListNode *nxt = head->next->next; // Initialize next pointer to the third node
        if (!nxt)
            return ans; // If there are only two nodes, return {-1, -1}

        int firstCP = -1;      // Index of the first critical point
        int lastCP = -1;       // Index of the last critical point
        int minDist = INT_MAX; // Initialize mini distance to maxi poss integer value
        int i = 1;             // Initialize the index to 1 since we start checking from the second node

        // Traverse the list to find critical points
        while (nxt)
        {
            // Check if the current node is a critical point
            bool isCP = ((curr->val > prev->val && curr->val > nxt->val) ||
                         (curr->val < prev->val && curr->val < nxt->val))
                            ? true
                            : false;
            if (isCP && firstCP == -1)
            {
                // If it's the first critical point found, set both firstCP and lastCP to its index
                firstCP = i;
                lastCP = i;
            }
            else if (isCP)
            {
                // If another critical point is found, update the minimum distance and lastCP
                minDist = min(minDist, i - lastCP);
                lastCP = i;
            }
            i++;               // Increment the index
            prev = prev->next; // Move the previous pointer to the next node
            curr = curr->next; // Move the current pointer to the next node
            nxt = nxt->next;   // Move the next pointer to the next node
        }

        if (lastCP == firstCP)
        {
            // If only one critical point was found, return {-1, -1}
            return ans;
        }
        else
        {
            // Otherwise, update the result vector with the minimum and maximum distances
            ans[0] = minDist;          // Minimum distance between any two critical points
            ans[1] = lastCP - firstCP; // Maximum distance between the first and last critical points
        }
        return ans; // Return the result
    }
};

// or

class Solution
{
public:
    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {
        // If the list has less than 3 nodes, return {-1, -1} because there can't be any critical points
        if (!head || !head->next || !head->next->next)
            return {-1, -1};

        vector<int> criticalPoints;        // To store the indices of critical points
        ListNode *prev = head;             // Pointer to the previous node
        ListNode *curr = head->next;       // Pointer to the current node
        ListNode *next = head->next->next; // Pointer to the next node
        int index = 1;                     // Index of the current node

        // Traverse the list until next is not NULL
        while (next)
        {
            // Check if the current node is a critical point
            if ((curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val))
            {
                criticalPoints.push_back(index); // Store index of the critical point
            }
            // Move to the next set of nodes
            prev = curr;
            curr = next;
            next = next->next;
            index++; // Increment the index
        }

        // If there are less than 2 critical points, return {-1, -1}
        if (criticalPoints.size() < 2)
            return {-1, -1};

        int minDist = INT_MAX;                                        // Initialize minDist to maximum integer value
        int maxDist = criticalPoints.back() - criticalPoints.front(); // Maximum distance is the difference between the first and last critical points

        // Find the minimum distance between consecutive critical points
        for (size_t i = 1; i < criticalPoints.size(); i++)
        {
            minDist = min(minDist, criticalPoints[i] - criticalPoints[i - 1]);
        }

        // Return the minimum and maximum distances
        return {minDist, maxDist};
    }
};

// gfg

