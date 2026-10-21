
/*
Problem: 3863. Minimum Operations to Sort a String
Date: 2026-10-21
Platform: LeetCode
Language: C++20

Algorithm Intuition:
First, find the minimum and maximum characters
by traversing the string.

If the string is already sorted, return 0.
If its length is 2 and it is not sorted, return -1.

If the first character is the minimum or the last
character is the maximum, return 1.

Otherwise, check the middle characters. If the
minimum or maximum character appears in the middle,
return 2.

If none of these conditions apply, return 3.

Time Complexity: O(n)
Finding the minimum and maximum, checking whether
the string is sorted, and scanning the middle
characters each take at most linear time.

Space Complexity: O(1)
Only a fixed number of extra variables are used.
*/

class Solution {
public:
    int minOperations(string s) {
        char mx = 'a', mn = 'z';
        int n = s.size();

        for (int i = 0; i < n; i++) {
            mx = max(mx, s[i]);
            mn = min(mn, s[i]);
        }

        if (ranges::is_sorted(s)) {
            return 0;
        }

        if (n == 2) return -1;

        if (s[0] == mn || s[n - 1] == mx) return 1;

        for (int i = 1; i < n - 1; i++) {
            if (s[i] == mn || s[i] == mx) return 2;
        }

        return 3;
    }
};
