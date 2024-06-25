// https://www.naukri.com/code360/problems/cycle-detection-in-a-singly-linked-list_628974?leftPanelTabValue=PROBLEM

// https://leetcode.com/problems/linked-list-cycle/description/

// Following is the class structure of the Node class :

#include <iostream>
#include <vector>
using namespace std;

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
    bool hasCycle(Node *head)
    {
        Node *slow = head; // Initialize slow pointer to head
        Node *fast = head; // Initialize fast pointer to head

        // Traverse the list

        // while(fast != NULL && fast->next != NULL)
        // or

        while (fast && fast->next)
        {
            slow = slow->next;       // Move slow pointer one step
            fast = fast->next->next; // Move fast pointer two steps

            // If slow pointer and fast pointer meet, there is a cycle
            if (slow == fast)
            {
                return true;
            }
        }

        // If fast pointer reaches the end, there is no cycle
        return false;
    }
};