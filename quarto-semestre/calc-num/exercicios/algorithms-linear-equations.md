%title: methods to solve linear equations
%author: haru02w

# -> Gauss Elimination <-

1. Create an argumented Matrix

*x + 2y = 3   ==> | 1 | 2 || 3 |*
*2x + 4y = 1  ==> | 2 | 4 || 1 |*

^

2. Turn every element below the diagonal into zero
*i == element at the diagonal*
*j == element below the diagonal*

```
         _______-> scaling factor
j - i \* (j / i) == 0
```
p.s. if a element was changed, all elements of the line must be changed as well
p.s. scaling factor doesn't change to all other elements of the row

3. use `backwords substitution` to solve for all unknowns!
