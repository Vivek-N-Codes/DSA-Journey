/*
==========================================================
Problem      : Leaders in an Array
Platform     : GeeksforGeeks
Problem Link : https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1
Difficulty   : Easy
Topic        : Arrays

Approach
----------------------------------------------------------
Traverse the array from right to left while maintaining
the maximum element seen so far. The last element is
always a leader. If the current element is greater than
the current leader, update the leader and add it to the
answer. Finally, reverse the answer to restore the
original order.

Time Complexity : O(n)

Space Complexity : O(n)

Date Solved : 01-08-2026
==========================================================
*/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> leaders(vector<int>& nums) {

        int n = nums.size();

        vector<int> ans;

        int leader = nums[n - 1];
        ans.push_back(leader);

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] > leader) {
                leader = nums[i];
                ans.push_back(leader);
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};