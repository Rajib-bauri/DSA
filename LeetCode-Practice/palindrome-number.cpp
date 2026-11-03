
/*
    Problem: 9. Palindrome Number

    Intuition:
    A number is a palindrome if its digits read the same
    forward and backward.

    Approach:
    1. If the number is negative, return false.
    2. Extract each digit using % 10.
    3. Store the digits in a vector.
    4. Use two pointers to compare digits from both ends.
    5. If all digits match, return true.

    Example:
    x = 121

    Extracted digits = [1, 2, 1]

    First comparison: 1 == 1
    Output: true

    Time Complexity: O(log10(x))
    Space Complexity: O(log10(x))
*/

class Solution {
public:

    bool check(int z) {

        vector<int> ans;

        while(z > 0) {
            int last = z % 10;
            ans.push_back(last);
            z /= 10;
        }

        // check palindrome
        int i = 0, j = ans.size() - 1;

        while(i < j) {
            if(ans[i] != ans[j]) return false;
            else {
                i++;
                j--;
            }
        }

        return true;
    }

    bool isPalindrome(int x) {

        if(x < 0) return false;
        else return check(x);
    }
};
