/*
==========================================================
Problem      : Sqrt(x)
Platform     : LeetCode
Problem Link : https://leetcode.com/problems/sqrtx/
Difficulty   : Easy
Topic        : Binary Search

Approach
----------------------------------------------------------
Use binary search on the range [0, x] to find the
greatest integer whose square is less than or equal
to x. To avoid integer overflow, compare using
mid <= x / mid instead of mid * mid <= x.

Time Complexity : O(log x)

Space Complexity : O(1)

Date Solved : 31-07-2026
==========================================================
*/


#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {

        if (x == 0 || x == 1) {
            return x;
        }

        int low = 0;
        int high = x;
        int ans = 0;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (mid <= x / mid) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};