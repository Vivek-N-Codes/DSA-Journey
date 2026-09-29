/*
==========================================================
Problem      : Find the Index of the First Occurrence in a String
Platform     : LeetCode
Problem Link : https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
Difficulty   : Easy
Topic        : Strings

Approach
----------------------------------------------------------
Try every possible starting position in haystack and compare
the characters of needle one by one.

Return the first position where the complete needle matches.

Time Complexity : O(n * m)
Space Complexity : O(1)

Date Solved :

==========================================================
*/

#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        if(m > n) return -1;

        for(int i = 0; i <= n - m; i++) {
            int j = 0;

            while(j < m && haystack[i + j] == needle[j]) {
                j++;
            }

            if(j == m) return i;
        }

        return -1;
    }
};
