/*
==========================================================
Problem      : Floor Square Root
Platform     : Coding Ninjas
Problem Link : https://www.naukri.com/code360/problems/square-root_893351
Difficulty   : Easy
Topic        : Binary Search

Approach
----------------------------------------------------------
Use binary search to find the largest integer whose
square is less than or equal to n.

Instead of checking mid * mid <= n, use mid <= n / mid
to avoid integer overflow.

Whenever mid satisfies the condition, store it as a
possible answer and search for a larger value on the
right.

Time Complexity : O(log n)

Space Complexity : O(1)

Date Solved : 01-09-2026
==========================================================
*/

#include <algorithm>

using namespace std;

class Solution {
public:
    int floorSqrt(int n) {

        if (n == 1 || n == 2 || n == 3) {
            return 1;
        }

        int low = 1;
        int high = n / 2;
        int ans = 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (mid <= n / mid) {
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