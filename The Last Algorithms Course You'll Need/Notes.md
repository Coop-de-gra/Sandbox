**Source**

https://frontendmasters.com/courses/algorithms/
<p></p>

#### Big O time complexity
<H6>a way to generalize the growth of your alorgithm</H6>

A. Growth is with respect to the input

B. simplest trick - Look for loops
  1. always ignore constants

C. Usually measure time complexity in _worst case scenario_

D. Examples
    1. O(N^2)

```
function sum_char_codes(n: string): number {
    let sum = 0;
    for (let i = 0; i < n.length; ++i) {
        for (let j = 0; j < n.length; ++j) {
            sum += charCode;
        }
    }

    return sum;
}
```
<br>
    2. O(N^3)
<br>

```
function sum_char_codes(n: string): number {
    let sum = 0;
    for (let i = 0; i < n.length; ++i) {
        for (let j = 0; j < n.length; ++j) {
            for (let k = 0; k < n.length; ++k) {
                sum += charCode;
            }
        }
    }
    return sum;
}
```
