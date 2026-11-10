
/*
    Problem: 796. Rotate String

    Approach 1: Simulation

    Intuition:
    Repeatedly rotate the string to the left by one position.
    If the rotated string matches goal, return true.

    Steps:
    1. Check whether both strings have equal lengths.
    2. Rotate the string one character at a time.
    3. Compare the rotated string with goal.
    4. If they match, return true.
    5. If no rotation matches, return false.

    Time Complexity: O(n^2)
    Space Complexity: O(n)

    --------------------------------------------------

    Approach 2: String Concatenation

    Intuition:
    If goal is a rotation of s, it must exist as a substring
    inside s + s.

    Steps:
    1. Check whether both strings have equal lengths.
    2. Create a new string by concatenating s with itself.
    3. Check whether goal exists inside the doubled string.
    4. If found, return true; otherwise, return false.

    Example:
    s = "abcde"
    goal = "cdeab"

    doubled string = "abcdeabcde"

    "cdeab" exists inside the doubled string.

    Output: true

    Time Complexity: Commonly O(n) in practice with optimized
    string search; worst-case depends on the implementation.
    Space Complexity: O(n)
*/

class Solution {
public:

    // Approach 1: Simulation

    bool is_equal(string x, string g) {

        int size = x.size();
        int i = 0;

        while(i < size) {
            if(x[i] != g[i]) return false;
            i++;
        }

        return true;
    }

    bool rotateString(string s, string goal) {

        int n = s.size();

        if(n != goal.size()) return false;

        if(s == goal) return true;

        string x = s;

        for(int i = 0; i < n; i++) {

            int a = 0;
            x = x.substr(a + 1) + x.substr(a, 1);

            if(is_equal(x, goal)) return true;
        }

        return false;
    }
};


// Approach 2: String Concatenation

class Solution2 {
public:
    bool rotateString(string s, string goal) {

        if(s.size() != goal.size()) return false;

        string doubledst = s + s;

        return doubledst.find(goal) < doubledst.length();
    }
};
