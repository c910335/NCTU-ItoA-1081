# Assignment 3 - Inversions

The **inversion number** – the count of **inversions** of an array – is a common measure of the unsortedness of an array.  
Given an array ![a](https://render.githubusercontent.com/render/math?math=a), find the **inversion number** of ![a](https://render.githubusercontent.com/render/math?math=a).

We call a pair ![(i, j)](https://render.githubusercontent.com/render/math?math=(i,%20j)) an **inversion** if ![i < j](https://render.githubusercontent.com/render/math?math=i%20%3C%20j) and ![a_i > a_j](https://render.githubusercontent.com/render/math?math=a_i%20%3E%20a_j).

## Input

Input begins with ![n](https://render.githubusercontent.com/render/math?math=n) which indicates the size of ![a](https://render.githubusercontent.com/render/math?math=a).  
The next line contains ![n](https://render.githubusercontent.com/render/math?math=n) integers which form ![a](https://render.githubusercontent.com/render/math?math=a).

<br>

- ![2 \leq n \leq 10^7](https://render.githubusercontent.com/render/math?math=2%20%5Cleq%20n%20%5Cleq%2010%5E7)

- ![-10^8 \leq a_i \leq 10^8](https://render.githubusercontent.com/render/math?math=-10%5E8%20%5Cleq%20a_i%20%5Cleq%2010%5E8)

## Output

Output the **inversion number** of ![a](https://render.githubusercontent.com/render/math?math=a)  
As the number can be quite large, output it **modulo** ![524287](https://render.githubusercontent.com/render/math?math=524287).

## Sample Input #1

```
4
4 3 2 1
```

## Sample Output #1

```
6
```

## Sample Input #2

```
6
4 5 10 4 7 1
```

## Sample Output #2

```
8
```
