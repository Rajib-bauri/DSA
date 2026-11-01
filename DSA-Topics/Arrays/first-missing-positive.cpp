
/*
LeetCode 41: First Missing Positive
Topic: Array, Sorting
Difficulty: Hard
Problem Link: https://leetcode.com/problems/first-missing-positive/

Problem Statement:
Given an unsorted integer array nums, return the smallest
missing positive integer.

Approach:
1. Sort the array.
2. Find the index where the value 1 occurs.
3. If 1 does not exist, return 1.
4. Initialize value = 1.
5. Traverse the array from the index of 1:
   - If nums[i] == value, increment value.
   - If nums[i] is a duplicate of the previous element,
     skip it.
   - Otherwise, stop the traversal.
6. Return value.

Algorithm Intuition:
After sorting, positive numbers appear in increasing order.

We start searching from 1 because it is the smallest
possible positive integer.

Whenever the current number matches value, we move to
the next expected positive integer.

Duplicates are ignored because they do not change
the smallest missing positive number.

Example:
nums = [3, 4, -1, 1]

After sorting:
[-1, 1, 3, 4]

Start with value = 1.

1 == 1, so value becomes 2.
3 != 2 and is not a duplicate, so stop.

Output: 2

Time Complexity: O(n log n)
Sorting takes O(n log n), and the remaining traversals
take O(n).

Space Complexity: Depends on sorting implementation.
The algorithm uses O(1) auxiliary variables apart from
the sorting implementation's internal stack/space.

Key Takeaway:
Sorting makes it easier to find the first missing
positive integer by checking consecutive expected values.
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        int n = nums.size();
        int idx = -1;

        sort(nums.begin(), nums.end());

        // Finding the index of 1
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                idx = i;
                break;
            }
        }

        if (idx == -1) return 1;

        int value = 1;

        for (int i = idx; i < n; i++) {

            if (nums[i] == value)
                value++;

            else if (nums[i] == nums[i - 1])
                continue;

            else
                break;
        }

        return value;
    }
};
