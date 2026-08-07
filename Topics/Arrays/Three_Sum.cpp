/*
==========================================================
Problem      : 3Sum
Platform     : LeetCode
Problem Link : https://leetcode.com/problems/3sum/
Difficulty   : Medium
Topic        : Arrays

Approach
----------------------------------------------------------
Sort the array and fix one element at a time. For each
fixed element, use the two-pointer technique to find the
remaining two elements whose sum equals the negative of
the fixed element. Skip duplicate values to ensure only
unique triplets are included in the result.

Time Complexity : O(n²)

Space Complexity : O(1) (excluding the output)

Date Solved : 07-08-2026
==========================================================
*/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {

            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int j = i + 1;
            int k = n - 1;

            while (j < k) {

                int sum = nums[i] + nums[j] + nums[k];

                if (sum < 0) {
                    j++;
                }
                else if (sum > 0) {
                    k--;
                }
                else {

                    ans.push_back({nums[i], nums[j], nums[k]});

                    j++;
                    k--;

                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }

                    while (j < k && nums[k] == nums[k + 1]) {
                        k--;
                    }
                }
            }
        }

        return ans;
    }
};