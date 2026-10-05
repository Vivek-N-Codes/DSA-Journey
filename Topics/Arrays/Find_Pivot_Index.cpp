/*
==========================================================
Problem      : Find Pivot Index
Platform     : LeetCode
Problem Link : https://leetcode.com/problems/find-pivot-index/
Difficulty   : Easy
Topic        : Arrays / Prefix Sum

Approach
----------------------------------------------------------
Calculate the total sum of the array.

For every index, calculate the right sum using:
right_sum = total_sum - left_sum - nums[i]

If left_sum equals right_sum, the current index is the
pivot index.

Time Complexity : O(n)
Space Complexity : O(1)

Date Solved :

==========================================================
*/

#include <vector>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        long long total_sum = 0;

        for(int i = 0; i < nums.size(); i++) {
            total_sum += nums[i];
        }

        long long left_sum = 0;

        for(int i = 0; i < nums.size(); i++) {
            long long right_sum = total_sum - left_sum - nums[i];

            if(left_sum == right_sum) return i;

            left_sum += nums[i];
        }

        return -1;
    }
};