/*
==========================================================
Problem      : Search in Rotated Sorted Array II
Platform     : LeetCode
Problem Link : https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
Difficulty   : Medium
Topic        : Binary Search

Approach
----------------------------------------------------------
Use binary search while identifying which half of the
rotated sorted array is currently sorted.

When the elements at low, mid, and high are equal, it is
not possible to determine which half is sorted. In this
case, shrink both boundaries by one.

Otherwise, use the same logic as Search in Rotated Sorted
Array to determine whether the target lies within the
sorted half.

Time Complexity : O(log n) average, O(n) worst case

Space Complexity : O(1)

Date Solved : 27-08-2026
==========================================================
*/

#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return true;
            }

            // The crack of the problem
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
                continue;
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

        return false;
    }
};