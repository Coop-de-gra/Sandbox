**Source**

https://frontendmasters.com/courses/algorithms/
<p></p>

NOTE: AFTER COURSE, CREATE EACH ALGORITHM ON YOUR OWN

### Things to remember

#### Big O time complexity
_a way to generalize the growth of your alorgithm_

_understanding algorithms comes before understanding time complexity_

<br>

A. Growth is with respect to the input

B. simplest trick - Look for loops
  1. always ignore constants

C. Usually measure time complexity in _worst case scenario_

D. Examples

<br>1. O(N^2)
  
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
<br>2. O(N^3)

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

<br>3. O(n log n)
<br>4. O(log n)
<br>5. O(sqrt(n))

#### Arrays

* continuous and ubreaking memory space
* cannot grow it

## Algorithms

### A. Linear Search

* simplest way to sort through an array | | goes index by index within an array looking for a match to a value | | brute force essentially
  * time complexity = O(N) | | the more indexes it searched, the longer its gets (linear)

### B. Binary Search
_under the assumption the array is sorted_

* **10% Method** | | repeatedly move 10% into the array, see if x > or < v | | if x < v, search the last 10% for x = v
  * O(N) complexity
* **sqrt(max) Method** | | repeatedly move sqrt(max) into the array, see if x > or < v | | if x < v, search the last sqrt(max) for x = v
  * O(sqrt(N)) complexity
* **Halfing Method** | | keep halfing the array, see if x > or < v | | find the right fractional area and search for x = v
  * O(logN) or O(NlogN)(_if you're scanning_) complexity
  * midpoint algo | | m = [lo + (hi - lo)/2]
  * 2 crystal balls dropped from a 100 story building problem
 
### Bubble Sort

_an array is sorted if Xi is <= Xi + 1_

* **Nutshell** | | is index i <=  i + 1 | | if yes, look at i + 1 and ask the same thing to the following index
  * * O(n^2) time complexity

* first iteration will always produce the largest item in the last spot
* can be implemented in 2 for loops, 1 if statement, and 3 lines of code
* dont forget to create a temp variable for spot switching

## Data Structures

### Linked List 

* list of containered items 
 
