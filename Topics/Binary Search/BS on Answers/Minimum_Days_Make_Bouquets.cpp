/*
==========================================================
Problem      : Minimum Number of Days to Make m Bouquets
Platform     : LeetCode
Problem Link : https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
Difficulty   : Medium
Topic        : Binary Search

Approach
----------------------------------------------------------
Binary Search on Answer.
For each candidate day, count the maximum number of
bouquets that can be formed using consecutive bloomed
flowers.

Time Complexity : O(n log D)
Space Complexity : O(1)

Date Solved :

==========================================================
*/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int func(vector<int> &arr, int mid, int k) {
        int cnt = 0;
        int i = 0;

        for(int j = 0; j < arr.size(); j++) {
            if(arr[j] > mid) {
                int length = j - i;

                if(length >= k) {
                    cnt += length / k;
                }

                i = j + 1;
            }
        }

        // Count last segment
        cnt += (arr.size() - i) / k;

        return cnt;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m * k > bloomDay.size()) return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            int count = func(bloomDay, mid, k);

            if(count >= m) {
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