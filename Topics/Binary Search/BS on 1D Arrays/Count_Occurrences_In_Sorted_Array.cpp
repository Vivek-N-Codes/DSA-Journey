/*
==========================================================
Problem      : Count Occurrences in a Sorted Array
Platform     : Coding Ninjas
Problem Link : https://www.naukri.com/code360/problems/occurrence-of-x-in-a-sorted-array_630456
Difficulty   : Easy
Topic        : Binary Search

Approach
----------------------------------------------------------
Use binary search twice to find the first and last
occurrence of the target.

For the first occurrence, when the target is found,
store its index and continue searching in the left half.

For the last occurrence, when the target is found,
store its index and continue searching in the right half.

The total number of occurrences is calculated as:

last occurrence - first occurrence + 1

Time Complexity : O(log n)

Space Complexity : O(1)

Date Solved : 25-08-2026
==========================================================
*/

#include <vector>

using namespace std;

class Solution {
public:
    int FirstOcurrence(vector<int>& arr, int target) {

        int low = 0;
        int high = arr.size() - 1;
        int mid;
        int ans = -1;

        while (low <= high) {

            mid = low + (high - low) / 2;

            if (arr[mid] == target) {
                ans = mid;
                high = mid - 1;
            }
            else if (arr[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }

    int LastOcurrence(vector<int>& arr, int target) {

        int low = 0;
        int high = arr.size() - 1;
        int mid;
        int ans = -1;

        while (low <= high) {

            mid = low + (high - low) / 2;

            if (arr[mid] == target) {
                ans = mid;
                low = mid + 1;
            }
            else if (arr[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }

    int countOccurrences(vector<int>& arr, int target) {

        int first = FirstOcurrence(arr, target);

        if (first == -1) {
            return -1;
        }

        int last = LastOcurrence(arr, target);

        return (last - first) + 1;
    }
};