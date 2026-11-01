
/*
LeetCode 453: Minimum Moves to Equal Array Elements
Topic: Array, Math
Difficulty: Medium
Problem Link: https://leetcode.com/problems/minimum-moves-to-equal-array-elements/

Problem Statement:
Given an integer array nums, return the minimum number
of moves required to make all array elements equal.

In one move, you can increment n - 1 elements by 1.

Approach:
1. Find the minimum element in the array.
2. Calculate the difference between every element
   and the minimum element.
3. Add all these differences to count.
4. Return count.

Algorithm Intuition:
In each move, we increment n-1 elements.
This is equivalent to decreasing the remaining element
by 1 relative to all the other elements.

Therefore, the optimal strategy is to make every element
equal to the minimum element.

The total number of moves is the sum of the differences
between each element and the minimum value.

Example:
nums = [1, 2, 3]

Minimum element = 1

count = (1 - 1) + (2 - 1) + (3 - 1)
      = 0 + 1 + 2
      = 3

Output: 3

Time Complexity: O(n)
Finding the minimum and calculating the sum both take O(n).

Space Complexity: O(1)
Only two variables are used.

Key Takeaway:
Incrementing n-1 elements is mathematically equivalent
to decrementing one element. This allows us to solve
the problem using the minimum element and a single sum.
*/

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());

        int count = 0;

        for (int x : nums)
            count += x - mn;

        return count;
    }
};
