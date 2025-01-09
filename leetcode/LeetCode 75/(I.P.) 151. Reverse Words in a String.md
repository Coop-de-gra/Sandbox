### 151. Reverse Words in a String

https://leetcode.com/problems/reverse-words-in-a-string/description/?envType=study-plan-v2&envId=leetcode-75

### algo (personal try)

* convert string into char
* two pointers that work front to back and stop at spaces
* every char between spaces will be collected
* when it reaches a space it waits for the other pointer
* then the two pointers switch the words and index one char foward and repeat the algo
* two pointers stop when they become equal
* char is converted to string and outputted

### strat (personal try)

* `getChars()` - Copies characters from a string to an array of chars
* `toCharArray()` - Converts this string to a new character array
* `isEmpty()` - Checks whether a string is empty or not

### inital code 
```
class Solution {
    public String reverseWords(String s) {
        
    }
}
```
