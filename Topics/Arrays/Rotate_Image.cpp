/*
==========================================================
Problem      : Rotate Image
Platform     : LeetCode
Problem Link : https://leetcode.com/problems/rotate-image/
Difficulty   : Medium
Topic        : Arrays

Approach
----------------------------------------------------------
Transpose the square matrix by swapping elements across
its main diagonal. Then reverse every row of the
transposed matrix to obtain a 90-degree clockwise
rotation in-place.

Time Complexity : O(n²)

Space Complexity : O(1)

Date Solved : 04-08-2026
==========================================================
*/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};