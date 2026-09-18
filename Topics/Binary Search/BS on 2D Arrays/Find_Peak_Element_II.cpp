/*
==========================================================
Problem      : Find a Peak Element II
Platform     : LeetCode
Problem Link : https://leetcode.com/problems/find-a-peak-element-ii/
Difficulty   : Medium
Topic        : Binary Search

Approach
----------------------------------------------------------
Binary Search on columns.

For each middle column, find the maximum element in that
column. Since it is the maximum in the column, its upper
and lower neighbors are automatically smaller.

Compare it with the left and right neighbors:
- If both are smaller, we found a peak.
- If left is greater, search the left half.
- Otherwise, search the right half.

Time Complexity : O(n log m)
Space Complexity : O(1)

Date Solved :

==========================================================
*/

#include <vector>

using namespace std;

class Solution {
public:
    int max_element(vector<vector<int>> &mat, int n, int mid) {
        int maxi = -1;
        int idx = -1;

        for(int i = 0; i < n; i++) {
            if(mat[i][mid] > maxi) {
                maxi = mat[i][mid];
                idx = i;
            }
        }

        return idx;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int low = 0;
        int high = m - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            int row = max_element(mat, n, mid);
            int curr = mat[row][mid];

            int left = (mid > 0) ? mat[row][mid - 1] : -1;
            int right = (mid < m - 1) ? mat[row][mid + 1] : -1;

            if(curr > left && curr > right) {
                return {row, mid};
            }
            else if(left > curr) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return {-1, -1};
    }
};