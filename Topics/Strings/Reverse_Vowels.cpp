/*
==========================================================
Problem      : Reverse Vowels of a String
Platform     : LeetCode
Problem Link : https://leetcode.com/problems/reverse-vowels-of-a-string/
Difficulty   : Easy
Topic        : Strings / Two Pointers

Approach
----------------------------------------------------------
Use two pointers to find vowels from both ends of the
string. Swap the vowels and move both pointers inward.

Time Complexity : O(n)
Space Complexity : O(1)

Date Solved :

==========================================================
*/

#include <cctype>
#include <string>
#include <utility>

using namespace std;

class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);

        return c == 'a' || c == 'e' || c == 'i' ||
               c == 'o' || c == 'u';
    }

    string reverseVowels(string s) {
        int left = 0;
        int right = s.size() - 1;

        while(left < right) {
            while(left < right && !isVowel(s[left])) left++;
            while(left < right && !isVowel(s[right])) right--;

            swap(s[left], s[right]);

            left++;
            right--;
        }

        return s;
    }
};