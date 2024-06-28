// https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=flattening-a-linked-list

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

Node *merge(Node *a, Node *b)
{
    // Base cases: If either list is empty, return the other list.
    if (!a) return b;
    if (!b) return a;

    Node *ans = nullptr;
    // Compare the data values of the nodes to determine the order in the merged list.
    if (a->data < b->data)
    {
        ans = a;
        // Recursively merge the bottom list of a with b.
        a->bottom = merge(a->bottom, b);
    }
    else
    {
        ans = b;
        // Recursively merge a with the bottom list of b.
        b->bottom = merge(a, b->bottom);
    }
    return ans;
}

Node *flatten(Node *root)
{
    // Base case: If root is nullptr, return nullptr.
    if (!root)
        return nullptr;

    // Recursively flatten the list starting from the next pointer of root.
    Node *mergedLL = merge(root, flatten(root->next));
    return mergedLL;
}