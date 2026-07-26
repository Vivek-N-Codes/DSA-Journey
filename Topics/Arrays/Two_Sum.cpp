/*
==========================================================
Problem      : Two Sum
Platform     : LeetCode
Problem Link : https://leetcode.com/problems/two-sum/
Difficulty   : Easy
Topic        : Arrays

Approach
----------------------------------------------------------
Store each element along with its original index in a
vector of pairs. Sort the vector based on element values
and use the two-pointer technique to find the pair whose
sum equals the target. Return the original indices of
the matching pair.

Time Complexity : O(n log n)

Space Complexity : O(n)

Date Solved : 23-07-2026
==========================================================
*/

#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<pair<int, int>> arr;

        for (int i = 0; i < nums.size(); i++) {
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end());

        int n = nums.size();
        int start = 0, end = n - 1;

        while (start < end) {
            int sum = arr[start].first + arr[end].first;

            if (sum == target) {
                return {arr[start].second, arr[end].second};
            }
            else if (sum < target) {
                start++;
            }
            else {
                end--;
            }
        }

        return {};
    }
};