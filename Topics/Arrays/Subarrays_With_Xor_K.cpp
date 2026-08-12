/*
==========================================================
Problem      : Subarrays With XOR K
Platform     : Coding Ninjas
Problem Link : https://www.naukri.com/code360/problems/subarrays-with-xor-k_6826258
Difficulty   : Medium
Topic        : Arrays

Approach
----------------------------------------------------------
Maintain a running prefix XOR while traversing the array.
For the current prefix XOR, calculate the XOR value that
must have occurred previously:

required = prefixXOR ^ k

If this required prefix XOR exists in the hash map, each
occurrence represents a subarray whose XOR is k. Store the
frequency of every prefix XOR to count all valid subarrays.

Initialize the map with prefix XOR 0 having frequency 1
to handle subarrays starting from index 0.

Time Complexity : O(n)

Space Complexity : O(n)

Date Solved : 12-08-2026
==========================================================
*/

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int subarraysWithXorK(vector<int>& nums, int k) {

        int n = nums.size();
        unordered_map<int, int> mp;

        mp[0] = 1;

        int cnt = 0;
        int prexor = 0;

        for (int i = 0; i < n; i++) {

            prexor ^= nums[i];

            int x = prexor ^ k;

            if (mp.find(x) != mp.end()) {
                cnt += mp[x];
            }

            mp[prexor] += 1;
        }

        return cnt;
    }
};