```cpp
/*
    LeetCode 161: One Edit Distance

    Problem:
    Given two strings s and t, return true if they are
    exactly one edit distance apart.

    An edit means:
    1. Insert one character.
    2. Delete one character.
    3. Replace one character.

    Intuition:
    First, make sure s is the shorter string.

    If the length difference is greater than 1,
    they cannot be one edit distance apart.

    Then compare both strings character by character.

    There are two possible cases:

    Case 1: Both strings have the same length.
    - One character must be replaced.
    - After finding the first mismatch, compare the
      remaining substrings.

    Case 2: Strings have different lengths.
    - One character must be inserted into the shorter
      string or deleted from the longer string.
    - After finding the first mismatch, skip one character
      in the longer string and compare the remaining parts.

    Approach:
    1. Calculate the lengths of both strings.
    2. If s is longer than t, swap their positions
       using recursion.
    3. If the length difference is greater than 1,
       return false.
    4. Traverse both strings using a for loop.
    5. If a mismatch is found:
       - Same length: Compare substrings after i.
       - Different length: Compare s from i with
         t from i + 1.
    6. If no mismatch is found, return true only when
       the lengths differ by exactly one.

    Time Complexity: O(n)
    - String comparison and substring operations take
      linear time in the worst case.

    Space Complexity: O(n)
    - Substrings may create temporary strings.

*/

class Solution {
public:
    bool isOneEditDistance(string s, string t) {

        int slen = s.length();
        int tlen = t.length();

        if (slen > tlen) {
            return isOneEditDistance(t, s);
        }

        if (tlen - slen > 1) return false;

        for (int i = 0; i < slen; i++) {

            if (s[i] != t[i]) {

                if (slen == tlen) {
                    return s.substr(i + 1) == t.substr(i + 1);
                }
                else {
                    return s.substr(i) == t.substr(i + 1);
                }
            }
        }

        return slen != tlen;
    }
};
```
