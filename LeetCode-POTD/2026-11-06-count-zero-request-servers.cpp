
/*
    Problem: 2747. Count Zero Request Servers

    Intuition:
    For each query, we need to count servers that did not
    receive any requests during the time interval [query - x, query].

    Instead of processing every query independently,
    sort the logs and queries by time and use a sliding window.

    Approach:
    1. Sort logs based on their timestamps.
    2. Store each query with its original index.
    3. Sort queries by time.
    4. Maintain two pointers:
       - i removes logs that are earlier than the window.
       - j adds logs that fall within the current window.
    5. Use an unordered_map to maintain the frequency of
       requests received by each server in the window.
    6. The number of active servers is mp.size().
    7. Calculate zero-request servers using n - mp.size().
    8. Store the answer at the original query index.

    Example:
    n = 3
    x = 2

    Suppose the current query time is 5.

    Current time window = [5 - 2, 5]
                         = [3, 5]

    Only servers that received requests between time 3 and 5
    are counted in the map.

    If 2 unique servers received requests:
    Answer = 3 - 2 = 1

    Time Complexity:
    O(m log m + q log q + m + q)

    - Sorting logs: O(m log m)
    - Sorting queries: O(q log q)
    - Sliding window traversal: O(m + q) average

    Space Complexity: O(q + k)

    - q = number of queries
    - k = maximum number of unique servers in the window
*/

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {

        int m = logs.size();

        auto lambda = [](vector<int>& vec1, vector<int>& vec2) {
            return vec1[1] < vec2[1];
        };

        sort(begin(logs), end(logs), lambda);

        int q = queries.size();

        vector<pair<int,int>> timeIndex(q);

        for (int i = 0; i < q; i++)
            timeIndex[i] = {queries[i], i};

        sort(begin(timeIndex), end(timeIndex));

        unordered_map<int,int> mp;
        vector<int> result(q);

        int i = 0, j = 0;

        for (auto [curtime, ind] : timeIndex) {

            int start = curtime - x;
            int end = curtime;

            // Add logs with time <= end
            while (j < m && logs[j][1] <= end) {
                mp[logs[j][0]]++;
                j++;
            }

            // Remove logs with time < start
            while (i < m && logs[i][1] < start) {

                mp[logs[i][0]]--;

                if (mp[logs[i][0]] == 0)
                    mp.erase(logs[i][0]);

                i++;
            }

            // Count servers that received zero requests
            result[ind] = n - mp.size();
        }

        return result;
    }
};
