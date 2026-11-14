
/*
    LeetCode POTD 3364: Minimum Positive Sum Subarray

    Problem:
    Given an integer array nums and two integers l and r,
    find the minimum positive sum of a subarray whose length
    is between l and r (inclusive).

    If no such subarray exists, return -1.

    Intuition:
    We use two nested loops to generate all possible subarrays.

    For every starting index i, we calculate the sum of
    subarrays by expanding the ending index j.

    Whenever the subarray length is between l and r
    and its sum is positive, we update the minimum sum.

    Approach:
    1. Initialize minsum with INT_MAX.
    2. Use the outer loop to select the starting index i.
    3. Initialize sum = 0 for every starting index.
    4. Use the inner loop to expand the subarray up to length r.
    5. Add each element to the current sum.
    6. Calculate the current subarray length.
    7. If the length is between l and r and sum is positive,
       update minsum.
    8. If no valid positive sum is found, return -1.

    Time Complexity: O(n * r)
    - For every starting index, we iterate at most r elements.

    Space Complexity: O(1)
    - Only a constant number of extra variables are used.
*/

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {

        int i = 0, j = 0;
        int minsum = INT_MAX;
        int n = nums.size();

        for (int i = 0; i < n; i++) {

            int sum = 0;

            for (int j = i; j < n && j < i + r; j++) {

                sum += nums[j];

                int len = j - i + 1;

                if (sum > 0 && len >= l && len <= r) {
                    minsum = min(sum, minsum);
                }
            }
        }

        return minsum == INT_MAX ? -1 : minsum;
    }
};
