/*
==========================================================
Problem      : Merge Sorted Array
Platform     : LeetCode
Problem Link : https://leetcode.com/problems/merge-sorted-array/
Difficulty   : Easy
Topic        : Arrays

Approach
----------------------------------------------------------
Use three pointers starting from the end of both sorted
arrays. Compare the largest remaining elements and place
the larger one at the end of nums1. Continue until all
elements of nums2 have been placed.

Traversing from the end allows the elements to be merged
in-place without overwriting the existing elements of
nums1.

Time Complexity : O(m + n)

Space Complexity : O(1)

Date Solved : 14-08-2026
==========================================================
*/

#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (i >= 0 && j >= 0) {

            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            }
            else {
                nums1[k] = nums2[j];
                j--;
            }

            k--;
        }

        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};