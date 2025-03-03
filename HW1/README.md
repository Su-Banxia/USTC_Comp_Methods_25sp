> 给定如下级数，取其近似值，要求截断误差在$10^{-6}$以内
>
> $\psi(x)=\sum\limits_{k=1}^\infty\frac{1}{k(k+x)}$

通项函数非负且单减，其余项$R_{n}$满足：
$$
R_{n}≤\int_{N}^{\infty}\frac{1}{t(t+x)}dt≤10^{-6}
$$
积分得：
$$
\begin{cases}
\frac{1}{x}\ln(1+\frac{x}{N})\le10^{-6} & x≠0 \\\\
\frac{1}{N}\le 10^{-6} & x=0\\
\end{cases}
$$
得到：
$$
\begin{cases}
N > \frac{x}{e^{x·10^{-6}}-1} & x≠0 \\\\
N > 10^6 & x=0
\end{cases}
$$
代码：

```c++
int find_k(double x)
{
    if (x == 0)
    {
        return 1e+6;
    }
    else
    {
        return x / ( exp( x * (1e-6)) - 1 ) + 1;
    }
}

```

