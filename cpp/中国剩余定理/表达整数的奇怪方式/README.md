# 204. 表达整数的奇怪方式

给定2n个整数*a*1,*a*2,…,*a**n*和*m*1,*m*2,…,*m**n*,求一个最小的非负整数x，满足∀*i*∈[1,*n*],*x*≡*m**i*(*m**o**d* *a**i*)。

#### 输入格式

第1行包含整数n。

第2..n行：每i+1行包含两个整数*a**i*和*m**i*,数之间用空格隔开。

#### 输出格式

输出最小非负整数x，如果x不存在，则输出-1。
如果存在x，则数据保证x一定在64位整数范围内。

#### 数据范围

1 ≤ *a**i* ≤ 2^31−1,

0 ≤ *m**i* < *a**i*

1 ≤ *n* ≤ 25

#### 输入样例：

```
2
8 7
11 9
```

#### 输出样例：

```
31
```