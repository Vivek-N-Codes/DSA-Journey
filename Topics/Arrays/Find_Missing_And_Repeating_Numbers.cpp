/*
==========================================================
Problem      : Find Missing and Repeating Numbers
Platform     : Coding Ninjas
Problem Link : https://www.naukri.com/code360/problems/find-missing-and-repeating-numbers_6826249
Difficulty   : Medium
Topic        : Arrays

Approach
----------------------------------------------------------
Use the mathematical equations for the sum and sum of
squares of the first n natural numbers.

Let x be the repeating number and y be the missing number.

S - Sn = x - y

S2 - S2n = x² - y²
          = (x - y)(x + y)

Using these two equations, calculate x + y and then
derive the repeating and missing numbers.

Use long long to safely handle large sums and squared
values.

Time Complexity : O(n)

Space Complexity : O(1)

Date Solved : 15-08-2026
==========================================================
*/

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {

        long long n = nums.size();

        long long Sn = (n * (n + 1)) / 2;
        long long S2n = (n * (n + 1) * (2 * n + 1)) / 6;

        long long S = 0;
        long long S2 = 0;

        for (int i = 0; i < n; i++) {
            S += nums[i];
            S2 += (long long)nums[i] * (long long)nums[i];
        }

        long long val1 = S - Sn;
        long long val2 = S2 - S2n;

        val2 = val2 / val1;

        long long x = (val1 + val2) / 2;
        long long y = x - val1;

        return {(int)x, (int)y};
    }
};