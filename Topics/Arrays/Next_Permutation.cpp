/*
==========================================================
Problem      : Next Permutation
Platform     : LeetCode
Problem Link : https://leetcode.com/problems/next-permutation/
Difficulty   : Medium
Topic        : Arrays

Approach
----------------------------------------------------------
Traverse the array from right to left to find the first
index where nums[i] < nums[i + 1]. This is the breakpoint.
If no such index exists, reverse the entire array since
it is the last permutation. Otherwise, find the smallest
element greater than nums[idx] from the right, swap them,
and reverse the suffix to obtain the next permutation.

Time Complexity : O(n)

Space Complexity : O(1)

Date Solved : 30-07-2026
==========================================================
*/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n = nums.size();
        int idx = -1;

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                idx = i;
                break;
            }
        }

        if (idx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        for (int i = n - 1; i > idx; i--) {
            if (nums[i] > nums[idx]) {
                swap(nums[i], nums[idx]);
                break;
            }
        }

        reverse(nums.begin() + idx + 1, nums.end());
    }
};