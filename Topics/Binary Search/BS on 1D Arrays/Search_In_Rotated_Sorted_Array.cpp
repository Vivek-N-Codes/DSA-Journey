/*
==========================================================
Problem      : Search in Rotated Sorted Array
Platform     : LeetCode
Problem Link : https://leetcode.com/problems/search-in-rotated-sorted-array/
Difficulty   : Medium
Topic        : Binary Search

Approach
----------------------------------------------------------
Use binary search while identifying which half of the
rotated sorted array is currently sorted.

If the left half is sorted, check whether the target lies
within its range. If it does, search the left half;
otherwise, search the right half.

If the right half is sorted, perform the same logic for
the right half.

Time Complexity : O(log n)

Space Complexity : O(1)

Date Solved : 25-08-2026
==========================================================
*/

#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            if (nums[low] <= nums[mid]) {

                if (nums[low] <= target && target <= nums[mid]) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            else {

                if (nums[mid] <= target && target <= nums[high]) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};