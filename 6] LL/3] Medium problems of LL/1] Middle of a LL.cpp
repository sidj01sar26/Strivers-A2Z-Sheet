// https://www.naukri.com/code360/problems/middle-of-linked-list_973250

// https://leetcode.com/problems/middle-of-the-linked-list/description/

#include <iostream>
#include <vector>
using namespace std;

// Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

class Solution
{
public:
    Node *middleNode(Node *head)
    {
        Node *slow = head; // Initialize slow pointer to head
        Node *fast = head; // Initialize fast pointer to head

        // Traverse the list

        // while(fast && fast->next)
        //           or

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;       // Move slow pointer one step
            fast = fast->next->next; // Move fast pointer two steps
        }

        // When fast pointer reaches the end, slow pointer will be at the middle
        return slow;
    }
};