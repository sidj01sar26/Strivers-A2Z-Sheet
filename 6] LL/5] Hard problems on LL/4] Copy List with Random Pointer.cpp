// https://leetcode.com/problems/copy-list-with-random-pointer/description/

// https://www.naukri.com/code360/problems/clone-a-linked-list-with-random-pointers_983604?utm_source=youtube&utm_medium=affiliate&utm_campaign=Codestudio_Linkedlistseries&leftPanelTabValue=PROBLEM

#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head) return nullptr; // If the original list is empty, return nullptr

        unordered_map<Node *, Node *> m; // Map original node to its copy

        // First pass: Create copies of all nodes and map each original node to its copy
        Node *curr = head;
        while (curr)
        {
            m[curr] = new Node(curr->val); // Create a new node with the same value
            curr = curr->next;             // Move to the next node in the original list
        }

        // Second pass: Assign next and random pointers for each copy based on the map
        curr = head;
        while (curr)
        {
            Node *copy = m[curr];           // Get the copy of current original node
            copy->next = m[curr->next];     // Assign next pointer of copy using the map
            copy->random = m[curr->random]; // Assign random pointer of copy using the map
            curr = curr->next;              // Move to the next node in original list
        }

        return m[head]; // Return the head of the copy list (which corresponds to the head of the original list)
    }
};