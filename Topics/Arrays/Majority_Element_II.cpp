/*
==========================================================
Problem      : Majority Element II
Platform     : LeetCode
Problem Link : https://leetcode.com/problems/majority-element-ii/
Difficulty   : Medium
Topic        : Arrays

Approach
----------------------------------------------------------
Use the extended Boyer-Moore Voting Algorithm to identify
up to two potential majority candidates. Since there can
be at most two elements occurring more than ⌊n/3⌋ times,
maintain two candidates and their frequencies. Perform a
second traversal to verify their actual frequencies before
adding them to the result.

Time Complexity : O(n)

Space Complexity : O(1)

Date Solved : 06-08-2026
==========================================================
*/

#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int n = nums.size();

        int c1 = 0, c2 = 0;
        int e1 = INT_MIN, e2 = INT_MIN;

        for (int i = 0; i < n; i++) {

            if (c1 == 0 && nums[i] != e2) {
                c1 = 1;
                e1 = nums[i];
            }
            else if (c2 == 0 && nums[i] != e1) {
                c2 = 1;
                e2 = nums[i];
            }
            else if (nums[i] == e1) {
                c1++;
            }
            else if (nums[i] == e2) {
                c2++;
            }
            else {
                c1--;
                c2--;
            }
        }

        vector<int> ls;

        c1 = 0;
        c2 = 0;

        for (int i = 0; i < n; i++) {

            if (nums[i] == e1) {
                c1++;
            }

            if (nums[i] == e2) {
                c2++;
            }
        }

        int mini = (n / 3) + 1;

        if (c1 >= mini) {
            ls.push_back(e1);
        }

        if (c2 >= mini) {
            ls.push_back(e2);
        }

        return ls;
    }
};