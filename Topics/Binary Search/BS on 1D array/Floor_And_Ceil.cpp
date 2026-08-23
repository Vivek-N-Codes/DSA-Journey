/*
==========================================================
Problem      : Floor and Ceil in Sorted Array
Platform     : GeeksforGeeks
Problem Link : https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1
Difficulty   : Easy
Topic        : Binary Search

Approach
----------------------------------------------------------
Use binary search to find the floor and ceil of x.

The floor is the largest element less than or equal to x.
Whenever nums[mid] <= x, store it as a possible answer
and search to the right for a larger valid value.

The ceil is the smallest element greater than or equal
to x. Whenever nums[mid] >= x, store it as a possible
answer and search to the left for a smaller valid value.

Time Complexity : O(log n)

Space Complexity : O(1)

Date Solved : 23-08-2026
==========================================================
*/

#include <vector>

using namespace std;

class Solution {
public:
    int floor(vector<int>& nums, int x) {

        int low = 0;
        int high = nums.size() - 1;
        int mid;
        int ans = -1;

        while (low <= high) {

            mid = low + (high - low) / 2;

            if (nums[mid] <= x) {
                ans = nums[mid];
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }

    int ceil(vector<int>& nums, int x) {

        int low = 0;
        int high = nums.size() - 1;
        int mid;
        int ans = -1;

        while (low <= high) {

            mid = low + (high - low) / 2;

            if (nums[mid] >= x) {
                ans = nums[mid];
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }

    vector<int> getFloorAndCeil(vector<int> nums, int x) {
        return {floor(nums, x), ceil(nums, x)};
    }
};