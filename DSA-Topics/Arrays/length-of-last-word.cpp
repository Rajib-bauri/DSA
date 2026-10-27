
/*
LeetCode 58: Length of Last Word
Topic: String
Difficulty: Easy
Problem Link: https://leetcode.com/problems/length-of-last-word/

Problem Statement:
Given a string s consisting of words and spaces, return
the length of the last word in the string.

Approach:
Traverse the string from right to left.

1. Skip all trailing spaces.
2. Count characters until reaching another space or
   the beginning of the string.
3. Return the count.

Algorithm Intuition:
The last word is at the end of the string, ignoring any
trailing spaces. So, there is no need to check the entire
string or store the words separately.

Example:
s = "Hello World   "

Skip the trailing spaces.
Count the characters in "World".

Output: 5

Time Complexity: O(n)
In the worst case, we traverse the entire string.

Space Complexity: O(1)
Only two integer variables are used.

Key Takeaway:
Starting from the end makes it easy to skip trailing
spaces and count the last word in one pass.
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length() - 1;

        // Skip trailing spaces
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        // Count characters in the last word
        int length = 0;

        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }

        return length;
    }
};
