```cpp
/*
    LeetCode 2243: Calculate Digit Sum of a String

    Problem:
    Given a string s and an integer k, divide the string
    into consecutive groups of size k.

    Calculate the sum of digits in each group and replace
    each group with its digit sum.

    Repeat this process until the string length becomes
    less than or equal to k.

    Intuition:
    We repeatedly divide the string into groups of k digits.

    For every group:
    1. Calculate the sum of its digits.
    2. Convert the sum into a string.
    3. Append it to a temporary string.

    After processing all groups, update the original string
    and repeat until its size is <= k.

    Approach:
    1. Use a while loop while s.size() > k.
    2. Create an empty temporary string.
    3. Traverse the string in groups of k using i += k.
    4. Calculate the sum of digits in each group.
    5. Convert the sum into a string using to_string().
    6. Append the result to the temporary string.
    7. Update s = tmp.
    8. Return s when its size becomes <= k.

    Time Complexity: O(n log_k(n)) approximately
    - Each round processes the current string.
    - The string size reduces after every round.

    Space Complexity: O(n)
    - A temporary string is created to store each round.
*/

class Solution {
public:
    string digitSum(string s, int k) {

        while (s.size() > k) {

            string tmp;
            int n = s.size();

            for (int i = 0; i < n; i += k) {

                int val = 0;

                for (int j = i; j < min(i + k, n); ++j) {
                    val += s[j] - '0';
                }

                tmp.append(to_string(val));
            }

            s = tmp;
        }

        return s;
    }
};
```
