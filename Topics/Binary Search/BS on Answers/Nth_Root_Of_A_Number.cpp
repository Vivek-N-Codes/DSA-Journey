/*
==========================================================
Problem      : Nth Root of a Number
Platform     : Coding Ninjas
Problem Link : https://www.naukri.com/code360/problems/find-nth-root-of-m_1062679
Difficulty   : Easy
Topic        : Binary Search

Approach
----------------------------------------------------------
Use binary search to find the integer whose Nth power is
equal to M.

For every middle value, calculate mid^N using a helper
function. Stop the multiplication early if the result
exceeds M because only the comparison with M matters.

If mid^N equals M, return mid. If it is smaller, search
the right half. Otherwise, search the left half.

Time Complexity : O(N log M)

Space Complexity : O(1)

Date Solved : 02-09-2026
==========================================================
*/

#include <vector>

using namespace std;

class Solution {
public:
    long long power(int mid, int N, int M) {

        long long temp = 1;

        for (int i = 0; i < N; i++) {

            temp *= mid;

            if (temp > M) {
                break;
            }
        }

        return temp;
    }

    int NthRoot(int N, int M) {

        if (N == 0) {
            return -1;
        }

        if (N == 1) {
            return M;
        }

        int low = 1;
        int high = M;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            long long value = power(mid, N, M);

            if (value == M) {
                return mid;
            }
            else if (value < M) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return -1;
    }
};