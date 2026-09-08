/*
==========================================================
Problem      : Aggressive Cows
Platform     : Coding Ninjas / GeeksforGeeks
Problem Link :
Difficulty   : Medium
Topic        : Binary Search

Approach
----------------------------------------------------------
Sort the stall positions and apply Binary Search on Answer.

For each candidate minimum distance, greedily place cows at
the earliest possible stall. If k cows can be placed, the
distance is feasible and we try for a larger distance.

Time Complexity : O(n log n + n log D)
Space Complexity : O(1)

Date Solved :

==========================================================
*/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool func(vector<int> &nums, int dist, int k) {
        int last = 0;
        int cows = 1;

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] >= (nums[last] + dist)) {
                cows++;
                last = i;

                if(cows == k) return true;
            }
        }

        return false;
    }

    int aggressiveCows(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());

        int low = 0;
        int high = nums.back() - nums.front();
        int ans = 0;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(func(nums, mid, k)) {
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