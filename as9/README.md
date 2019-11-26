# Assignment 9 - Summation 3

- dp[i]: 前 i 個的最佳解（先不考慮環狀）
  - = a[0] if i = 0
  - = max(a[0], a[1]) if i = 1
  - = max(dp[i - 1], dp[i - 2] + a[i]) otherwise

然後去頭去尾各跑一次取大的
