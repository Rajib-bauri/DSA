
/*
LeetCode 31: Next Permutation
Topic: Array, Two Pointers
Difficulty: Medium
Problem Link: https://leetcode.com/problems/next-permutation/

Problem Statement:
Given an array of integers, rearrange it into the next
lexicographically greater permutation.

If no greater permutation exists, rearrange it into the
lowest possible order (ascending order).

Approach:
1. Find the first index i from the right where
   nums[i] < nums[i + 1].
2. If such an index exists, find the first element j
   from the right that is greater than nums[i].
3. Swap nums[i] and nums[j].
4. Reverse the elements after index i.

Algorithm Intuition:
The next permutation should be just slightly greater
than the current permutation.

- Finding i identifies the position that can be increased.
- Finding j gives the smallest suitable greater element
  from the right.
- Reversing the suffix makes the remaining elements
  as small as possible.

Example:
nums = [1, 2, 3]

Step 1:
i = 1, because nums[1] < nums[2].

Step 2:
j = 2, because nums[2] > nums[1].

Step 3:
Swap 2 and 3:
[1, 3, 2]

Step 4:
Reverse the suffix after i:
[1, 3, 2]

Output: [1, 3, 2]

Time Complexity: O(n)
Finding the pivot, finding the swap element, and reversing
the suffix each take at most O(n) time.

Space Complexity: O(1)
The permutation is modified in-place without extra space.

Key Takeaway:
Find the pivot, swap it with the next greater element
from the right, and reverse the remaining suffix.
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        if (i >= 0) {
            int j = n - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }

            swap(nums[i], nums[j]);
        }

        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }
};
