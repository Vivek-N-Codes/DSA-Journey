/*
==========================================================
Problem      : Set Matrix Zeroes
Platform     : LeetCode
Problem Link : https://leetcode.com/problems/set-matrix-zeroes/
Difficulty   : Medium
Topic        : Arrays

Approach
----------------------------------------------------------
Use the first row and first column of the matrix as marker
arrays to record which rows and columns should be set to
zero. Since matrix[0][0] cannot represent both the first
row and first column, use an additional variable (col0)
to track the state of the first column. After marking,
update the remaining cells and finally process the first
row and first column separately.

Time Complexity : O(m × n)

Space Complexity : O(1)

Date Solved : 03-08-2026
==========================================================
*/

#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        int col0 = 1;

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                if (matrix[i][j] == 0) {

                    matrix[i][0] = 0;

                    if (j != 0) {
                        matrix[0][j] = 0;
                    }
                    else {
                        col0 = 0;
                    }
                }
            }
        }

        for (int i = 1; i < m; i++) {

            for (int j = 1; j < n; j++) {

                if (matrix[i][j] != 0) {

                    if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                        matrix[i][j] = 0;
                    }
                }
            }
        }

        if (matrix[0][0] == 0) {

            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }

        if (col0 == 0) {

            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};