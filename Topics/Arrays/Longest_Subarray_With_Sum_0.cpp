/*
==========================================================
Problem      : Longest Subarray With Sum 0
Platform     : GeeksforGeeks
Problem Link : https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
Difficulty   : Medium
Topic        : Arrays

Approach
----------------------------------------------------------
Maintain a running prefix sum while traversing the array.
If the prefix sum becomes zero, the subarray from the
beginning to the current index has sum zero.

If the same prefix sum has appeared before, the elements
between the previous occurrence and the current index
have sum zero. Store only the first occurrence of each
prefix sum to obtain the maximum possible length.

Time Complexity : O(n)

Space Complexity : O(n)

Date Solved : 11-08-2026
==========================================================
*/

#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int maxLen(vector<int>& arr) {
        unordered_map<int, int> mp;
        int maxi = 0;
        int sum = 0;

        if (arr.size() == 0) {
            return 0;
        }

        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];

            if (sum == 0) {
                maxi = max(maxi, i + 1);
            }
            else {
                if (mp.find(sum) != mp.end()) {
                    maxi = max(maxi, i - mp[sum]);
                }
                else {
                    mp[sum] = i;
                }
            }
        }

        return maxi;
    }
};