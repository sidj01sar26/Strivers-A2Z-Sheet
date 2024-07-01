// babbar

// https://leetcode.com/problems/largest-rectangle-in-histogram/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the previous smaller element for each element in the input array
    vector<int> prevSmallerElement(vector<int> &input)
    {
        stack<int> s;
        s.push(-1); // Initialize stack with -1 to handle edge cases
        vector<int> ans(input.size());

        // Traverse the input array from left to right
        for (int i = 0; i < input.size(); i++)
        {
            int curr = input[i];

            // Pop elements from the stack until we find a smaller element
            while (s.top() != -1 && input[s.top()] >= curr)
            {
                s.pop();
            }

            // The top element is the previous smaller element
            ans[i] = s.top();

            // Push the current element's index onto the stack
            s.push(i);
        }
        return ans; // Return the array of previous smaller elements
    }

    // Function to find the next smaller element for each element in the input array
    vector<int> nextSmaller(vector<int> &input)
    {
        stack<int> s;
        s.push(-1); // Initialize stack with -1 to handle edge cases
        vector<int> ans(input.size());

        // Traverse the input array from right to left
        for (int i = input.size() - 1; i >= 0; i--)
        {
            int curr = input[i];

            // Pop elements from the stack until we find a smaller element
            while (s.top() != -1 && input[s.top()] >= curr)
            {
                s.pop();
            }

            // The top element is the next smaller element
            ans[i] = s.top();

            // Push the current element's index onto the stack
            s.push(i);
        }
        return ans; // Return the array of next smaller elements
    }

    // Function to find the largest rectangle area in a histogram
    int largestRectangleArea(vector<int> &heights)
    {
        // Step 1: Get previous smaller elements for each bar in the histogram
        vector<int> prev = prevSmallerElement(heights);

        // Step 2: Get next smaller elements for each bar in the histogram
        vector<int> next = nextSmaller(heights);

        int maxArea = INT_MIN; // Initialize the maximum area variable
        int size = heights.size();

        // Calculate the area for each bar
        for (int i = 0; i < heights.size(); i++)
        {
            int length = heights[i];

            // If no next smaller element, set it to the size of the histogram
            if (next[i] == -1)
            {
                next[i] = size;
            }

            // Calculate the width of the rectangle
            int width = next[i] - prev[i] - 1;

            // Calculate the area of the rectangle
            int area = length * width;

            // Update the maximum area
            maxArea = max(maxArea, area);
        }

        return maxArea; // Return the maximum rectangle area
    }
};

// or

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> st;        // Stack to store indices of histogram bars
        int maxArea = 0;      // Variable to store the maximum area
        heights.push_back(0); // Add a zero-height bar at the end to handle remaining bars

        // Traverse the heights array
        for (int i = 0; i < heights.size(); i++)
        {
            // Process the bars in the stack that are taller than the current bar
            while (!st.empty() && heights[st.top()] > heights[i])
            {
                int h = heights[st.top()]; // Height of the bar at the top of the stack
                st.pop();                  // Pop the top bar

                int w; // Width of the rectangle
                if (st.empty())
                {
                    w = i; // If stack is empty, width is the current index
                }
                else
                {
                    w = i - st.top() - 1; // Width is the distance between current index and the index of the new top of the stack
                }

                // Calculate the area with the popped bar as the smallest (or minimum height) bar
                maxArea = max(maxArea, h * w); // Update the maximum area
            }
            st.push(i); // Push the current index onto the stack
        }

        return maxArea; // Return the maximum area found
    }
};