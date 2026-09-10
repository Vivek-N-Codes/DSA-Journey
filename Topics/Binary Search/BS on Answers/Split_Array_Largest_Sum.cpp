/*
==========================================================
Problem      : Split Array Largest Sum
Platform     : LeetCode
Problem Link : https://leetcode.com/problems/split-array-largest-sum/
Difficulty   : Hard
Topic        : Binary Search

Approach
----------------------------------------------------------
Binary Search on Answer.
For each candidate maximum subarray sum, greedily split
the array whenever adding the next element would exceed
the candidate limit.

If the array can be split into at most k subarrays, the
candidate is feasible and we search for a smaller answer.

Time Complexity : O(n log S)
Space Complexity : O(1)

Date Solved :

==========================================================
*/

#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    bool isLargest_Possible(vector<int> &nums, long long mid, int k) {
        int total_subarr = 1;
        long long sum = 0;

        for(int x : nums) {
            if(x > mid) return false;

            if(sum + x > mid) {
                total_subarr++;
                sum = x;
            }
            else {
                sum += x;
            }
        }

        return total_subarr <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        long long low = *max_element(nums.begin(), nums.end());
        long long high = accumulate(nums.begin(), nums.end(), 0LL);
        long long ans = -1;

        while(low <= high) {
            long long mid = low + (high - low) / 2;

            if(isLargest_Possible(nums, mid, k)) {
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