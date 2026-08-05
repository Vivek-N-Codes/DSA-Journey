/*
==========================================================
Problem      : Spiral Matrix
Platform     : LeetCode
Problem Link : https://leetcode.com/problems/spiral-matrix/
Difficulty   : Medium
Topic        : Arrays

Approach
----------------------------------------------------------
Maintain four boundaries (top, bottom, left, and right)
representing the current layer of the matrix. Traverse
the boundaries in spiral order while shrinking them after
each traversal. Continue until all elements are visited.

Time Complexity : O(m × n)

Space Complexity : O(m × n)

Date Solved : 05-08-2026
==========================================================
*/

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> ans;

        int top = 0;
        int bottom = m - 1;
        int left = 0;
        int right = n - 1;

        while (top <= bottom && left <= right) {

            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            top++;

            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;

            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            if (top <= bottom && left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return ans;
    }
};