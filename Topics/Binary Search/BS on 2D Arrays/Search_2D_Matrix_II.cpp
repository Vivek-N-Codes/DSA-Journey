/*
==========================================================
Problem      : Search a 2D Matrix II
Platform     : LeetCode
Problem Link : https://leetcode.com/problems/search-a-2d-matrix-ii/
Difficulty   : Medium
Topic        : Binary Search

Approach
----------------------------------------------------------
Start from the top-right corner.

If the current element is greater than target, move left.
If the current element is smaller than target, move down.

Each movement eliminates an entire row or column.

Time Complexity : O(n + m)
Space Complexity : O(1)

Date Solved :

==========================================================
*/

#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int i = 0;
        int j = m - 1;

        while(i < n && j >= 0) {
            if(matrix[i][j] == target) return true;
            else if(matrix[i][j] > target) j--;
            else i++;
        }

        return false;
    }
};