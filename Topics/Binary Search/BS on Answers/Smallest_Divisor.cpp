/*
==========================================================
Problem      : Find the Smallest Divisor Given a Threshold
Platform     : LeetCode
Problem Link : https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
Difficulty   : Medium
Topic        : Binary Search

Approach
----------------------------------------------------------
Binary Search on Answer.
For each candidate divisor, calculate the sum of the
ceiling divisions. If the sum is within the threshold,
search for a smaller divisor.

Time Complexity : O(n log M)
Space Complexity : O(1)

Date Solved :

==========================================================
*/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int func(vector<int> &nums, int mid) {
        int cnt = 0;

        for(int i = 0; i < nums.size(); i++) {
            cnt += (nums[i] + mid - 1) / mid;
        }

        return cnt;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = -1;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            int count = func(nums, mid);

            if(count <= threshold) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};