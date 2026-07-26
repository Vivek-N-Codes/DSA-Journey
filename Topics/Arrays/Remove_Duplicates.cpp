/*
==========================================================
Problem      : Remove Duplicates from Sorted Array
Platform     : LeetCode
Problem Link : https://leetcode.com/problems/remove-duplicates-from-sorted-array/
Difficulty   : Easy
Topic        : Arrays, Two Pointers

Approach
----------------------------------------------------------
Use two pointers to overwrite duplicate elements.

Pointer 'i' keeps track of the last unique element,
while pointer 'j' traverses the array. Whenever a new
unique element is found, place it at index 'i + 1'
and increment 'i'.

The first (i + 1) elements of the array will contain
all unique elements in sorted order.

Time Complexity : O(n)
Space Complexity: O(1)

Date Solved : 22-07-2026
==========================================================
*/

#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int i = 0;

        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {
                nums[i + 1] = nums[j];
                i++;
            }
        }

        return i + 1;
    }
};