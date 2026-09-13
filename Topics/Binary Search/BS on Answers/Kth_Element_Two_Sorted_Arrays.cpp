/*
==========================================================
Problem      : K-th Element of Two Sorted Arrays
Platform     : GeeksforGeeks
Problem Link :
Difficulty   : Medium
Topic        : Binary Search

Approach
----------------------------------------------------------
Binary Search on the partition of the smaller array.

The left partition contains exactly k elements. If cut1
elements are taken from array a, then cut2 = k - cut1
elements are taken from array b.

A valid partition satisfies:
l1 <= r2 && l2 <= r1

The k-th element is the maximum element on the left side.

Time Complexity : O(log(min(n1, n2)))
Space Complexity : O(1)

Date Solved :

==========================================================
*/

#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    int kthElement(vector<int> &a, vector<int>& b, int k) {
        int n1 = a.size();
        int n2 = b.size();

        if(n2 < n1) return kthElement(b, a, k);

        int low = max(0, k - n2);
        int high = min(k, n1);

        while(low <= high) {
            int cut1 = low + (high - low) / 2;
            int cut2 = k - cut1;

            int l1 = cut1 == 0 ? INT_MIN : a[cut1 - 1];
            int l2 = cut2 == 0 ? INT_MIN : b[cut2 - 1];

            int r1 = cut1 == n1 ? INT_MAX : a[cut1];
            int r2 = cut2 == n2 ? INT_MAX : b[cut2];

            if(l1 <= r2 && l2 <= r1) {
                return max(l1, l2);
            }
            else if(l1 > r2) {
                high = cut1 - 1;
            }
            else {
                low = cut1 + 1;
            }
        }

        return -1;
    }
};