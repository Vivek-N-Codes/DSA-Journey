/*
==========================================================
Problem      : Find First and Last Position of Element
Platform     : LeetCode
Problem Link : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
Difficulty   : Medium
Topic        : Binary Search

Approach
----------------------------------------------------------
Use binary search twice to find the first and last
occurrence of the target.

For the first occurrence, whenever the target is found,
store its index and continue searching in the left half.

For the last occurrence, whenever the target is found,
store its index and continue searching in the right half.

Time Complexity : O(log n)

Space Complexity : O(1)

Date Solved : 24-08-2026
==========================================================
*/

#include <vector>

using namespace std;

class Solution {
public:
    int FirstOccurrence(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;
        int mid;
        int ans = -1;

        while (low <= high) {

            mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                ans = mid;
                high = mid - 1;
            }
            else if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }

    int LastOccurrence(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;
        int mid;
        int ans = -1;

        while (low <= high) {

            mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                ans = mid;
                low = mid + 1;
            }
            else if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {

        int first = FirstOccurrence(nums, target);

        if (first == -1) {
            return {-1, -1};
        }

        int last = LastOccurrence(nums, target);

        return {first, last};
    }
};