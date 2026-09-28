/*
==========================================================
Problem      : Valid Parentheses
Platform     : LeetCode
Problem Link : https://leetcode.com/problems/valid-parentheses/
Difficulty   : Easy
Topic        : Stack

Approach
----------------------------------------------------------
Use a stack to store opening brackets.

For every closing bracket, check whether the top of the
stack contains its corresponding opening bracket. If it
matches, remove it; otherwise the string is invalid.

At the end, the stack must be empty.

Time Complexity : O(n)
Space Complexity : O(n)

Date Solved :

==========================================================
*/

#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char ch : s) {
            if(ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }
            else {
                if(st.empty()) return false;

                char top = st.top();

                if(ch == ')' && top != '(' ||
                    ch == '}' && top != '{' ||
                    ch == ']' && top != '[') {
                    return false;
                }

                st.pop();
            }
        }

        return st.empty();
    }
};