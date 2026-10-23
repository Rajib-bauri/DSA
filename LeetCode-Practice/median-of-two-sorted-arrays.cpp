
/*
=========================================================
LeetCode 4: Median of Two Sorted Arrays
Topic: Arrays, Sorting
Difficulty: Hard

Problem Link:
https://leetcode.com/problems/median-of-two-sorted-arrays/

PROBLEM STATEMENT:
Given two sorted arrays nums1 and nums2, return the median
of the two sorted arrays combined.

The overall time complexity of the required solution
should be O(log(m + n)).

Example 1:
Input: nums1 = [1, 3], nums2 = [2]
Output: 2.0

Example 2:
Input: nums1 = [1, 2], nums2 = [3, 4]
Output: 2.5


=========================================================
APPROACH: MERGE, THEN SORT
=========================================================

APPROACH:
Append all elements of nums2 to nums1, sort the combined
array, and calculate the median using its middle index.

ALGORITHM INTUITION:
1. Copy every element of nums2 into nums1.
2. Sort nums1 so all elements are in ascending order.
3. Calculate mid = size / 2.
4. If the size is odd, the median is nums1[mid].
5. If the size is even, the median is the average of
   nums1[mid - 1] and nums1[mid].

EXAMPLE:
nums1 = [1, 2]
nums2 = [3, 4]

After combining and sorting:
[1, 2, 3, 4]

The size is 4, which is even.
Median = (2 + 3) / 2.0 = 2.5


TIME COMPLEXITY: O((m + n) log(m + n))
Appending elements takes O(n), and sorting the combined
array takes O((m + n) log(m + n)).

SPACE COMPLEXITY:
The combined array occupies O(m + n) space in total.
The sort implementation may also use auxiliary stack
space, depending on the implementation.

IMPORTANT:
This is a straightforward sorting-based approach.
It does NOT meet the problem's required O(log(m + n))
time complexity. The optimal solution uses binary search.


=========================================================
C++ SOLUTION
=========================================================
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1,
                                  vector<int>& nums2) {

        for (int num : nums2) {
            nums1.push_back(num);
        }

        sort(nums1.begin(), nums1.end());

        int x = nums1.size();
        int mid = x / 2;

        if (x % 2 == 0) {
            return ((double)nums1[mid - 1] + nums1[mid]) / 2.0;
        }

        return nums1[mid];
    }
};
