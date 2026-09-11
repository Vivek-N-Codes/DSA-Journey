/*
==========================================================
Problem      : Painter's Partition Problem
Platform     : InterviewBit
Problem Link :
Difficulty   : Hard
Topic        : Binary Search

Approach
----------------------------------------------------------
Binary Search on Answer.
For each candidate maximum painting time, greedily assign
consecutive boards to each painter without exceeding the
candidate limit.

Time Complexity : O(n log S)
Space Complexity : O(1)

Date Solved :

==========================================================
*/

#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPossible(vector<int> &nums, long long mid, int A, int B) {
        int painter = 1;
        long long time = 0;

        for(int x : nums) {
            if(1LL * x * B > mid) return false;

            if(time + (1LL * x * B) > mid) {
                painter++;
                time = 1LL * x * B;
            }
            else {
                time += 1LL * x * B;
            }
        }

        return painter <= A;
    }

    int paint(int A, int B, vector<int>& C) {
        long long low = 1LL * (*max_element(C.begin(), C.end())) * B;
        long long high = accumulate(C.begin(), C.end(), 0LL) * B;
        long long ans = -1;

        while(low <= high) {
            long long mid = low + (high - low) / 2;

            if(isPossible(C, mid, A, B)) {
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