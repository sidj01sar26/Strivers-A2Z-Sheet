// GFG
// https://www.geeksforgeeks.org/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    void linkdelete(struct Node *head, int M, int N)
    {
        struct Node *curr = head;
        struct Node *prev = NULL;

        while (curr)
        {
            // Skip M nodes
            for (int i = 0; i < M && curr; i++)
            {
                prev = curr;
                curr = curr->next;
            }

            // Delete N nodes
            for (int i = 0; i < N && curr; i++)
            {
                struct Node *temp = curr;
                curr = curr->next;
                free(temp);
            }

            // Connect previous node to the remaining list
            if (prev)
            {
                prev->next = curr;
            }
        }
    }
};

// or

// codestudio
// https://www.naukri.com/code360/problems/delete-n-nodes-after-m-nodes-of-a-linked-list_668903?leftPanelTabValue=PROBLEM

Node *getListAfterDeleteOperation(Node *head, int n, int m)
{
    Node *curr = head; // Initialize current node as head
    Node *prev = NULL; // Previous node pointer initially set to NULL

    while (curr)
    {
        // Skip M nodes
        for (int i = 0; i < m && curr; i++)
        {
            prev = curr;       // Update previous node to current node
            curr = curr->next; // Move to the next node
        }

        // Delete N nodes
        for (int i = 0; i < n && curr; i++)
        {
            Node *temp = curr; // Store current node in temp
            curr = curr->next; // Move to the next node
            delete temp;       // Delete the temp node
        }

        // Connect previous node to the remaining list
        if (prev)
        {
            prev->next = curr; // Link previous node to the current node
        }
        else
        {
            head = curr; // If prev is NULL, update head to current node
        }
    }

    return head; // Return the modified head of the list
}