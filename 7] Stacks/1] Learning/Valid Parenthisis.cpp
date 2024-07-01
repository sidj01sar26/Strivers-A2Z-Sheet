// https://leetcode.com/problems/valid-parentheses/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st; // Stack to store opening brackets

        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i]; // Current character

            // Check if current character is an opening bracket
            if (ch == '(' || ch == '{' || ch == '[')
            {
                st.push(ch); // Push opening bracket to stack
            }
            else
            {
                // Current character is a closing bracket
                if (!st.empty())
                {
                    char topCh = st.top(); // Top character in stack
                    // Check for matching brackets
                    if ((ch == ')' && topCh == '(') ||
                        (ch == '}' && topCh == '{') ||
                        (ch == ']' && topCh == '['))
                    {
                        st.pop(); // Pop the matching opening bracket from stack
                    }
                    else
                    {
                        // Brackets do not match
                        return false;
                    }
                }
                else
                {
                    // No matching opening bracket
                    return false;
                }
            }
        }

        // Stack should be empty if all brackets are matched
        return st.empty();
    }
};