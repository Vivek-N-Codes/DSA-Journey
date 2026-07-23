/*
==========================================================
Problem      : Missing Number
Platform     : LeetCode
Problem Link : https://leetcode.com/problems/missing-number/
Difficulty   : Easy
Topic        : Arrays

Approach
----------------------------------------------------------
Calculate the expected sum of all numbers from 0 to n
using the arithmetic sum formula. Then calculate the
actual sum of the elements in the array. The difference
between the expected sum and the actual sum is the
missing number.

Time Complexity : O(n)

Space Complexity : O(1)

Date Solved : 23-07-2026
==========================================================
*/

#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = (n * (n + 1)) / 2;

        int i = 0, count = 0;

        while (i < n) {
            count += nums[i];
            i++;
        }

        return sum - count;
    }
};