# Assignment 17 - Night Market

簡單來說就是邊的總長乘二扣掉直徑
至於找直徑的方法一般來說有兩種

- [main.c](main.c) - 對於每個點都去算以其為根的子樹當中有經過該點的最長路徑
- [main.cpp](main.cpp) - DFS 找出最遠的點再從它開始 DFS 找出最長路徑
