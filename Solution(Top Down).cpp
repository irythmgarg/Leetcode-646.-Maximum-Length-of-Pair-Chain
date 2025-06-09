// 💡 C++ Solution to Find the Longest Chain of Pairs
// 📌 Author: Ridham Garg (Thapar Institute of Engineering and Technology)
// 📧 Email: Ridhamgarg000@gmail.com

class Solution {
public:
    // DP table for memoization
    int t[1001][1001];

    // Recursive helper function to find the longest chain
    int hlo(vector<vector<int>>& pairs, int i, int prevelement) {
        // Base case: if we have checked all pairs
        if (i >= pairs.size()) return 0;

        // If result is already computed
        if (prevelement != -1 && t[i][prevelement] != -1)
            return t[i][prevelement];

        int take = 0;

        // Check if we can take the current pair in the chain
        if (prevelement == -1 || pairs[prevelement][1] < pairs[i][0]) {
            take = 1 + hlo(pairs, i + 1, i); // Take current and move forward
        }

        // Skip current pair
        int nottake = hlo(pairs, i + 1, prevelement);

        // Store and return the maximum result
        if (prevelement != -1)
            return t[i][prevelement] = max(take, nottake);

        return max(take, nottake);
    }

    // Main function to find the longest chain
    int findLongestChain(vector<vector<int>>& pairs) {
        // Sort pairs by starting time
        sort(pairs.begin(), pairs.end());

        // Initialize DP table with -1
        memset(t, -1, sizeof(t));

        // Start recursion from 0th index with no previous element
        return hlo(pairs, 0, -1);
    }
};
