/*
==========================================================
Problem      : Kth Missing Positive Number
Platform     : LeetCode
Problem Link : https://leetcode.com/problems/kth-missing-positive-number/
Difficulty   : Easy
Topic        : Binary Search

Approach
----------------------------------------------------------
Binary Search for the first index where the number of
missing positive integers becomes at least k.

For index i, the number of missing elements before arr[i]
is arr[i] - i - 1.

Time Complexity : O(log n)
Space Complexity : O(1)

Date Solved :

==========================================================
*/

#include <vector>

using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0;
        int high = arr.size() - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            int missing = arr[mid] - mid - 1;

            if(missing < k) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return low + k;
    }
};