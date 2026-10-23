
/*
=========================================================
LeetCode 80: Remove Duplicates from Sorted Array II
Topic: Array, Two Pointers
Difficulty: Medium

Problem Link:
https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/


PROBLEM STATEMENT:
Given an integer array nums sorted in non-decreasing order,
remove some duplicates in-place so that each unique element
appears at most twice.

The relative order of the elements must remain the same.

Return the number of elements remaining after removing
the extra duplicates.


EXAMPLE 1:
Input:  nums = [1,1,1,2,2,3]
Output: 5

Modified array's first 5 elements:
[1,1,2,2,3]


EXAMPLE 2:
Input:  nums = [0,0,1,1,1,1,2,3,3]
Output: 7

Modified array's first 7 elements:
[0,0,1,1,2,3,3]


=========================================================
APPROACH: COUNT DUPLICATES + IN-PLACE OVERWRITING
=========================================================

ALGORITHM INTUITION:

Because the array is sorted, equal elements appear
together.

We use:
- idx: next position where a valid element is written.
- count: tracks occurrences of the current value.
- value: stores the current value being counted.

For each element:
1. Handle a repeated element when count has been reset.
2. If the element equals value, increase count.
3. Otherwise, start counting the new value from 1.
4. If count <= 2, keep the element at nums[idx] and
   increment idx.
5. If count > 2, reset count to 0 so the next repeated
   occurrence can be skipped by the first condition.

The array is modified in-place, and idx gives the final
valid length.


DRY RUN:
Input: [1,1,1,2,2,3]

Initially:
idx = 0, count = 0, value = 1

First 1:
count becomes 1, keep it.
idx = 1

Second 1:
count becomes 2, keep it.
idx = 2

Third 1:
count becomes 3, so do not keep it.
Reset count = 0.

Next 2:
It differs from the previous element, so process it.
value = 2, count = 1, keep it.
idx = 3

Next 2:
count = 2, keep it.
idx = 4

Next 3:
value = 3, count = 1, keep it.
idx = 5

Return 5.


TIME COMPLEXITY: O(n)
The array is traversed once, so the time complexity
is linear.

SPACE COMPLEXITY: O(1)
Only a constant number of variables are used.
The array is modified in-place without an extra array.


KEY TAKEAWAY:
Since the array is sorted, duplicate values are adjacent.
Counting occurrences allows us to keep at most two copies
of each value while preserving the original order.
=========================================================
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int n = nums.size();

        int idx = 0, count = 0, value = nums[0];

        for (int i = 0; i < n; i++) {

            if ((count == 0 && i > 0) &&
                nums[i] == nums[i - 1]) {
                continue;
            }

            if (nums[i] == value) {
                count++;
            } else {
                value = nums[i];
                count = 1;
            }

            if (count <= 2) {
                nums[idx++] = nums[i];
            }

            if (count > 2) {
                count = 0;
            }
        }

        return idx;
    }
};
