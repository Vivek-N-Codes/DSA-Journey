/*
==========================================================
Problem      : Move Zeroes
Platform     : LeetCode
Problem Link : https://leetcode.com/problems/move-zeroes/
Difficulty   : Easy
Topic        : Arrays, Two Pointers

Approach
----------------------------------------------------------
Maintain a pointer 'j' to track the position where the
next non-zero element should be placed. Traverse the
array using another pointer 'i'. Whenever a non-zero
element is found, swap it with the element at index 'j'
and increment 'j'. This moves all non-zero elements to
the front while preserving their relative order.

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
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        if (n <= 1) {
            return;
        }

        int j = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};