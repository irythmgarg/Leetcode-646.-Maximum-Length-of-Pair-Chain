# Leetcode-646.-Maximum-Length-of-Pair-Chain
# ⛓️ Find Longest Chain of Pairs - Dynamic Programming Magic!

## 🧩 Problem Statement

Given a list of `n` pairs where each pair `[a, b]` represents a chainable interval (i.e., one can follow another if `b < next_a`), find the **longest chain** you can form such that for every pair `[a, b]`, the next pair `[c, d]` in the chain satisfies `b < c`.

## 🧪 Example

```cpp
Input: pairs = {{1,2}, {2,3}, {3,4}}
Output: 2
Explanation: The longest chain is [1,2] -> [3,4]
```

---

## 🧠 Approach 1: Top-Down Dynamic Programming (Memoization)

1. **Sort** all the pairs based on the starting element.
2. Use recursion with memoization (`t[i][prevelement]`) to decide whether to take or skip a pair.
3. If `prevelement == -1` or `pairs[prevelement][1] < pairs[i][0]`, include the current pair.
4. Recurse and return the maximum chain length.

### ⏱️ Time Complexity:

* Sorting: `O(n log n)`
* DP Recursion: `O(n^2)`

### 💾 Space Complexity:

* Memoization table: `O(n^2)`
* Recursion stack: `O(n)`

✅ This is a top-down **recursive** solution with memoization.

---

## 🧠 Approach 2: Bottom-Up Dynamic Programming (LIS-style Tabulation)

1. **Sort** the pairs based on their starting elements.
2. Create a `dp[]` array initialized to 1.
3. For each pair `i`, check all `j < i` such that `pairs[j][1] < pairs[i][0]`, and update `dp[i] = max(dp[i], dp[j] + 1)`.
4. Return the maximum value in `dp`.

### ⏱️ Time Complexity:

* Sorting: `O(n log n)`
* Nested loop: `O(n^2)`

### 💾 Space Complexity:

* `dp[]` array: `O(n)`

✅ This is a bottom-up **iterative** solution inspired by **Longest Increasing Subsequence**.

---

## 👨‍💻 Author Info

> ✍️ Developed with ❤️ by **Ridham Garg**
> 
> 🎓 **Thapar Institute of Engineering and Technology**
> 
> 📧 Email: [Ridhamgarg000@gmail.com](mailto:Ridhamgarg000@gmail.com)

---

> 🔗 Keep chaining success like this algorithm chains pairs! 🔥💡💻
