/*
==========================================================
Problem      : Row With Maximum 1s
Platform     : GeeksforGeeks
Problem Link :
Difficulty   : Medium
Topic        : Binary Search

Approach
----------------------------------------------------------
For each row, use Binary Search to find the first
occurrence of 1. Since each row is sorted, the number
of 1s is equal to the number of columns minus the index
of the first 1.

Track the row having the maximum number of 1s.

Time Complexity : O(r log c)
Space Complexity : O(1)

Date Solved :

==========================================================
*/

#include <vector>

using namespace std;

class Solution {
public:
    int first_occurence(vector<int> &nums, int n, int x) {
        int low = 0;
        int high = n - 1;
        int ans = n;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] >= x) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }

    int rowWithMax1s(vector<vector<int>> &mat) {
        int n = mat[0].size();
        int maxCount = -1;
        int idx = -1;

        for(int i = 0; i < mat.size(); i++) {
            int cnt = n - first_occurence(mat[i], n, 1);

            if(cnt > maxCount) {
                maxCount = cnt;
                idx = i;
            }
        }

        return idx;
    }
};