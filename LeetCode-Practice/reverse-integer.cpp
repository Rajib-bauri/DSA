
/*
LeetCode 7: Reverse Integer
Topic: Math
Difficulty: Medium
Problem Link: https://leetcode.com/problems/reverse-integer/

Problem Statement:
Given a signed 32-bit integer x, return x with its digits
reversed.

If reversing x causes the value to go outside the
32-bit signed integer range, return 0.

Approach:
1. Convert the input into a positive long long value.
2. Handle the negative sign separately.
3. Extract digits using a % 10.
4. Build the reversed number using prod = prod * 10 + last.
5. Check whether the reversed number exceeds INT_MAX.
6. Restore the negative sign if required.

Algorithm Intuition:
The last digit of a number can be extracted using % 10.
After extracting it, remove that digit using / 10.

Build the reversed number by multiplying the current
result by 10 and adding the extracted digit.

Using long long helps safely handle intermediate values.

Example:
x = 123

Extract 3: prod = 3
Extract 2: prod = 32
Extract 1: prod = 321

Output: 321

Example:
x = -123

Reverse the digits to get 321.
Restore the negative sign.

Output: -321

Time Complexity: O(log |x|)
Each iteration processes one digit.

Space Complexity: O(1)
Only a few variables are used.

Key Takeaway:
Use modulo to extract digits, division to remove digits,
and overflow checks to stay within the 32-bit integer range.
*/

class Solution {
public:

    int solve(long long a) {
        long long prod = 0;

        while (a > 0) {
            int last = a % 10;
            prod = prod * 10 + last;
            a /= 10;

            if (prod > INT_MAX) return 0;
        }

        return prod;
    }

    int reverse(int x) {
        long long a = x;

        if (a < 0) {
            a = -a;
            int y = solve(a);
            return -1 * y;
        }
        else {
            return solve(a);
        }
    }
};
