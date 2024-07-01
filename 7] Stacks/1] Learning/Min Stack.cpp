// https://leetcode.com/problems/min-stack/description/

#include <bits/stdc++.h>
using namespace std;

class MinStack
{
private:
    stack<int> s1; // Main stack to store all elements
    stack<int> s2; // Auxiliary stack to keep track of minimum elements

public:
    MinStack()
    {
        // Constructor: no initialization required for the stacks.
    }

    // Function to push an element onto the stack
    void push(int val)
    {
        s1.push(val); // Push the value onto the main stack

        // If the auxiliary stack is empty or the new value is less than or equal
        // to the current minimum on the auxiliary stack, push it onto the auxiliary stack.
        if (s2.empty() || val <= s2.top())
        {
            s2.push(val);
        }
    }

    // Function to pop the top element from the stack
    void pop()
    {
        // If the element being popped from s1 is the same as the current minimum in s2,
        // pop from s2 as well to maintain accurate tracking of minimums.
        if (s1.top() == s2.top())
        {
            s2.pop();
        }
        s1.pop(); // Always pop from s1, which contains all elements.
    }

    // Function to get the top element of the stack
    int top()
    {
        return s1.top(); // Return the top element of s1
    }

    // Function to get the minimum element in the stack
    int getMin()
    {
        return s2.top(); // Return the top element of s2, which is the current minimum
    }
};