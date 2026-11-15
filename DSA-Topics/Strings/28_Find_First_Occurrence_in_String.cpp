```cpp
/*
    LeetCode 28: Find the Index of the First Occurrence
    in a String

    Problem:
    Given two strings haystack and needle, find the first
    occurrence of needle inside haystack.

    Return the starting index if found.
    Otherwise, return -1.

    Intuition:
    We check every possible starting position in haystack.

    At each position, we extract a substring of length
    equal to needle's length.

    If the extracted substring matches needle,
    we return that starting index.

    Approach:
    1. Calculate the lengths of both strings.
    2. If needle is longer than haystack, return -1.
    3. Traverse haystack using a while loop.
    4. Extract a substring of length m using substr().
    5. Compare the substring with needle.
    6. If both match, return the current index.
    7. Otherwise, move to the next index.
    8. If no match is found, return -1.

    Time Complexity: O((n - m + 1) * m)
    - We check up to (n - m + 1) positions.
    - Each substring comparison can take O(m).

    Space Complexity: O(m)
    - A temporary substring of length m is created.
*/

class Solution {
public:
    int strStr(string haystack, string needle) {

        int n = haystack.size();
        int m = needle.size();

        if (m > n) return -1;

        int i = 0;

        while (i < n && i <= n - m) {

            string x = haystack.substr(i, m);

            if (x == needle)
                return i;
            else
                i++;
        }

        return -1;
    }
};
```
