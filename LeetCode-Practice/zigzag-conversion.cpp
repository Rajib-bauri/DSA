
/*
LeetCode 6: Zigzag Conversion
Topic: String
Difficulty: Medium
Problem Link: https://leetcode.com/problems/zigzag-conversion/

Problem Statement:
Given a string s and an integer numRows, write the characters
in a zigzag pattern across the specified number of rows.
Return the string formed by reading the rows from top to bottom.

Approach:
1. If numRows <= 1, return s directly.
2. Create a vector of strings, one for each row.
3. Traverse the input string character by character.
4. Append each character to the current row.
5. Change direction at the top and bottom rows.
6. Concatenate all rows to form the final result.

Algorithm Intuition:
The characters move downward through the rows and then upward
diagonally, repeating this pattern.

- j represents the current row.
- dir represents the direction of movement.
- At the top or bottom row, reverse dir.
- Add each character to its current row.
- Finally, join all rows in order.

Example:
s = "PAYPALISHIRING"
numRows = 3

Rows:
P   A   H   N
A P L S I I G
Y   I   R

Output: "PAHNAPLSIIGYIR"

Time Complexity: O(n)
Each character is processed and appended once, and the rows
are concatenated once.

Space Complexity: O(n)
The row strings collectively store all n characters.

Key Takeaway:
Simulate the zigzag movement using a current row index and
a direction variable instead of building a 2D grid.
*/

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) return s;

        vector<string> v(numRows, "");

        int j = 0, dir = -1;

        for (int i = 0; i < s.length(); i++) {
            if (j == numRows - 1 || j == 0)
                dir *= (-1);

            v[j] += s[i];

            if (dir == 1) j++;
            else j--;
        }

        string res;

        for (auto& it : v)
            res += it;

        return res;
    }
};
