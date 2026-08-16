/*
==========================================================
Problem      : Number of Inversions
Platform     : Coding Ninjas
Problem Link : https://www.naukri.com/code360/problems/count-inversions_615
Difficulty   : Hard
Topic        : Arrays

Approach
----------------------------------------------------------
Use Merge Sort to count inversions efficiently. During the
merge step, when an element from the right half is smaller
than an element from the left half, all remaining elements
in the left half form inversions with that element.

The number of such inversions is:

mid - i + 1

Count all inversions while merging the two sorted halves.

Time Complexity : O(n log n)

Space Complexity : O(n)

Date Solved : 16-08-2026
==========================================================
*/

#include <vector>

using namespace std;

class Solution {
public:
    long long int cnt = 0;

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
                cnt += mid - i + 1;
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

    void mergeSort(vector<int>& nums, int low, int high) {

        if (low >= high) {
            return;
        }

        int mid = low + (high - low) / 2;

        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, high);
        merge(nums, low, mid, high);
    }

    long long int numberOfInversions(vector<int> nums) {

        cnt = 0;

        if (nums.empty()) {
            return 0;
        }

        mergeSort(nums, 0, nums.size() - 1);

        return cnt;
    }
};