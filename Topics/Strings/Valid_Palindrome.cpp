/*
==========================================================
Problem      : Valid Palindrome
Platform     : LeetCode
Problem Link : https://leetcode.com/problems/valid-palindrome/
Difficulty   : Easy
Topic        : Strings / Two Pointers

Approach
----------------------------------------------------------
Use two pointers from both ends of the string.

Skip non-alphanumeric characters and compare the remaining
characters case-insensitively.

If any pair doesn't match, the string is not a palindrome.

Time Complexity : O(n)
Space Complexity : O(1)

Date Solved :

==========================================================
*/

#include <cctype>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while(left < right) {
            while(left < right && !isalnum(s[left])) left++;
            while(left < right && !isalnum(s[right])) right--;

            if(tolower(s[left]) != tolower(s[right])) return false;

            left++;
            right--;
        }

        return true;
    }
};