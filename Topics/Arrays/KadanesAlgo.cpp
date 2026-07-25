/*
==========================================================
Problem      : Maximum Subarray
Platform     : LeetCode
Problem Link : https://leetcode.com/problems/maximum-subarray/
Difficulty   : Medium
Topic        : Arrays

Approach
----------------------------------------------------------
Use Kadane's Algorithm. Maintain a running sum while
traversing the array. Update the maximum subarray sum
whenever the running sum becomes larger. If the running
sum becomes negative, reset it to zero since a negative
prefix cannot contribute to a larger future subarray.

Time Complexity : O(n)

Space Complexity : O(1)

Date Solved : 25-07-2026
==========================================================
*/

#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int maxSum = INT_MIN;
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {

            sum += nums[i];

            if (sum > maxSum) {
                maxSum = sum;
            }

            if (sum < 0) {
                sum = 0;
            }
        }

        return maxSum;
    }
};