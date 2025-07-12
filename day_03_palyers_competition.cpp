class Solution {
public:
    // Memoization: key is (total players, pos1, pos2)
    map<tuple<int, int, int>, pair<int, int>> memo;

    pair<int, int> dfs(int n, int a, int b) {
        if (a > b) swap(a, b); // always keep a < b
        if (a + b == n + 1) return {1, 1}; // they face each other now

        auto key = make_tuple(n, a, b);
        if (memo.count(key)) return memo[key];

        int half = (n + 1) / 2;
        int minRound = INT_MAX, maxRound = INT_MIN;

        // Simulate all matchups
        vector<int> players(n);
        iota(players.begin(), players.end(), 1);  // [1, 2, ..., n]

        vector<int> nextRound;
        generateNextRounds(players, a, b, 0, {}, nextRound, n, minRound, maxRound);

        return memo[key] = {minRound, maxRound};
    }

    void generateNextRounds(vector<int>& players, int a, int b, int i,
                            vector<int> current,
                            vector<int>& result,
                            int n,
                            int& minRound,
                            int& maxRound) {
        int size = players.size();

        if (i >= size / 2) {
            // If odd, handle middle player
            if (size % 2 == 1)
                current.push_back(players[size / 2]);

            // Re-sort the next round based on original numbering
            sort(current.begin(), current.end());

            // Find new positions of a and b in current
            int pos1 = find(current.begin(), current.end(), a) - current.begin() + 1;
            int pos2 = find(current.begin(), current.end(), b) - current.begin() + 1;

            auto [ear, lat] = dfs(current.size(), pos1, pos2);
            if (ear < INT_MAX) minRound = min(minRound, 1 + ear);
            if (lat > INT_MIN) maxRound = max(maxRound, 1 + lat);
            return;
        }

        int left = players[i];
        int right = players[size - 1 - i];

        // if a and b face each other now
        if ((left == a && right == b) || (left == b && right == a)) {
            minRound = min(minRound, 1);
            maxRound = max(maxRound, 1);
            return;
        }

        // Case 1: a or b wins
        if (left == a || left == b) {
            current.push_back(left);
            generateNextRounds(players, a, b, i + 1, current, result, n, minRound, maxRound);
            current.pop_back();
        }
        else if (right == a || right == b) {
            current.push_back(right);
            generateNextRounds(players, a, b, i + 1, current, result, n, minRound, maxRound);
            current.pop_back();
        }
        else {
            // either can win
            current.push_back(left);
            generateNextRounds(players, a, b, i + 1, current, result, n, minRound, maxRound);
            current.pop_back();

            current.push_back(right);
            generateNextRounds(players, a, b, i + 1, current, result, n, minRound, maxRound);
            current.pop_back();
        }
    }

    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        return {dfs(n, firstPlayer, secondPlayer).first, dfs(n, firstPlayer, secondPlayer).second};
    }
};
