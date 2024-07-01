// https://leetcode.com/problems/longest-valid-parentheses/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        stack<int> st; // Stack to store indices of '(' characters
        st.push(-1);   // Push -1 as a base index

        int ans = 0; // Variable to store the length of the longest valid parentheses substring

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                st.push(i); // Push index of '(' onto the stack
            }
            else
            {             // When encountering a ')'
                st.pop(); // Pop the top of the stack

                if (st.empty())
                { // If stack becomes empty, push current index as base
                    st.push(i);
                }
                else
                {
                    // Calculate current valid substring length and update ans
                    ans = max(ans, i - st.top());
                }
            }
        }

        return ans; // Return the longest valid parentheses substring length
    }
};

// or

