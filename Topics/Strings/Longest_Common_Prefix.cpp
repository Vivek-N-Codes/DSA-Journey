/*
==========================================================
Problem      : Longest Common Prefix
Platform     : LeetCode
Problem Link : https://leetcode.com/problems/longest-common-prefix/
Difficulty   : Easy
Topic        : Strings

Approach
----------------------------------------------------------
Sort the strings lexicographically. The longest common
prefix of all strings must also be the common prefix of
the lexicographically smallest and largest strings.

Compare these two strings character by character.

Time Complexity : O(n log n * L)
Space Complexity : O(1)

Date Solved :

==========================================================
*/

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());

        string first = strs.front();
        string last = strs.back();

        int i = 0;

        while(i < first.size() && i < last.size() && first[i] == last[i]) {
            i++;
        }

        return first.substr(0, i);
    }
};