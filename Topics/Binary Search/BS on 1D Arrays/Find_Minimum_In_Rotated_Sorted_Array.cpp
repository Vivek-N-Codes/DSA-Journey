/*
==========================================================
Problem      : Find Minimum in Rotated Sorted Array
Platform     : LeetCode
Problem Link : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
Difficulty   : Medium
Topic        : Binary Search

Approach
----------------------------------------------------------
Use binary search and identify the sorted half of the
rotated array.

If the left half is sorted, nums[low] is the smallest
element in that half. Store it as a possible answer and
search the right half.

Otherwise, the minimum lies in the left half including
nums[mid]. Store nums[mid] as a possible answer and
continue searching in the left half.

Time Complexity : O(log n)

Space Complexity : O(1)

Date Solved : 28-08-2026
==========================================================
*/

#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {

        int low = 0;
        int high = nums.size() - 1;
        int ans = INT_MAX;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (nums[low] <= nums[mid]) {
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
            else {
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }

        return ans;
    }
};