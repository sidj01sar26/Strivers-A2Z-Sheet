#include <iostream>
#include <stack>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    // Function to find the previous smaller elements for each element in the input vector
    vector<int> prevSmallerElement(vector<int> &input)
    {
        stack<int> s;
        s.push(-1); // Initialize stack with -1 to handle edge cases
        vector<int> ans(input.size());

        // Traverse the input vector from left to right
        for (int i = 0; i < input.size(); i++)
        {
            int curr = input[i];

            // Find the previous smaller element in the stack
            while (s.top() != -1 && input[s.top()] >= curr)
            {
                s.pop();
            }

            // Store the index of the previous smaller element
            ans[i] = s.top();

            // Push the current element index onto the stack
            s.push(i);
        }
        return ans;
    }

    // Function to find the next smaller elements for each element in the input vector
    vector<int> nextSmaller(vector<int> &input)
    {
        stack<int> s;
        s.push(-1); // Initialize stack with -1 to handle edge cases
        vector<int> ans(input.size());

        // Traverse the input vector from right to left
        for (int i = input.size() - 1; i >= 0; i--)
        {
            int curr = input[i];

            // Find the next smaller element in the stack
            while (s.top() != -1 && input[s.top()] >= curr)
            {
                s.pop();
            }

            // Store the index of the next smaller element
            ans[i] = s.top();

            // Push the current element index onto the stack
            s.push(i);
        }
        return ans;
    }

    // Function to find the largest rectangle area in a histogram
    int largestRectangleArea(vector<int> &heights)
    {
        // Step 1: Find the previous smaller elements
        vector<int> prev = prevSmallerElement(heights);

        // Step 2: Find the next smaller elements
        vector<int> next = nextSmaller(heights);

        int maxArea = INT_MIN;
        int size = heights.size();

        // Calculate the maximum area for each bar in the histogram
        for (int i = 0; i < heights.size(); i++)
        {
            int length = heights[i];

            // If there is no next smaller element, set it to the size of the histogram
            if (next[i] == -1)
            {
                next[i] = size;
            }

            int width = next[i] - prev[i] - 1;
            int area = length * width;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};

int main()
{
    Solution sol;
    vector<int> heights = {2, 1, 5, 6, 2, 3};

    int maxArea = sol.largestRectangleArea(heights);
    cout << "The largest rectangle area in the histogram is: " << maxArea << endl;

    return 0;
}