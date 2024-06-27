// https://www.naukri.com/code360/problems/find-pairs-with-given-sum-in-doubly-linked-list_1164172?utm_source=youtube&utm_medium=affiliate&utm_campaign=Codestudio_Linkedlistseries&leftPanelTabValue=PROBLEM

#include <bits/stdc++.h>
using namespace std;

// Definition of doubly linked list:

class Node
{
public:
    int data;   // The value stored in the node
    Node *prev; // Pointer to the previous node in the list
    Node *next; // Pointer to the next node in the list
    Node()
    {
        this->data = 0;    // Default value for data
        this->prev = NULL; // Default previous pointer is NULL
        this->next = NULL; // Default next pointer is NULL
    }
    Node(int data)
    {
        this->data = data; // Initialize data with the given value
        this->prev = NULL; // Initialize previous pointer to NULL
        this->next = NULL; // Initialize next pointer to NULL
    }
    Node(int data, Node *next, Node *prev)
    {
        this->data = data; // Initialize data with the given value
        this->prev = prev; // Initialize previous pointer with the given node
        this->next = next; // Initialize next pointer with the given node
    }
};

// Helper function to find the tail of the doubly linked list
Node *findTail(Node *head)
{
    Node *tail = head; // Start from the head of the list

    // Traverse to the end of the list
    while (tail->next != NULL)
    {
        tail = tail->next; // Move to the next node
    }
    return tail; // Return the last node (tail) of the list
}

// Function to find pairs of nodes that sum up to the given value k
vector<pair<int, int>> findPairs(Node *head, int k)
{
    vector<pair<int, int>> ans; // Vector to store the pairs that sum to k

    // If the list is empty, return the empty vector
    if (head == NULL)
    {
        return ans;
    }

    Node *left = head;            // Initialize left pointer to the head of the list
    Node *right = findTail(head); // Initialize right pointer to the tail of the list

    // Traverse the list from both ends until the left and right pointers meet or cross
    while (left != NULL && right != NULL && left->data < right->data)
    {
        int sum = left->data + right->data; // Calculate the sum of the current pair of nodes

        // If the sum equals k
        if (sum == k)
        {
            ans.push_back({left->data, right->data}); // Add the pair to result vector
            left = left->next;                        // Move the left pointer forward
            right = right->prev;                      // Move the right pointer backward
        }

        // If the sum is less than k
        else if (sum < k)
        {
            left = left->next; // Move the left pointer forward to increase the sum
        }

        // If the sum is greater than k
        else
        {
            right = right->prev; // Move the right pointer backward to decrease the sum
        }
    }

    return ans; // Return the vector containing all pairs that sum to k
}