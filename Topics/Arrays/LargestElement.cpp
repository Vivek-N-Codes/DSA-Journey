/*
==========================================================
Problem      : Largest Element in an Array
Platform     : LeetCode
Problem No.  : N/A (LeetCode Study Plan)
Difficulty   : Easy

Topic         : Arrays

Approach
----------------------------------------------------------
Traverse the array once while maintaining the maximum
element encountered so far.

If the current element is greater than the current maximum,
update the answer.

Time Complexity : O(n)

Space Complexity: O(1)

Date Solved     : 20-07-2026
==========================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestElement(vector<int>& nums) {

        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {

            if (nums[i] > ans) {
                ans = nums[i];
            }

        }

        return ans;
    }
};