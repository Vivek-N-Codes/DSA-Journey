/*
==========================================================
Problem      : Median of Two Sorted Arrays
Platform     : LeetCode
Problem Link : https://leetcode.com/problems/median-of-two-sorted-arrays/
Difficulty   : Hard
Topic        : Binary Search

Approach
----------------------------------------------------------
Binary Search on the partition of the smaller array.
Find a partition where all elements on the left side are
less than or equal to all elements on the right side.

Time Complexity : O(log(min(n1, n2)))
Space Complexity : O(1)

Date Solved :

==========================================================
*/

#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        if(n2 < n1) return findMedianSortedArrays(nums2, nums1);

        int low = 0;
        int high = n1;

        while(low <= high) {
            int cut1 = low + (high - low) / 2;
            int cut2 = ((n1 + n2 + 1) / 2) - cut1;

            int l1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
            int l2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];

            int r1 = cut1 == n1 ? INT_MAX : nums1[cut1];
            int r2 = cut2 == n2 ? INT_MAX : nums2[cut2];

            if(l1 <= r2 && l2 <= r1) {
                if((n1 + n2) % 2 == 0) {
                    return ((long long)max(l1, l2) + min(r1, r2)) / 2.0;
                }
                else {
                    return max(l1, l2);
                }
            }
            else if(l1 > r2) {
                high = cut1 - 1;
            }
            else {
                low = cut1 + 1;
            }
        }

        return 0.0;
    }
};