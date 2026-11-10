
/*
    Problem: 10. Regular Expression Matching

    Intuition:
    We need to check whether the string s matches the pattern p.
    The pattern supports:
    1. '.' matches any single character.
    2. '*' matches zero or more occurrences of the
       previous character.

    Approach: Recursion + Memoization

    1. Use two pointers:
       i -> index of string s
       j -> index of pattern p

    2. If the pattern is exhausted, check whether
       the string is also exhausted.

    3. Check whether the current characters match:
       - Characters are equal, or
       - Pattern character is '.'

    4. If the next pattern character is '*', try two choices:
       - Don't take: Skip the current character and '*'.
       - Take: If characters match, consume one character
         from s but keep j unchanged.

    5. Otherwise, move both pointers forward.

    6. Store calculated results in the DP table.

    Time Complexity: O(m * n)
    Space Complexity: O(m * n)
    - DP table and recursion stack.

    m = s.length()
    n = p.length()
*/

class Solution {
public:
    int t[21][21];

    bool solve(int i, int j, const string& s, const string& p) {

        if(j == p.length()) {
            return i == s.length();
        }

        if(t[i][j] != -1) return t[i][j];

        bool match = false;

        if(i < s.length() && (p[j] == s[i] || p[j] == '.')) {
            match = true;
        }

        if(j + 1 < p.length() && p[j + 1] == '*') {

            bool dont_take = solve(i, j + 2, s, p);

            bool take = match && solve(i + 1, j, s, p);

            return t[i][j] = dont_take || take;
        }

        return t[i][j] = match && solve(i + 1, j + 1, s, p);
    }

    bool isMatch(string s, string p) {

        memset(t, -1, sizeof(t));

        return solve(0, 0, s, p);
    }
};
