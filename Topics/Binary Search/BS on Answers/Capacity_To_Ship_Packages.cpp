/*
==========================================================
Problem      : Capacity To Ship Packages Within D Days
Platform     : LeetCode
Problem Link : https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
Difficulty   : Medium
Topic        : Binary Search

Approach
----------------------------------------------------------
Binary Search on Answer.
The minimum possible capacity is the maximum package
weight, while the maximum possible capacity is the total
weight of all packages.

For each candidate capacity, calculate the number of days
required to ship all packages while maintaining their order.

Time Complexity : O(n log S)
Space Complexity : O(1)

Date Solved :

==========================================================
*/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    long long sum(vector<int> &weights) {
        long long total_weight = 0;

        for(int i = 0; i < weights.size(); i++) {
            total_weight += weights[i];
        }

        return total_weight;
    }

    int func(vector<int> &weights, int mid) {
        int weight = 0;
        int days = 0;

        for(int i = 0; i < weights.size(); i++) {
            weight += weights[i];

            if(weight == mid) {
                days++;
                weight = 0;
            }
            else if(weight > mid) {
                days++;
                weight = weights[i];
            }
        }

        // Count last remaining weight
        if(weight > 0) days++;

        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = (int)(sum(weights));

        if(days == 1) return high;

        int ans = -1;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            int days_taken = func(weights, mid);

            if(days_taken <= days) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};