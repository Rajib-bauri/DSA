
/*
    Problem: LeetCode 3736. Minimum Moves

    Intuition:
    To make all array elements equal using increment operations,
    we need to make every element equal to the maximum element.

    Approach:
    1. Find the maximum element in the array.
    2. Traverse the array.
    3. For every element, calculate the difference between
       the maximum element and the current element.
    4. Add all differences to get the minimum moves.

    Example:
    nums = [1, 2, 3]

    Maximum element = 3

    Moves = (3 - 1) + (3 - 2) + (3 - 3)
          = 2 + 1 + 0
          = 3

    Time Complexity: O(n)
    - Finding maximum takes O(n).
    - Traversing the array takes O(n).

    Space Complexity: O(1)
    - Only a few variables are used.
*/

class Solution {
public:
    int minMoves(vector<int>& nums) {

        int maxele = *max_element(nums.begin(), nums.end());

        int moves = 0;

        for(int x : nums) {
            moves += (maxele - x);
        }

        return moves;
    }
};
