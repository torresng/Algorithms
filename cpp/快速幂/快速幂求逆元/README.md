# 876. 快速幂求逆元

给定*n*组*a**i*,*p**i*，其中*p**i*是质数,求*a**i*模*p**i*的乘法逆元，若逆元不存在则输出impossible。

**注意**：请返回在0∼*p*−1之间的逆元。

##### 乘法逆元的定义

> 若整数*b*，*m*互质，并且*b*|*a*，则存在一个整数*x*，使得*a*/*b*≡*a*∗*x*(*m**o**d* *m*)，则称*x*为*b*的模*m*乘法逆元，记为*b*−1(*m**o**d* *m*)。
> *b*存在乘法逆元的充要条件是*b*与模数*m*互质。当模数*m*为质数时，*b**m*−2即为b的乘法逆元。

#### 输入格式

第一行包含整数*n*。

接下来*n*行，每行包含一个数组*a**i*,*p**i*，数据保证*p**i*是质数。

#### 输出格式

输出共*n*行，每组数据输出一个结果，每个结果占一行。

若*a**i*模*p**i*的乘法逆元存在，则输出一个整数，表示逆元，否则输出impossible。

#### 数据范围

1 ≤ *n* ≤ 10^5,
1 ≤ *a**i*, *p**i* ≤ 2∗10^9

#### 输入样例：

```
3
4 3
8 5
6 3
```

#### 输出样例：

```
1
2
impossible
```