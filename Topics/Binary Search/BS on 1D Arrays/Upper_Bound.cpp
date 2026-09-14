/*
==========================================================
Problem      : Upper Bound
Platform     : Coding Ninjas
Problem Link : https://www.naukri.com/code360/problems/implement-upper-bound_8165383
Difficulty   : Easy
Topic        : Binary Search

Approach
----------------------------------------------------------
Use binary search to find the first index whose value is
strictly greater than x.

Whenever nums[mid] > x, store mid as a possible answer
and continue searching in the left half for a smaller
valid index. If nums[mid] <= x, search the right half.

Initialize the answer to n so that if no element is
greater than x, the function returns n.

Time Complexity : O(log n)

Space Complexity : O(1)

Date Solved : 21-08-2026
==========================================================
*/

#include <vector>

using namespace std;

class Solution {
public:
    int upperBound(vector<int>& nums, int x) {

        int low = 0;
        int high = nums.size() - 1;
        int mid;
        int ans = high + 1;

        while (low <= high) {

            mid = low + (high - low) / 2;

            if (nums[mid] > x) {
                ans = mid;

                // Look for a smaller valid index on the left.
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};