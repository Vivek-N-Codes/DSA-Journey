/*
==========================================================
Problem      : Rotate Array
Platform     : LeetCode
Problem Link : https://leetcode.com/problems/rotate-array/
Difficulty   : Medium
Topic        : Arrays

Approach
----------------------------------------------------------
Reverse the entire array first. Then reverse the first
k elements followed by the remaining elements. This
results in the array being rotated to the right by
k positions.

Time Complexity : O(n)

Space Complexity : O(1)

Date Solved : 22-07-2026
==========================================================
*/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty()) {
            return;
        }

        int n = nums.size();
        k = k % n;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};