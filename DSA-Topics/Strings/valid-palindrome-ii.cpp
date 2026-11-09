
/*
    Problem: 680. Valid Palindrome II

    Intuition:
    A string can become a palindrome by deleting at most
    one character.

    Approach:
    1. Use two pointers: left and right.
    2. Compare characters from both ends.
    3. If characters match, move both pointers inward.
    4. If characters do not match, try two possibilities:
       - Skip the left character.
       - Skip the right character.
    5. If either remaining substring is a palindrome,
       return true.
    6. Otherwise, return false.

    Example:
    s = "abca"

    First mismatch: 'b' != 'c'

    Option 1: Remove 'b' -> "aca"
    Option 2: Remove 'c' -> "aba"

    Both are palindromes.

    Output: true

    Time Complexity: O(n)
    Space Complexity: O(1) auxiliary space
    - Only pointers and boolean results are used.
*/

class Solution {
public:

    bool is_palindrom(string x, int left, int right) {

        while(left < right) {
            if(x[left] != x[right]) return false;

            left++;
            right--;
        }

        return true;
    }

    bool validPalindrome(string s) {

        int left = 0, right = s.size() - 1;

        while(left < right) {

            if(s[left] != s[right]) {

                return is_palindrom(s, left + 1, right) ||
                       is_palindrom(s, left, right - 1);
            }

            left++;
            right--;
        }

        return true;
    }
};
