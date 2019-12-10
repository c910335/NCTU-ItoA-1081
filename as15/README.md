# Assignment 15 - Assignments 4

- assignments 以 score 大到小排序
- 用 disjoint sets 記錄 1...n 每個位置往前找到第一個空位的位置
- 依序處理每個 assignment
  - 若 deadline >= n 則一定能完成
  - 若 deadline < n 則利用 disjoint sets 把它放到不超過 deadline 的最後一個空位
    - 若沒空位則放棄
