/*
==========================================================
Problem      : Search a 2D Matrix
Platform     : LeetCode
Problem Link : https://leetcode.com/problems/search-a-2d-matrix/
Difficulty   : Medium
Topic        : Binary Search

Approach
----------------------------------------------------------
Treat the matrix as a sorted 1D array and perform Binary
Search.

Convert a virtual 1D index into a matrix position using:
row = mid / number_of_columns
column = mid % number_of_columns

Time Complexity : O(log(n * m))
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

        int low = 0;
        int high = n * m - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(matrix[mid / m][mid % m] == target) {
                return true;
            }
            else if(matrix[mid / m][mid % m] > target) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return false;
    }
};