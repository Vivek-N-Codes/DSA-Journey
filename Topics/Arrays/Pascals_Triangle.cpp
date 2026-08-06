/*
==========================================================
Problem      : Pascal's Triangle
Platform     : LeetCode
Problem Link : https://leetcode.com/problems/pascals-triangle/
Difficulty   : Easy
Topic        : Arrays

Approach
----------------------------------------------------------
Generate each row using the nCr recurrence relation.
Start every row with 1, then compute each subsequent
element from the previous one using:

next = previous × (row - column) / column

This avoids factorial computations and generates each
row efficiently.

Time Complexity : O(numRows²)

Space Complexity : O(1) (excluding the output)

Date Solved : 06-08-2026
==========================================================
*/

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> func(int n) {

        vector<int> ansRow;

        long long ans = 1;
        ansRow.push_back(ans);

        for (int i = 1; i < n; i++) {
            ans = ans * (n - i);
            ans /= i;
            ansRow.push_back(ans);
        }

        return ansRow;
    }

    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> ans;

        for (int i = 1; i <= numRows; i++) {
            ans.push_back(func(i));
        }

        return ans;
    }
};