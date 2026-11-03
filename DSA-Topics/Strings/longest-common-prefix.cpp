
/*
    Problem: 14. Longest Common Prefix

    Intuition:
    After sorting the strings lexicographically, the first
    and last strings will have the maximum difference.
    Their common prefix is the common prefix of all strings.

    Approach:
    1. Sort the array of strings.
    2. Store the first string in 'fast'.
    3. Store the last string in 'last'.
    4. Compare both strings character by character.
    5. Stop when characters don't match.
    6. Return the common prefix using substr().

    Example:
    strs = ["flower", "flow", "flight"]

    After sorting:
    ["flight", "flow", "flower"]

    Compare "flight" and "flower".
    Common prefix = "fl"

    Output: "fl"

    Time Complexity: O(n log n * m)
    - Sorting n strings takes O(n log n * m) approximately,
      where m is the maximum string length.
    - Comparing the first and last strings takes O(m).

    Space Complexity: Depends on sorting implementation.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        sort(strs.begin(), strs.end());

        string fast = strs[0];
        string last = strs[strs.size() - 1];

        int i = 0;
        int size = min(fast.length(), last.length());

        while(i < size && fast[i] == last[i]) {
            i++;
        }

        return fast.substr(0, i);
    }
};
