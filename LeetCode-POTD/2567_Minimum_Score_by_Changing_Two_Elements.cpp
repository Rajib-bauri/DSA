```cpp
/*
    LeetCode 2567: Minimum Score by Changing Two Elements

    Problem:
    Given an integer array nums, we can change at most
    two elements to any value.

    The score is the difference between the maximum
    and minimum elements.

    Find the minimum possible score.

    Intuition:
    First, sort the array.

    After sorting, we have three possible ways to
    minimize the difference:

    Case 1:
    Change the three largest elements.
    Remaining difference = nums[n-3] - nums[0].

    Case 2:
    Change the three smallest elements.
    Remaining difference = nums[n-1] - nums[2].

    Case 3:
    Change the two smallest and the two largest
    elements in a balanced way.
    Remaining difference = nums[n-2] - nums[1].

    We calculate all three possibilities and return
    the minimum.

    Approach:
    1. Calculate the array size.
    2. Sort the array in ascending order.
    3. Calculate the three possible differences.
    4. Use min() to return the smallest difference.

    Time Complexity: O(n log n)
    - Sorting takes O(n log n).
    - Calculating the three differences takes O(1).

    Space Complexity: O(1) auxiliary space
    - Sorting is performed in place (ignoring
      implementation-dependent sorting stack space).
*/

class Solution {
public:
    int minimizeSum(vector<int>& nums) {

        int n = nums.size();

        sort(nums.begin(), nums.end());

        return min({
            nums[n-3] - nums[0],
            nums[n-1] - nums[2],
            nums[n-2] - nums[1]
        });
    }
};
```
