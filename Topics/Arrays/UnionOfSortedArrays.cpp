/*
==========================================================
Problem      : Union of Two Sorted Arrays
Platform     : Practice
Difficulty   : Easy
Topic        : Arrays

Approach
----------------------------------------------------------
Use two pointers to traverse both sorted arrays
simultaneously. Compare the current elements and insert
the smaller one into the answer if it is not already
present. If both elements are equal, insert only one
copy and advance both pointers. Finally, process the
remaining elements of either array.

Time Complexity : O(n + m)

Space Complexity : O(n + m)

Date Solved : 23-07-2026
==========================================================
*/

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<int> ans;
        int i = 0, j = 0;

        while (i < n && j < m) {
            if (nums1[i] < nums2[j]) {
                if (ans.empty() || ans.back() != nums1[i]) {
                    ans.push_back(nums1[i]);
                }
                i++;
            }
            else if (nums1[i] > nums2[j]) {
                if (ans.empty() || ans.back() != nums2[j]) {
                    ans.push_back(nums2[j]);
                }
                j++;
            }
            else {
                if (ans.empty() || ans.back() != nums1[i]) {
                    ans.push_back(nums1[i]);
                }
                i++;
                j++;
            }
        }

        while (i < n) {
            if (ans.empty() || ans.back() != nums1[i]) {
                ans.push_back(nums1[i]);
            }
            i++;
        }

        while (j < m) {
            if (ans.empty() || ans.back() != nums2[j]) {
                ans.push_back(nums2[j]);
            }
            j++;
        }

        return ans;
    }
};