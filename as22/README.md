# Assignment 22 - Aye Congratulations

把每個 prop 和 item 都當成是一個節點  
另外新增源點和匯點  
每個 item 都以 expected profit 為容量接上匯點  
每個 prop 都以 cost 為容量接上源點  
每個 item 和 prop 的相依關係都在它們之間建一條無限容量的邊  
這張圖的 min cut = max flow 就會是最佳解所需 props 的 cost 加上不在最佳解之中 items 的 expected profit  
也就是說所有 expected profit 的和減掉 max flow 即為所求

- [main.c](main.c) - Dinic
- [main.cpp](main.cpp) - Edmonds-Karp
