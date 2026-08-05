/*
==========================================================
Problem      : Subarray Sum Equals K
Platform     : LeetCode
Problem Link : https://leetcode.com/problems/subarray-sum-equals-k/
Difficulty   : Medium
Topic        : Arrays

Approach
----------------------------------------------------------
Maintain a running prefix sum while traversing the array.
For each prefix sum, compute (prefixSum - k). If this
value has appeared before, then each occurrence represents
a valid subarray with sum k. Store the frequency of every
prefix sum in a hash map to count all such subarrays.

Time Complexity : O(n)

Space Complexity : O(n)

Date Solved : 05-08-2026
==========================================================
*/

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> mp;
        mp[0] = 1;

        int presum = 0;
        int cnt = 0;

        for (int i = 0; i < nums.size(); i++) {

            presum += nums[i];

            int remove = presum - k;

            cnt += mp[remove];

            mp[presum] += 1;
        }

        return cnt;
    }
};