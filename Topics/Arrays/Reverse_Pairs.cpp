/*
==========================================================
Problem      : Reverse Pairs
Platform     : LeetCode
Problem Link : https://leetcode.com/problems/reverse-pairs/
Difficulty   : Hard
Topic        : Arrays

Approach
----------------------------------------------------------
Use Merge Sort to count reverse pairs efficiently. For
each element in the left sorted half, use a pointer in
the right sorted half to count elements satisfying:

nums[i] > 2 * nums[j]

Since both halves are sorted, the pointer only moves
forward, allowing all valid pairs to be counted in linear
time during each merge level.

After counting the reverse pairs, merge the two sorted
halves.

Use 2LL to avoid integer overflow during the comparison.

Time Complexity : O(n log n)

Space Complexity : O(n)

Date Solved : 17-08-2026
==========================================================
*/

#include <vector>

using namespace std;

class Solution {
public:
    int cnt = 0;

    void merge(vector<int>& nums, int low, int mid, int high) {

        vector<int> temp;

        int i = low;
        int j = mid + 1;

        while (i <= mid && j <= high) {

            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i]);
                i++;
            }
            else {
                temp.push_back(nums[j]);
                j++;
            }
        }

        while (i <= mid) {
            temp.push_back(nums[i]);
            i++;
        }

        while (j <= high) {
            temp.push_back(nums[j]);
            j++;
        }

        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
    }

    void countPair(vector<int>& nums, int low, int mid, int high) {

        int j = mid + 1;

        for (int i = low; i <= mid; i++) {

            while (j <= high && nums[i] > 2LL * nums[j]) {
                j++;
            }

            cnt += j - (mid + 1);
        }
    }

    void mergeSort(vector<int>& nums, int low, int high) {

        if (low >= high) {
            return;
        }

        int mid = low + (high - low) / 2;

        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, high);

        countPair(nums, low, mid, high);
        merge(nums, low, mid, high);
    }

    int reversePairs(vector<int>& nums) {

        cnt = 0;

        if (nums.empty()) {
            return 0;
        }

        mergeSort(nums, 0, nums.size() - 1);

        return cnt;
    }
};