/*
==========================================================
Problem      : Find Peak Element
Platform     : LeetCode
Problem Link : https://leetcode.com/problems/find-peak-element/
Difficulty   : Medium
Topic        : Binary Search

Approach
----------------------------------------------------------
Use binary search to find a peak element. First handle
the boundary elements separately.

For the middle element, if it is greater than both
neighbors, it is a peak. If nums[mid] < nums[mid + 1],
a peak must exist on the right side. Otherwise, a peak
exists on the left side.

Continue reducing the search space until a peak is found.

Time Complexity : O(log n)

Space Complexity : O(1)

Date Solved : 31-08-2026
==========================================================
*/

#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int n = nums.size();

        if (n == 1) {
            return 0;
        }

        if (nums[0] > nums[1]) {
            return 0;
        }

        if (nums[n - 1] > nums[n - 2]) {
            return n - 1;
        }

        int low = 1;
        int high = n - 2;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[mid - 1] &&
                nums[mid] > nums[mid + 1]) {
                return mid;
            }
            else if (nums[mid] < nums[mid + 1]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return -1;
    }
};