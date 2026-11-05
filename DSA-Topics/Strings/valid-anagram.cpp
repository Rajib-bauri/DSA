
/*
    Problem: 242. Valid Anagram

    Intuition:
    Two strings are anagrams if they contain the same characters
    with the same frequencies.

    Approach:
    1. If the lengths of both strings are different, return false.
    2. Store the frequency of every character in s using a map.
    3. Traverse string t.
    4. If a character exists in the map, decrease its frequency.
    5. If its frequency becomes zero, erase it from the map.
    6. If a character does not exist, return false.
    7. Finally, return true if the map is empty.

    Example:
    s = "anagram"
    t = "nagaram"

    Character frequencies match.

    Output: true

    Time Complexity: O(n) average
    Space Complexity: O(k)
    - k represents the number of distinct characters.
*/

class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size()) return false;

        unordered_map<char, int> mp;

        for(char ch : s) {
            mp[ch]++;
        }

        for(int i = 0; i < t.size(); i++) {

            if(mp.find(t[i]) != mp.end()) {

                mp[t[i]]--;

                if(mp[t[i]] == 0) mp.erase(t[i]);
            }
            else return false;
        }

        return mp.empty();
    }
};
