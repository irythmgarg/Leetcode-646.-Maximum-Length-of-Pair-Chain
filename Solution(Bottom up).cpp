// 💡 C++ Solution: Bottom-Up DP (Longest Chain of Pairs)
// 📌 Author: Ridham Garg (Thapar Institute of Engineering and Technology)
// 📧 Email: Ridhamgarg000@gmail.com

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();

        // Step 1: Sort the pairs based on their first element to ensure order
        sort(pairs.begin(), pairs.end());

        // Step 2: Initialize the DP array
        // Each pair can at least form a chain of length 1 (by itself)
        vector<int> dp(n, 1);

        // Variable to store the overall maximum chain length
        int maxans = 1;

        // Step 3: Apply LIS-style dynamic programming
        for (int i = 0; i < n; i++) {
            // Check all previous pairs
            for (int j = 0; j < i; j++) {
                // If the current pair can follow the j-th pair
                if (pairs[j][1] < pairs[i][0]) {
                    // Update the dp[i] with max chain length ending at i
                    dp[i] = max(dp[i], dp[j] + 1);

                    // Update the overall max
                    maxans = max(maxans, dp[i]);
                }
            }
        }

        // Step 4: Return the length of the longest chain
        return maxans;
    }
};
