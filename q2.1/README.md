# Quiz 2.1 - Maximum Matching on a Tree

1. 以 Dynamic Programming 的角度來解這題
    - 對於每個節點都計算出以其為根的子樹的 maximum matching 以及該 matching 是否得用到此節點
2. 以 Greedy 的角度來解這題
    - 對於一個葉子
        - 如果父節點沒配對，和它配對一定比較好
        - 如果父節點有配對，換成和葉子配對不會比較差
    - 也就是說不斷讓葉子和其父節點配對就行了

- [main.c](main.c) - DP
- [main.cpp](main.cpp) - 以 queue 維護葉子列表
- [main2.cpp](main2.cpp) - 以 stack 維護葉子列表
- [main2.c](main2.c) - DFS 走回來的時候讓葉子和其父節點配對
