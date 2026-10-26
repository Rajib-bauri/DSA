
/*
LeetCode 334: Increasing Triplet Subsequence
Topic: Array, Greedy
Difficulty: Medium
Problem Link: https://leetcode.com/problems/increasing-triplet-subsequence/

Problem Statement:
Given an integer array nums, return true if there exist
indices i < j < k such that nums[i] < nums[j] < nums[k].
Otherwise, return false.

Approach:
Maintain two variables:
- first: the smallest value found so far.
- sec: the smallest possible second value greater than first.

Traverse the array:
1. If num <= first, update first.
2. Otherwise, if num <= sec, update sec.
3. Otherwise, num is greater than both first and sec,
   so an increasing triplet exists. Return true.

Algorithm Intuition:
We want three numbers in increasing order.

Instead of storing every number, keep the smallest possible
first and second numbers. Smaller values are better because
they leave more chances for a later number to be greater.

If a number is greater than both first and sec, then:
first < sec < num
Therefore, an increasing triplet exists.

Example:
nums = [2, 1, 5, 0, 4, 6]

first = 2, then 1
sec = 5, then 4
num = 6

Since 6 > first and 6 > sec, return true.

Time Complexity: O(n)
The array is traversed once.

Space Complexity: O(1)
Only two variables are used.

Key Takeaway:
Greedy approach: maintain the smallest possible first
and second values to detect an increasing triplet efficiently.
*/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX;
        int sec = INT_MAX;

        for (int num : nums) {
            if (num <= first) {
                first = num;
            }
            else if (num <= sec) {
                sec = num;
            }
            else {
                return true;
            }
        }

        return false;
    }
};
