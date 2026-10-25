
/*
LeetCode 2348: Number of Zero-Filled Subarrays
Topic: Arrays, Sliding Window
Difficulty: Medium
Problem Link: https://leetcode.com/problems/number-of-zero-filled-subarrays/

Problem Statement:
Given an integer array nums, return the number of
subarrays consisting only of zeros.

Approach:
Use two pointers i and j to track the current
zero-filled segment.

- If nums[j] == 0, add (j - i + 1) to count.
- Otherwise, move j forward and reset i to j.

Algorithm Intuition:
When nums[j] is zero, every subarray ending at index j
and starting from i through j contains only zeros.

If the current zero segment has length 3, it contributes
3 zero-filled subarrays ending at its last position.
The same logic applies whenever another zero is found.

Example:
nums = [0, 0, 0, 2, 0, 0]

First zero segment [0, 0, 0]:
Count = 1 + 2 + 3 = 6

Second zero segment [0, 0]:
Count = 1 + 2 = 3

Total = 6 + 3 = 9

Time Complexity: O(n)
Each element is processed once.

Space Complexity: O(1)
Only a few variables are used.

Key Takeaway:
A zero segment of length k contributes
k * (k + 1) / 2 zero-filled subarrays.
The sliding window counts these incrementally.
*/

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        long long count = 0;

        while (j < n) {
            if (nums[j] == 0) {
                count += (j - i + 1);
                j++;
            }
            else {
                j++;
                i = j;
            }
        }

        return count;
    }
};
