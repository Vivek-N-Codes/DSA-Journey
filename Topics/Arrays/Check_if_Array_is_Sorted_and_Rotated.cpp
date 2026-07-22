/*
==========================================================
Problem      : Check if Array Is Sorted and Rotated
Platform     : LeetCode
Problem Link : https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
Difficulty   : Easy
Topic        : Arrays

Approach
----------------------------------------------------------
Traverse the array once and count the number of positions
where the current element is greater than the next element.
The last element is compared with the first using modulo
indexing to handle the circular nature of the rotated array.

A sorted and rotated array can have at most one such
inversion (drop).

Time Complexity : O(n)

Space Complexity : O(1)

Date Solved : 22-07-2026
==========================================================
*/

#include <vector>

using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }
        }

        return count <= 1;
    }
};