
/*
    Problem: 125. Valid Palindrome

    Intuition:
    A string is a palindrome if it reads the same forward
    and backward, after ignoring non-alphanumeric characters
    and case differences.

    Approach:
    1. Traverse the original string.
    2. Keep only English letters and digits.
    3. Convert all characters to lowercase.
    4. Use two pointers:
       - i starts from the beginning.
       - j starts from the end.
    5. If characters don't match, return false.
    6. If all characters match, return true.

    Example:
    s = "A man, a plan, a canal: Panama"

    Filtered and lowercase:
    "amanaplanacanalpanama"

    Output: true

    Time Complexity: O(n)
    - Filtering takes O(n).
    - Lowercase conversion takes O(n).
    - Two-pointer check takes O(n).

    Space Complexity: O(n)
    - Extra string x stores the filtered characters.
*/

class Solution {
public:
    bool isPalindrome(string s) {

        string x = "";

        for(int i = 0; i < s.size(); i++) {

            int e = int(s[i]);

            if((e >= 97 && e <= 122) ||
               (e >= 65 && e <= 90) ||
               (e >= 48 && e <= 57)) {

                x += s[i];
            }
        }

        for(int i = 0; i < x.size(); i++) {
            x[i] = tolower(x[i]);
        }

        int i = 0, j = x.size() - 1;

        while(i < j) {
            if(x[i] != x[j]) return false;

            i++;
            j--;
        }

        return true;
    }
};
