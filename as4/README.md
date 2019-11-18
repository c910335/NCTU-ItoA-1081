# Assignment 4 - Finding Max

You are given an integer array ![num[0...n-1]](https://render.githubusercontent.com/render/math?math=num[0...n-1]) and several queries. There are two types of queries and each query contains three integers ![i](https://render.githubusercontent.com/render/math?math=i), ![j](https://render.githubusercontent.com/render/math?math=j) and ![k](https://render.githubusercontent.com/render/math?math=k).

For  the first type of query ![(i = 1)](https://render.githubusercontent.com/render/math?math=(i%20=%201)), you have to **modify**  ![num[j]](https://render.githubusercontent.com/render/math?math=num[j]) to ![k](https://render.githubusercontent.com/render/math?math=k).

For the second type of query ![(i = 2)](https://render.githubusercontent.com/render/math?math=(i%20=%202)), you have to output the **maximum** element between indices ![j](https://render.githubusercontent.com/render/math?math=j) and ![k](https://render.githubusercontent.com/render/math?math=k).

## Input

The input begins with two integers ![n](https://render.githubusercontent.com/render/math?math=n) and ![m](https://render.githubusercontent.com/render/math?math=m) indicating the size of the integer array ![num](https://render.githubusercontent.com/render/math?math=num) and the number of queries respectively.

The next line contains ![n](https://render.githubusercontent.com/render/math?math=n) integers which are the elements of ![num](https://render.githubusercontent.com/render/math?math=num).

Each of the following ![m](https://render.githubusercontent.com/render/math?math=m) lines contains three integers ![i](https://render.githubusercontent.com/render/math?math=i), ![j](https://render.githubusercontent.com/render/math?math=j) and ![k](https://render.githubusercontent.com/render/math?math=k) indicating a query.

- ![1 \leq n \leq 3 \times 10^5](https://render.githubusercontent.com/render/math?math=1%20%5Cleq%20n%20%5Cleq%203%20%5Ctimes%2010%5E5)
- ![1 \leq m \leq 3 \times 10^5](https://render.githubusercontent.com/render/math?math=1%20%5Cleq%20m%20%5Cleq%203%20%5Ctimes%2010%5E5)
- ![-10^9\leq num[r] \leq 10^9](https://render.githubusercontent.com/render/math?math=-10%5E9%5Cleq%20num[r]%20%5Cleq%2010%5E9), ![\forall r\in \[0, n)](https://render.githubusercontent.com/render/math?math=%5Cforall%20r%5Cin%20[0,%20n))
- ![0 \leq j \leq n - 1](https://render.githubusercontent.com/render/math?math=0%20%5Cleq%20j%20%5Cleq%20n%20-%201), ![-10^9\leq k \leq 10^9](https://render.githubusercontent.com/render/math?math=-10%5E9%5Cleq%20k%20%5Cleq%2010%5E9), when ![i = 1](https://render.githubusercontent.com/render/math?math=i%20=%201)
- ![0 \leq j \leq k \leq n-1](https://render.githubusercontent.com/render/math?math=0%20%5Cleq%20j%20%5Cleq%20k%20%5Cleq%20n-1), when ![i = 2](https://render.githubusercontent.com/render/math?math=i%20=%202)

## Output

For each query with ![i = 2](https://render.githubusercontent.com/render/math?math=i%20=%202), output the maximum element between  indices ![j](https://render.githubusercontent.com/render/math?math=j) and ![k](https://render.githubusercontent.com/render/math?math=k) in one line.

## Sample Input #1

```
3 2
9 5 0
1 0 7
2 0 2
```

## Sample Output #1

```
7
```

## Sample Input #2

```
5 3
2 0 5 13 8
2 2 3
1 1 15
2 0 4
```

## Sample Output #2

```
13
15
```
