
/*
Problem: 392. Is Subsequence
Platform: LeetCode
Topic: String, Two Pointers

Approach:
Use two pointers i and j to traverse strings s and t.

Algorithm:
1. Initialize i = 0 and j = 0.
2. If s[i] != t[j], move j forward.
3. If s[i] == t[j], move both i and j forward.
4. If i reaches the end of s, return true.
5. Otherwise, return false.

Time Complexity: O(n)
Space Complexity: O(1)

Where:
n = size of string t
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;

        while (i < s.size() && j < t.size()) {
            if (s[i] != t[j]) {
                j++;
            }
            else {
                i++;
                j++;
            }
        }

        if (i >= s.size()) return true;
        else return false;
    }
};
