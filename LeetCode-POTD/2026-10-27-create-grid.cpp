
/*
LeetCode 3963: Create Grid
Topic: Array, Strings
Problem Link: https://leetcode.com/problems/

Problem Statement:
Create and return an m x n grid represented as a vector
of strings according to the problem's required pattern.

Approach:
1. Create a vector of m strings.
2. Set the first row to n dots.
3. Create another row containing n-1 hashes followed by a dot.
4. Assign this row to every remaining row.

Algorithm Intuition:
The first row is filled entirely with dots.
Every row after the first has hashes in the first n-1
positions and a dot in the last position.

Example:
m = 3, n = 3

Output:
[
  "...",
  "##.",
  "##."
]

Time Complexity: O(m * n)
Creating and assigning the rows requires O(m * n) work.

Space Complexity: O(m * n)
The returned grid stores m strings of length n.

Key Takeaway:
The string constructor string(length, character) creates
a string filled with the specified character.
*/

class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m);
        grid[0] = string(n, '.');

        string row = string(n - 1, '#') + '.';

        for (int i = 1; i < m; i++) {
            grid[i] = row;
        }

        return grid;
    }
};
