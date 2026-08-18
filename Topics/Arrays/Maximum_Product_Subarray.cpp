/*
==========================================================
Problem      : Maximum Product Subarray
Platform     : LeetCode
Problem Link : https://leetcode.com/problems/maximum-product-subarray/
Difficulty   : Medium
Topic        : Arrays

Approach
----------------------------------------------------------
Maintain the maximum and minimum product ending at the
current index. The minimum is also required because a
negative number can turn a minimum product into the
maximum product.

If the current number is negative, swap the maximum and
minimum products before updating them. At every index,
choose either the current element itself or its product
with the previous maximum/minimum.

Time Complexity : O(n)

Space Complexity : O(1)

Date Solved : 18-08-2026
==========================================================
*/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int maxEnding = nums[0];
        int minEnding = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {

            if (nums[i] < 0) {
                swap(maxEnding, minEnding);
            }

            maxEnding = max(nums[i], nums[i] * maxEnding);
            minEnding = min(nums[i], nums[i] * minEnding);

            ans = max(ans, maxEnding);
        }

        return ans;
    }
};