
/*
=========================================================
LeetCode 3644: Maximum K to Sort a Permutation
Topic: Array, Bit Manipulation
Difficulty: Medium

Problem Link:
https://leetcode.com/problems/maximum-k-to-sort-a-permutation/


PROBLEM STATEMENT:
You are given a permutation nums containing every integer
from 0 to n - 1 exactly once.

You can swap two elements only when their bitwise AND
equals k.

Return the maximum value of k that allows nums to be
sorted in ascending order. If nums is already sorted,
return 0.


EXAMPLE 1:
Input:  nums = [0, 3, 2, 1]
Output: 1

EXAMPLE 2:
Input:  nums = [0, 1, 3, 2]
Output: 2

EXAMPLE 3:
Input:  nums = [3, 2, 1, 0]
Output: 0


=========================================================
APPROACH: BITWISE AND OF MISPLACED ELEMENTS
=========================================================

ALGORITHM INTUITION:

In a sorted permutation, every element should be equal
to its index.

For example:
Index:  0  1  2  3
Nums:   0  3  2  1

Here, nums[1] = 3 and nums[3] = 1 are misplaced because
their values do not match their indices.

The key observation is that k must be compatible with
every misplaced element. Taking the bitwise AND of all
misplaced values gives the maximum possible k.

WHY INITIALIZE k = -1?

In C++, -1 has all bits set to 1 in the usual two's
complement integer representation.

Therefore, k = -1 allows the first bitwise AND operation
to preserve the bits of the first misplaced value.

ALGORITHM:

1. Initialize k = -1.
2. Traverse the array using index i.
3. If nums[i] != i, the element is misplaced.
4. Update k = k & nums[i].
5. After the loop, if k is still -1, the array was already
   sorted, so return 0.
6. Otherwise, return k.


DRY RUN:
nums = [0, 3, 2, 1]

Initially:
k = -1

i = 0:
nums[0] = 0
Element is correctly placed, so skip.

i = 1:
nums[1] = 3
3 != 1, so:
k = -1 & 3 = 3

i = 2:
nums[2] = 2
Element is correctly placed, so skip.

i = 3:
nums[3] = 1
1 != 3, so:
k = 3 & 1 = 1

Final answer = 1.


TIME COMPLEXITY: O(n)

We traverse the array once and perform a constant-time
comparison and bitwise AND operation for each element.

SPACE COMPLEXITY: O(1)

We only use the variables k and n. No additional array
or data structure is created.


KEY TAKEAWAY:
Bitwise AND helps identify the common set bits shared
by all misplaced elements. Those common bits determine
the maximum valid k for this problem.
=========================================================
*/

class Solution {
public:
    int sortPermutation(vector<int>& nums) {

        int n = nums.size();
        int k = -1;

        for (int i = 0; i < n; i++) {

            if (nums[i] != i) {
                k = (k & nums[i]);
            }
        }

        return k == -1 ? 0 : k;
    }
};
