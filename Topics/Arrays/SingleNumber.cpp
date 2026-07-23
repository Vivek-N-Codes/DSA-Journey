/*
==========================================================
Problem      : Single Number
Platform     : LeetCode
Problem Link : https://leetcode.com/problems/single-number/
Difficulty   : Easy
Topic        : Arrays

Approach
----------------------------------------------------------
Use the XOR operation to cancel out duplicate elements.
Since x ^ x = 0 and x ^ 0 = x, all paired elements are
eliminated, leaving only the element that appears once.

Time Complexity : O(n)

Space Complexity : O(1)

Date Solved : 23-07-2026
==========================================================
*/

#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;

        for (int i : nums) {
            ans ^= i;
        }

        return ans;
    }
};