```cpp
/*
    LeetCode POTD 3789: Minimum Cost

    Problem:
    We are given the costs of buying item 1, item 2, and
    both items together. We also have the required quantities
    of item 1 and item 2.

    Find the minimum total cost to satisfy both requirements.

    Intuition:
    First, check whether buying item 1 and item 2 separately
    is cheaper than buying both together.

    If buying separately is cheaper or equal, we simply
    purchase each item individually.

    Otherwise, we buy as many combined items as possible
    using min(need1, need2).

    After that, we purchase the remaining items individually
    or using the combined option, whichever is cheaper.

    Approach:
    1. If cost1 + cost2 <= costBoth, buy both items separately.
    2. Calculate the maximum number of combined purchases:
       both = min(need1, need2).
    3. Add the combined purchase cost to the total.
    4. Reduce need1 and need2 by the combined quantity.
    5. For the remaining requirement, choose the cheaper
       option between individual and combined cost.
    6. Return the minimum total cost.

    Time Complexity: O(1)
    - Only a constant number of comparisons and calculations.

    Space Complexity: O(1)
    - Only a few variables are used.
*/

class Solution {
public:
    typedef long long ll;

    ll minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {

        if (cost1 + cost2 <= costBoth) {
            return 1LL * cost1 * need1 + 1LL * cost2 * need2;
        }

        int both = min(need1, need2);
        ll total = 1LL * both * costBoth;

        need1 -= both;
        need2 -= both;

        if (need1 > 0)
            total += 1LL * need1 * min(cost1, costBoth);
        else if (need2 > 0)
            total += 1LL * need2 * min(cost2, costBoth);

        return total;
    }
};
```
