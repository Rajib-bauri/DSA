
/*
    Problem: 6. Zigzag Conversion

    Intuition:
    Instead of placing characters into rows and then reading
    them, we can directly calculate the indexes of characters
    belonging to each row.

    Approach:
    1. If numRows == 1, return the original string.
    2. Calculate the cycle length:
       jumps = 2 * numRows - 2.
    3. Traverse each row one by one.
    4. Add the vertically aligned character at index j.
    5. For middle rows, calculate the diagonal character:
       x = j + jumps - 2 * i.
    6. Add the diagonal character if its index is valid.
    7. Return the final result.

    Example:
    s = "PAYPALISHIRING"
    numRows = 3

    Row 0: P   A   H   N
    Row 1: A P L S I I G
    Row 2: Y   I   R

    Output: "PAHNAPLSIIGYIR"

    Time Complexity: O(n)
    Space Complexity: O(n)
    - Result string stores all n characters.
*/

class Solution {
public:
    string convert(string s, int numRows) {

        if(numRows == 1) return s;

        string result = "";

        int jumps = 2 * numRows - 2;

        for(int i = 0; i < numRows; i++) {

            for(int j = i; j < s.size(); j += jumps) {

                result += s[j];

                if(i > 0 && i < numRows - 1) {

                    int x = j + jumps - 2 * i;

                    if(x < s.size()) result += s[x];
                }
            }
        }

        return result;
    }
};
