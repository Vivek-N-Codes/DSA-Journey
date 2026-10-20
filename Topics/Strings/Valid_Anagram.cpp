/*
==========================================================
Problem      : Valid Anagram
Platform     : LeetCode
Problem Link : https://leetcode.com/problems/valid-anagram/
Difficulty   : Easy
Topic        : Strings

Approach
----------------------------------------------------------
Use a frequency array of size 26. Increment the frequency
of each character in s and decrement the frequency of
each character in t. If all frequencies are zero, the
strings are anagrams.

Time Complexity : O(n)
Space Complexity: O(1)

Date Solved : 20-10-2026

==========================================================
*/

#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int m = s.size();
        int n = t.size();

        if(m != n) return false;

        int freq[26] = {0};

        for(int i = 0; i < m; i++){
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        for(int i = 0; i < 26; i++){
            if(freq[i] != 0) return false;
        }

        return true;
    }
};