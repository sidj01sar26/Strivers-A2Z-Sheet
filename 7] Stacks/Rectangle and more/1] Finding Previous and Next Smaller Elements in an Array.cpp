#include <iostream>
#include <vector>
#include <stack>
using namespace std;

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
        while (s.top() >= curr)
        {
            s.pop();
        }

        // Store the previous smaller element
        ans[i] = s.top();

        // Push the current element onto the stack
        s.push(curr);
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
        while (s.top() >= curr)
        {
            s.pop();
        }

        // Store the next smaller element
        ans[i] = s.top();

        // Push the current element onto the stack
        s.push(curr);
    }
    return ans;
}

int main()
{
    vector<int> input = {2, 1, 4, 3};

    // Find the next smaller elements
    vector<int> ans1 = nextSmaller(input);
    cout << "Next smaller elements: ";
    for (int i = 0; i < input.size(); i++)
    {
        cout << ans1[i] << " ";
    }
    cout << endl;

    // Find the previous smaller elements
    vector<int> ans2 = prevSmallerElement(input);
    cout << "Previous smaller elements: ";
    for (int i = 0; i < input.size(); i++)
    {
        cout << ans2[i] << " ";
    }
    cout << endl;

    return 0;
}