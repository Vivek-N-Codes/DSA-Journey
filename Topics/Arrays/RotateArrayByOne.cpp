/*
==========================================================
Problem      : Rotate Array by One Position
Platform     : code studio
Difficulty   : Easy
Topic        : Arrays

Approach
----------------------------------------------------------
Store the first element in a temporary variable.
Shift all remaining elements one position to the left.
Place the stored element at the last index to complete
the left rotation by one position.

Time Complexity : O(n)
Space Complexity : O(1)

Date Solved : 22-07-2026
==========================================================
*/

#include <vector>

class Solution {
public:
    void rotateArrayByOne(std::vector<int>& nums) {
        if (nums.empty()) {
            return;
        }

        int temp = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            nums[i - 1] = nums[i];
        }

        nums[nums.size() - 1] = temp;
    }
};