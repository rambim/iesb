# Fibonacci

Studying and benchmarking Fibonacci sequence: finding its n-th element using **recursion**, **iteration** and a **closed form**.

> Available on Medium: https://medium.com/@marcellguilherme/fibonacci-9aded34b2fb6

Closed form demonstration: https://github.com/Mazuh/MyNotebook-Math/blob/master/files/discrete/fibonacci.pdf

## About Fibonacci sequence

It was created by an Italian mathematician, Leonardo of Pisa, who popularized the Hindu–Arabic numeral
system in the Western World on Middle Ages.

The n-th number of such sequence is equals to the sum of the two directly previous numbers,
assuming that the 1st and 2nd are both 1. That said, here's a few of them:

> 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89…

There's a way to describe it using this recurrence relation:

```
Let n be a natural number,
f(0) = 0
f(1) = 1
f(2) = 1
f(n) = f(n-1) + f(n-2), for n > 1
```

It's very common to see Fibonacci spiral...

![Graphic visualization of Fibonacci sequence](https://elearningindustry.com/wp-content/uploads/2017/09/dd7620fc0fceffcce27b5d11c5c01a96.png) 

... as an aproximation of the Golden Spiral:

![Golden Spiral animation](https://upload.wikimedia.org/wikipedia/commons/e/e9/GoldenSpiralLogarithmic_color_in.gif)

On Pascal Triangle too:

![Pascal Triangle with Fibonacci](https://upload.wikimedia.org/wikipedia/commons/b/bf/PascalTriangleFibanacci.svg)

And at the most unusual places:

![Seeing Fibonacci graphical pattern on Trump's head](https://qph.ec.quoracdn.net/main-qimg-0281d782e4ec471ce2d5091d2c40f1b5-c)
