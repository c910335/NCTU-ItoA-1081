# Quiz 2.5 - Bipartite Matching

新增一個源點接上所有左邊的點  
新增一個匯點接上所有右邊的點  
每個邊的 capacity 都設為 `1`  
這張圖的 maximum flow 即為解

- [main.c](main.c) - Dinic
- [main.cpp](main.cpp) - Edmonds-Karp
