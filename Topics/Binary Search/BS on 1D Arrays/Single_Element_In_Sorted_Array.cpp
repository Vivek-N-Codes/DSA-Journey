/*
==========================================================
Problem      : Single Element in a Sorted Array
Platform     : LeetCode
Problem Link : https://leetcode.com/problems/single-element-in-a-sorted-array/
Difficulty   : Medium
Topic        : Binary Search

Approach
----------------------------------------------------------
Use binary search based on the pairing pattern of the
sorted array. Before the single element, pairs start at
even indices. After the single element, this pairing
pattern shifts.

Check whether the middle element forms a valid pair
according to its index parity. If the pairing is still
correct, search the right half. Otherwise, search the
left half.

Handle the first and last elements separately to avoid
out-of-bounds access when checking mid - 1 and mid + 1.

Time Complexity : O(log n)

Space Complexity : O(1)

Date Solved : 30-08-2026
==========================================================
*/

#include <vector>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int n = nums.size() - 1;

        if (nums.size() == 1) {
            return nums[0];
        }

        if (nums[0] != nums[1]) {
            return nums[0];
        }

        if (nums[n] != nums[n - 1]) {
            return nums[n];
        }

        int low = 1;
        int high = nums.size() - 2;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (nums[mid] != nums[mid - 1] &&
                nums[mid] != nums[mid + 1]) {
                return nums[mid];
            }

            if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) ||
                (mid % 2 == 1 && nums[mid] == nums[mid - 1])) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return -1;
    }
};