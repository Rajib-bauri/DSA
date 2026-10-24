
/*
=========================================================
LeetCode 2409: Count Days Spent Together
Topic: Strings, Arrays, Prefix Sum
Difficulty: Easy

Problem Link:
https://leetcode.com/problems/count-days-spent-together/


PROBLEM STATEMENT:
Alice and Bob each have an arrival date and a leaving date.
Given these dates in "MM-DD" format, return the number of
days they spend together.

Both arrival and leaving dates are inclusive.


APPROACH: CONVERT DATES TO DAY OF YEAR

ALGORITHM INTUITION:
Comparing dates directly as strings is not the main idea
of this solution. Instead, convert every date into its
day number within a non-leap year.

For example:
January 1  -> day 1
February 1 -> day 32
March 1    -> day 60

A cumulative month-days array tells us how many days occur
before the current month. Add the date within that month
to get the day number.


ALGORITHM:
1. Store the number of days in each month.
2. Build cumMonthDays, where each entry stores the total
   number of days before that month.
3. Use findDayOfYear() to extract the month and date from
   each "MM-DD" string.
4. Convert Alice's arrival and leaving dates to day numbers.
5. Do the same for Bob.
6. The overlap starts at the later arrival date:
   max(arriveAliceDay, arriveBobDay).
7. The overlap ends at the earlier leaving date:
   min(leaveAliceDay, leaveBobDay).
8. Calculate:
   overlap = earlier_leave - later_arrival + 1.
9. If the overlap is negative, return 0; otherwise return
   the overlap.


EXAMPLE:
Alice: 08-15 to 08-18
Bob:   08-16 to 08-19

Alice's interval: days 227 to 230
Bob's interval:   days 228 to 231

Later arrival = 228
Earlier leaving = 230

Overlap = 230 - 228 + 1 = 3

Output: 3


TIME COMPLEXITY: O(1)
Only a fixed number of dates and 12 months are processed.
The input date strings have a fixed "MM-DD" format.

SPACE COMPLEXITY: O(1)
The month-days and cumulative-days arrays have fixed sizes.
Only a constant amount of additional space is used.


KEY TAKEAWAY:
Convert dates to day numbers, then find the intersection
of the two inclusive intervals.
=========================================================
*/

class Solution {
public:
    int findDayOfYear(const string& day,
                      const vector<int>& cumMonthDays) {
        int month = stoi(day.substr(0, 2));
        int date = stoi(day.substr(3));

        return cumMonthDays[month - 1] + date;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        vector<int> monthDays = {
            31, 28, 31, 30, 31, 30,
            31, 31, 30, 31, 30, 31
        };

        vector<int> cumMonthDays(13, 0);

        for (int i = 1; i <= 12; i++) {
            cumMonthDays[i] =
                cumMonthDays[i - 1] + monthDays[i - 1];
        }

        int arriveAliceDay =
            findDayOfYear(arriveAlice, cumMonthDays);
        int leaveAliceDay =
            findDayOfYear(leaveAlice, cumMonthDays);
        int arriveBobDay =
            findDayOfYear(arriveBob, cumMonthDays);
        int leaveBobDay =
            findDayOfYear(leaveBob, cumMonthDays);

        int overlapDays =
            min(leaveAliceDay, leaveBobDay)
            - max(arriveAliceDay, arriveBobDay) + 1;

        return overlapDays < 0 ? 0 : overlapDays;
    }
};
