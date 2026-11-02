
/*
    Problem: 8. String to Integer (atoi)

    Intuition:
    Convert the string into an integer by skipping leading
    spaces, checking the sign, and processing digits one by one.

    Approach:
    1. Skip all leading whitespace characters.
    2. Check whether the number has a '+' or '-' sign.
    3. Process digits and build the number.
    4. Before multiplying by 10 and adding a digit,
       check whether the result will overflow.
    5. Return INT_MIN or INT_MAX if overflow occurs.
    6. Apply the negative sign if required.

    Example:
    s = "   -42"

    Skip spaces -> "-42"
    Sign = negative
    Extract digits -> 42
    Apply sign -> -42

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

class Solution {
public:
    int myAtoi(string s) {

        long long res = 0;
        int i = 0;

        // for whitespaces
        while(i < s.size() && s[i] == ' ') {
            i++;
        }

        // for signed
        bool yes = false;

        if(i < s.size() && s[i] == '-') {
            yes = true;
            i++;
        }
        else if(i < s.size() && s[i] == '+') {
            i++;
        }

        // for digits
        while(i < s.size()) {

            int x = s[i] - '0';

            if(x >= 0 && x < 10) {

                if(res > INT_MAX / 10 ||
                  (res == INT_MAX / 10 && x > (yes ? 8 : 7))) {
                    return yes ? INT_MIN : INT_MAX;
                }

                res = (res * 10) + x;
                i++;
            }
            else break;
        }

        if(yes) res = -res;

        return (int)res;
    }
};
