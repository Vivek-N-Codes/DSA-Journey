/*
==========================================================
Problem      : 4Sum
Platform     : LeetCode
Problem Link : https://leetcode.com/problems/4sum/
Difficulty   : Medium
Topic        : Arrays

Approach
----------------------------------------------------------
Sort the array and use two nested loops to fix the first
two elements. For the remaining two elements, use the
two-pointer technique to find combinations whose sum
equals the target.

Skip duplicate values for the first two positions and
also skip duplicates while moving the two pointers to
ensure that only unique quadruplets are added.

Use long long for the sum to avoid integer overflow.

Time Complexity : O(n³)

Space Complexity : O(1) (excluding the output)

Date Solved : 10-08-2026
==========================================================
*/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {

            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            for (int j = i + 1; j < n; j++) {

                if (j != (i + 1) && nums[j] == nums[j - 1]) {
                    continue;
                }

                int k = j + 1;
                int l = n - 1;

                while (k < l) {

                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];

                    if (sum == target) {

                        vector<int> temp = {
                            nums[i],
                            nums[j],
                            nums[k],
                            nums[l]
                        };

                        ans.push_back(temp);

                        k++;
                        l--;

                        while (k < l && nums[k] == nums[k - 1]) {
                            k++;
                        }

                        while (k < l && nums[l] == nums[l + 1]) {
                            l--;
                        }
                    }
                    else if (sum < target) {
                        k++;
                    }
                    else {
                        l--;
                    }
                }
            }
        }

        return ans;
    }
};