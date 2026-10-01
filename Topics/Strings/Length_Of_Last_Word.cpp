/*
==========================================================
Problem      : Length of Last Word
Platform     : LeetCode
Problem Link : https://leetcode.com/problems/length-of-last-word/
Difficulty   : Easy
Topic        : Strings

Approach
----------------------------------------------------------
Traverse the string from the end.

First skip all trailing spaces, then count characters
until the next space is encountered.

Time Complexity : O(n)
Space Complexity : O(1)

Date Solved :

==========================================================
*/

#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        int len = 0;

        while(i >= 0 && s[i] == ' ') i--;

        while(i >= 0 && s[i] != ' ') {
            len++;
            i--;
        }

        return len;
    }
};