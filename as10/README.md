# Assignment 10 - Summation 0???

- [main.c](main.c)
  - dp[i][j]: 前 i 個能不能挑出一部分剛好和為 j
    - = true if j = 0
    - = false if i = 0 && j != 0
    - = dp[i - 1][j] if j < a[i]
    - = dp[i - 1][j] || dp[i - 1][j - a[i]] otherwise
  - 從 dp[n][j = sum / 2] 往前找到最大的 j
    - sum - 2 * j 即為解
- [main.cpp](main.cpp)
  - dp[i][j]: 前 i 個挑出一部分和不大於 j 的最大和
    - = 0 if i = 0
    - = dp[i - 1][j] if j < a[i]
    - = max(dp[i - 1][j], dp[i - 1][j - a[i]] + a[i]) otherwise
  - sum - 2 * dp[n][sum / 2] 即為解
