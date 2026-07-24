/*
==========================================================
Problem      : Longest Subarray With Sum K
Platform     : Coding Ninjas
Problem Link : https://www.naukri.com/code360/problems/longest-subarray-with-sum-k_6682399
Difficulty   : Medium
Topic        : Arrays

Approach
----------------------------------------------------------
Traverse the array while maintaining a running prefix sum.
Store the first occurrence of every prefix sum in a hash
map. At each index, check if (current prefix sum - k)
exists in the map. If it does, then a subarray with sum k
exists between those two indices. Update the maximum
length accordingly.

Time Complexity : O(n)

Space Complexity : O(n)

Date Solved : 24-07-2026
==========================================================
*/

#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<long long, int> mp;

        long long sum = 0;
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];

            if (sum == k) {
                maxLen = max(maxLen, i + 1);
            }

            if (mp.find(sum - k) != mp.end()) {
                maxLen = max(maxLen, i - mp[sum - k]);
            }

            // Store only the first occurrence of each prefix sum
            if (mp.find(sum) == mp.end()) {
                mp[sum] = i;
            }
        }

        return maxLen;
    }
};