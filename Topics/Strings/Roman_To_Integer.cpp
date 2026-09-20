/*
==========================================================
Problem      : Roman to Integer
Platform     : LeetCode
Problem Link : https://leetcode.com/problems/roman-to-integer/
Difficulty   : Easy
Topic        : Hashing

Approach
----------------------------------------------------------
Store the value of each Roman numeral in a lookup table.
Traverse the string from right to left.

If the current numeral is smaller than the previous numeral,
subtract it; otherwise add it.

Time Complexity : O(n)
Space Complexity : O(1)

Date Solved :

==========================================================
*/

#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int arr[128] = {};

        arr['I'] = 1;
        arr['V'] = 5;
        arr['X'] = 10;
        arr['L'] = 50;
        arr['C'] = 100;
        arr['D'] = 500;
        arr['M'] = 1000;

        int ans = 0;
        int prev = 0;

        for(int i = s.size() - 1; i >= 0; i--) {
            if(arr[s[i]] < prev) {
                ans -= arr[s[i]];
            }
            else {
                ans += arr[s[i]];
                prev = arr[s[i]];
            }
        }

        return ans;
    }
};