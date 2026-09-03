/*
==========================================================
Problem      : Koko Eating Bananas
Platform     : LeetCode
Problem Link : https://leetcode.com/problems/koko-eating-bananas/
Difficulty   : Medium
Topic        : Binary Search

Approach
----------------------------------------------------------
Binary Search on Answer.
For each eating speed, calculate the total hours required
using ceiling division. If Koko can finish within h hours,
search for a smaller speed.

Time Complexity : O(n log M)
Space Complexity : O(1)

Date Solved :

==========================================================
*/

class Solution {
public:
    int maxPile(vector<int> &piles) {
        int maxi = INT_MIN;

        for(int i = 0; i < piles.size(); i++) {
            maxi = max(maxi, piles[i]);
        }

        return maxi;
    }

    long long hourly(vector<int> &piles, int mid) {
        long long total_hourly = 0;

        for(int i = 0; i < piles.size(); i++) {
            total_hourly += (piles[i] + mid - 1) / mid;
        }

        return total_hourly;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = maxPile(piles);

        while(low <= high) {
            int mid = low + (high - low) / 2;
            long long total_hrs = hourly(piles, mid);

            if(total_hrs <= h) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};