/*
==========================================================
Problem      : Majority Element
Platform     : LeetCode
Problem Link : https://leetcode.com/problems/majority-element/
Difficulty   : Easy
Topic        : Arrays

Approach
----------------------------------------------------------
Use the Boyer-Moore Voting Algorithm. Maintain a
candidate and its frequency. Whenever the frequency
becomes zero, choose the current element as the new
candidate. Matching elements increase the count while
different elements decrease it. Since the majority
element appears more than n/2 times, it remains as the
final candidate.

Time Complexity : O(n)

Space Complexity : O(1)

Date Solved : 25-07-2026
==========================================================
*/

#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int ans = -1;
        int freq = 0;

        for (int i = 0; i < nums.size(); i++) {

            if (freq == 0) {
                ans = nums[i];
            }

            if (nums[i] == ans) {
                freq++;
            }
            else {
                freq--;
            }
        }

        return ans;
    }
};