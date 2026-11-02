
/*
    Problem: 462. Minimum Moves to Equal Array Elements II

    Intuition:
    The minimum total moves are achieved when every element
    is converted to the median of the array.

    Approach:
    1. Sort the array.
    2. Find the middle element using index n / 2.
    3. Calculate the absolute difference between every
       element and the median.
    4. Add all differences to get the minimum moves.

    Example:
    nums = [1, 2, 3]

    Median = 2

    Moves = |1 - 2| + |2 - 2| + |3 - 2|
          = 1 + 0 + 1
          = 2

    Time Complexity: O(n log n)
    - Sorting takes O(n log n).
    - Traversing the array takes O(n).

    Space Complexity: O(1) auxiliary space
    - Apart from the sorting implementation's internal space.
*/

class Solution {
public:
    int minMoves2(vector<int>& nums) {

        int n = nums.size();

        sort(nums.begin(), nums.end());

        int ans = 0;
        int mid = n / 2;

        for (int i = 0; i < n; i++) {
            ans += abs(nums[mid] - nums[i]);
        }

        return ans;
    }
};
