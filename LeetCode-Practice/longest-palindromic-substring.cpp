
/*
LeetCode 5: Longest Palindromic Substring
Topic: Dynamic Programming (2D DP)
Difficulty: Medium
Problem Link: https://leetcode.com/problems/longest-palindromic-substring/

Problem Statement:
Given a string s, return the longest substring of s
that is a palindrome.

Approach:
Use a 2D DP table where dp[i][j] indicates whether the
substring s[i...j] is a palindrome.

A substring is a palindrome if:
1. The characters at both ends are equal.
2. The substring has length at most 3, or the inner
   substring dp[i+1][j-1] is also a palindrome.

Traverse i from right to left and j from i to n-1.
Whenever a longer palindrome is found, update start and maxLen.

Algorithm Intuition:
A palindrome reads the same forward and backward.

If s[i] == s[j], then the substring can be a palindrome
when its length is 1, 2, or 3, or when the substring
between these two characters is already a palindrome.

Processing i from right to left ensures dp[i+1][j-1]
has already been calculated when needed.

Example:
s = "babad"

A longest palindrome is "bab".
Another valid answer is "aba".

Output: "bab" or "aba"

Time Complexity: O(n^2)
There are O(n^2) pairs of indices to check.

Space Complexity: O(n^2)
The 2D DP table stores n*n boolean values.

Key Takeaway:
Build longer palindromes using already-checked shorter
substrings, and track the starting index and length
of the longest palindrome found.
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int start = 0, maxLen = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] &&
                    (j - i <= 2 || dp[i + 1][j - 1])) {

                    dp[i][j] = true;

                    if (j - i + 1 > maxLen) {
                        start = i;
                        maxLen = j - i + 1;
                    }
                }
            }
        }

        return s.substr(start, maxLen);
    }
};
