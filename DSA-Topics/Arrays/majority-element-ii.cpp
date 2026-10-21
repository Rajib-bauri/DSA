
/*
Problem: 229. Majority Element II
Platform: LeetCode
Topic: Arrays, Hashing
Language: C++

Algorithm Intuition:
Count the frequency of every element using an
unordered_map. Then traverse the map and add
each element whose frequency is greater than n / 3
to the answer vector.

Time Complexity: O(n) on average.
Counting frequencies and checking the map take
linear time on average. The theoretical worst
case for hash map operations can be O(n^2).

Space Complexity: O(n).
The hash map can store up to n distinct elements,
and the answer vector uses additional space.
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums;

        unordered_map<int, int> mp;

        for (int num : nums) {
            mp[num]++;
        }

        vector<int> ans;

        for (auto it : mp) {
            if (it.second > n / 3) {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};
