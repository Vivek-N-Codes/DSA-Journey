/*
==========================================================
Problem      : Find K Rotation
Platform     : Coding Ninjas
Problem Link : https://www.naukri.com/code360/problems/rotation_7449070
Difficulty   : Easy
Topic        : Binary Search

Approach
----------------------------------------------------------
Use binary search to find the minimum element in the
rotated sorted array.

The index of the minimum element represents the number
of times the sorted array has been rotated.

If the left half is sorted, nums[low] is a candidate for
the minimum. Otherwise, nums[mid] is a candidate.

Store the index whenever a smaller minimum is found and
continue searching the remaining portion.

Time Complexity : O(log n)

Space Complexity : O(1)

Date Solved : 29-08-2026
==========================================================
*/

#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    int findKRotation(vector<int>& nums) {

        int low = 0;
        int high = nums.size() - 1;
        int ans = INT_MAX;
        int idx = 0;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (nums[low] <= nums[mid]) {

                if (nums[low] <= ans) {
                    ans = nums[low];
                    idx = low;
                }

                low = mid + 1;
            }
            else {

                if (nums[mid] <= ans) {
                    ans = nums[mid];
                    idx = mid;
                }

                high = mid - 1;
            }
        }

        return idx;
    }
};