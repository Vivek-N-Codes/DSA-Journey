/*
==========================================================
Problem      : Rearrange Array Elements by Sign
Platform     : LeetCode
Problem Link : https://leetcode.com/problems/rearrange-array-elements-by-sign/
Difficulty   : Medium
Topic        : Arrays

Approach
----------------------------------------------------------
Create a new array of the same size. Maintain two indices:
one for positive numbers at even positions and one for
negative numbers at odd positions. Traverse the array once
and place each element at its respective position.

Time Complexity : O(n)

Space Complexity : O(n)

Date Solved : 29-07-2026
==========================================================
*/

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        int n = nums.size();

        vector<int> ans(n);

        int pos = 0;
        int neg = 1;

        for (int i = 0; i < n; i++) {

            if (nums[i] > 0) {
                ans[pos] = nums[i];
                pos += 2;
            }
            else {
                ans[neg] = nums[i];
                neg += 2;
            }
        }

        return ans;
    }
};