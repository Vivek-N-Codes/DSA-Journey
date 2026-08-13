/*
==========================================================
Problem      : Merge Intervals
Platform     : LeetCode
Problem Link : https://leetcode.com/problems/merge-intervals/
Difficulty   : Medium
Topic        : Arrays

Approach
----------------------------------------------------------
Sort the intervals by their starting points. Maintain the
last interval in the answer and compare it with each
current interval. If they overlap, merge them by updating
the ending point to the maximum of both ending points.
Otherwise, add the current interval to the answer.

Time Complexity : O(n log n)

Space Complexity : O(n) (excluding the sorting space)

Date Solved : 13-08-2026
==========================================================
*/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        int n = intervals.size();

        if (intervals.empty()) {
            return {};
        }

        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end());

        ans.push_back(intervals[0]);

        for (int i = 0; i < n; i++) {

            if (ans.back()[1] >= intervals[i][0]) {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
            else {
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};