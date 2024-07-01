#include <iostream>
#include <vector>
#include <limits.h>
#include <stack>
using namespace std;

// Function to find the previous smaller elements for each element in the input vector
vector<int> prevSmallerElement(vector<int> &input)
{
    stack<int> s;
    s.push(-1);
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

        // Store the previous smaller element index
        ans[i] = s.top();

        // Push the current index onto the stack
        s.push(i);
    }
    return ans;
}

// Function to find the next smaller elements for each element in the input vector
vector<int> nextSmaller(vector<int> &input)
{
    stack<int> s;
    s.push(-1);
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

        // Store the next smaller element index
        ans[i] = s.top();

        // Push the current index onto the stack
        s.push(i);
    }
    return ans;
}

// Function to calculate the largest rectangular area in a histogram
int getRectangularAreaHistogram(vector<int> &height)
{
    // Find previous smaller elements
    vector<int> prev = prevSmallerElement(height);

    // Find next smaller elements
    vector<int> next = nextSmaller(height);

    int maxArea = INT_MIN;
    int size = height.size();

    // Calculate the maximum area for each element
    for (int i = 0; i < height.size(); i++)
    {
        int length = height[i];

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

int main()
{
    vector<int> v = {2, 1, 5, 6, 2, 3};

    // Calculate and print the largest rectangular area
    cout << "Ans is: " << getRectangularAreaHistogram(v) << endl;

    return 0;
}