# Assignment 1 - Recurrences

在德國的樂透中你必須從 1 到 49 號之中選出六個數字。玩樂透有一個很普遍的策略（雖然不會增加你贏的機會），就是選擇一個子集合 ![S](https://render.githubusercontent.com/render/math?math=S) 包含 49 個數字裡面的 ![k](https://render.githubusercontent.com/render/math?math=k) (![k > 6](https://render.githubusercontent.com/render/math?math=k%20%3E%206)) 個數字，然後只從 ![S](https://render.githubusercontent.com/render/math?math=S) 裡面選擇 6 個數字，重複玩很多次。

例如，![k=8](https://render.githubusercontent.com/render/math?math=k=8) 且 ![S](https://render.githubusercontent.com/render/math?math=S) ![=](https://render.githubusercontent.com/render/math?math==) {![1,2,3,5,8,13,21,34](https://render.githubusercontent.com/render/math?math=1,2,3,5,8,13,21,34)}，總共有 28 種組合: [1,2,3,5,8,13], [1,2,3,5,8,21], [1,2,3,5,8,34], [1,2,3,5,13,21], ..., [3,5,8,13,21,34]。

你的工作就是寫一個程式，讀入 ![k](https://render.githubusercontent.com/render/math?math=k) 以及 ![S](https://render.githubusercontent.com/render/math?math=S)，然後印出所有可能的組合。

## Input

有好幾組測資。每一組測資會先給一個整數 ![k](https://render.githubusercontent.com/render/math?math=k) ![(6 < k < 13)](https://render.githubusercontent.com/render/math?math=(6%20%3C%20k%20%3C%2013))，接著之後的 ![k](https://render.githubusercontent.com/render/math?math=k) 個整數就是集合 ![S](https://render.githubusercontent.com/render/math?math=S) (數字由小排到大)。![k=0](https://render.githubusercontent.com/render/math?math=k=0) 代表輸入結束。

## Output

對於每組測資，印出所有可能的組合（一行印一種組合）。每一種組合的數字要從小到大印出，每個數字之間要用一個空白隔開。所有的組合必須要根據字典順序印出，也就是先從最小的數字當作排序的依據，相等的時候再根據第二小的數字，依此類推。每一組測資的輸出要用一個空行隔開。不要在最後一組測資的輸出之後多印一個空行。

## Sample Input #1

```
7 1 2 3 4 5 6 7
0
```

## Sample Output #1

```
1 2 3 4 5 6
1 2 3 4 5 7
1 2 3 4 6 7
1 2 3 5 6 7
1 2 4 5 6 7
1 3 4 5 6 7
2 3 4 5 6 7
```

## Sample Input #2

```
7 1 2 3 4 5 6 7
8 1 2 3 5 8 13 21 34
0
```

## Sample Output #2

```
1 2 3 4 5 6
1 2 3 4 5 7
1 2 3 4 6 7
1 2 3 5 6 7
1 2 4 5 6 7
1 3 4 5 6 7
2 3 4 5 6 7

1 2 3 5 8 13
1 2 3 5 8 21
1 2 3 5 8 34
1 2 3 5 13 21
1 2 3 5 13 34
1 2 3 5 21 34
1 2 3 8 13 21
1 2 3 8 13 34
1 2 3 8 21 34
1 2 3 13 21 34
1 2 5 8 13 21
1 2 5 8 13 34
1 2 5 8 21 34
1 2 5 13 21 34
1 2 8 13 21 34
1 3 5 8 13 21
1 3 5 8 13 34
1 3 5 8 21 34
1 3 5 13 21 34
1 3 8 13 21 34
1 5 8 13 21 34
2 3 5 8 13 21
2 3 5 8 13 34
2 3 5 8 21 34
2 3 5 13 21 34
2 3 8 13 21 34
2 5 8 13 21 34
3 5 8 13 21 34
```
