# Quiz 1.4 - Assignments 3

先對 deadline 由小到大排序

- dp[i][j]: 在第 i 個的 deadline 內使用不超過 ｊ 的時間能獲得的最大分數
  - = 0 if i = 0 || j > d[i]
  - = dp[i - 1][j] if j < t[i]
  - = max(dp[i - 1][j], dp[i - 1][j - t[i]] + s[i]) otherwise
- dp[n] 那一行最大的值即為解
