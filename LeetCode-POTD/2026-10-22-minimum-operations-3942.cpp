
/*
Problem: LeetCode 3942
Date: 2026-10-22
Platform: LeetCode
Language: C++

Algorithm Intuition:
Find the index of zero, then traverse the array
circularly to check two possible patterns:
increasing values (i) and decreasing values (n - i).

If both patterns become invalid, return -1.
Otherwise, use the valid pattern to calculate
the minimum number of operations.

Time Complexity: O(n)
Finding zero and checking the patterns take
linear time.

Space Complexity: O(1)
Only a constant number of extra variables are used.
*/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return 0;

        int zero = find(nums.begin(), nums.end(), 0)
                   - nums.begin();

        bool inc = true, dec = true;

        for (int i = 1; i < n; i++) {
            int value = nums[(zero + i) % n];

            if (value != i) inc = false;
            if (value != n - i) dec = false;

            if (!inc && !dec) return -1;
        }

        if (inc) return min(zero, n - zero + 2);

        return min(n - zero, zero + 2);
    }
};
