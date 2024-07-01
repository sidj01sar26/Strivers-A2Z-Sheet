// https://www.naukri.com/code360/problems/redundant-brackets_975473

#include <bits/stdc++.h>
using namespace std;

// Function to check if there are any redundant brackets in the expression
bool findRedundantBrackets(string &s)
{
    stack<char> st; // Stack to keep track of characters

    for (int i = 0; i < s.length(); i++)
    { // Traverse each character in the string
        char ch = s[i];
        if (ch == ')')
        { // If current character is a closing bracket
            char top = st.top();
            st.pop();
            bool flag = true;

            // Check characters inside the brackets
            while (!st.empty() && top != '(')
            {
                if (top == '+' || top == '-' || top == '*' || top == '/')
                {
                    flag = false; // Found an operator, so brackets are not redundant
                }
                top = st.top();
                st.pop();
            }

            if (flag) // If no operator found, brackets are redundant
                return true;
        }
        else
        {
            st.push(ch); // Push other characters to stack
        }
    }
    return false; // No redundant brackets found
}

// or

#include <bits/stdc++.h>

// Function to check if there are any redundant brackets in the expression
bool findRedundantBrackets(string &s)
{
    // If the string is empty, no redundant brackets can be present
    if (s.size() == 0)
    {
        return false;
    }

    stack<char> st; // Stack to keep track of characters

    // Traverse each character in the string
    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];

        // Push opening brackets and operators onto the stack
        if (c == '(' || c == '+' || c == '-' || c == '/' || c == '*')
        {
            st.push(c);
        }
        else if (c == ')')
        { 
            // When a closing bracket is encountered
            // If the stack is empty or the top is an opening bracket, it's redundant
            if (st.empty() || st.top() == '(')
            {
                return true;
            }

            // Pop elements until an opening bracket is found
            while (!st.empty() && st.top() != '(')
            {
                st.pop();
            }
            st.pop(); // Pop the opening bracket
        }
    }

    // No redundant brackets found
    return false;
}