/*
==========================================================
Problem      : Second Largest Element in an Array

Platform     : LeetCode / Coding Practice

Problem Link : N/A

Difficulty   : Easy

Topic        : Arrays

Approach
----------------------------------------------------------
Maintain two variables:
1. largest  -> Stores the largest element found so far.
2. slargest -> Stores the second largest distinct element.

Traverse the array once.
- If the current element is greater than largest,
  update both largest and second largest.
- Otherwise, if it lies between largest and second largest,
  update second largest.

Time Complexity : O(n)

Space Complexity: O(1)

Date Solved     : 21-07-2026
==========================================================
*/

#include <vector>
using namespace std;

class Solution {
public:
    int secondLargestElement(vector<int>& nums) {

        int largest = nums[0];
        int slargest = -1;

        for (int i = 1; i < nums.size(); i++) {

            if (nums[i] > largest) {
                slargest = largest;
                largest = nums[i];
            }
            else if (nums[i] < largest && nums[i] > slargest) {
                slargest = nums[i];
            }

        }

        return slargest;
    }
};