/*
==========================================================
Problem      : Allocate Books
Platform     : Coding Ninjas / GeeksforGeeks
Problem Link :
Difficulty   : Medium
Topic        : Binary Search

Approach
----------------------------------------------------------
Binary Search on Answer.
For each candidate maximum number of pages, greedily
allocate consecutive books to each student without
exceeding the candidate limit.

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
    bool isPossible(vector<int> &nums, long long mid, int m) {
        long long pages = 0;
        int student = 1;

        for(int x : nums) {
            if(x > mid) return false;

            if((x + pages) > mid) {
                student++;
                pages = x;
            }
            else {
                pages += x;
            }
        }

        return student <= m;
    }

    int findPages(vector<int> &nums, int m) {
        if(nums.size() < m) return -1;

        long long low = *max_element(nums.begin(), nums.end());
        long long high = accumulate(nums.begin(), nums.end(), 0LL);
        long long ans = -1;

        while(low <= high) {
            long long mid = low + (high - low) / 2;

            if(isPossible(nums, mid, m)) {
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