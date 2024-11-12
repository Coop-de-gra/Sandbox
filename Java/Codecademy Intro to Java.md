## Source

* https://www.codecademy.com/courses/learn-java/lessons/hello-world-java/exercises/introduction-to-java

## Unorganized notes

* slogan - "write once, run everywhere"
    * thanks to JVM

* Java file compiled into a class file (byte code) which is then translated into respective machine code via JVM
    * javac filename.java - compiles the code
    * java filename - runs program

* Each file has atleast one class and one main method
    * one primary class named after the file itself
    * `main` method that runs the tasks of the program

* `Strings[] args` is a placeholder for information we want to pass to that class
```
public static void main(String[] args) {

}
```

* breaking down the following code
```
System.out.println("Let's play hide and seek.");
```
* `System` - built in Java Class
* `out` - variable in the System class, public static field of the system class, represents instance of PrintStream (class used to output data)
* `println` - method in PrintSteam class

* Class -> Variable -> Method
* Each step in is accessible through dot syntax

* print() outputs argument, dosen't break line
* println() breaks line and starts the next line

* single line comments use `//ex. comment`
* multi line comments use
```
/*
test
test
ex. comment
test
test
*/
```

* javadoc comments are represented by /** and */
    * not important now, but useful in future

 * curly braces `{}` mark the scope of each class and method

### Variables

* variables are stored with primitive data types (int, bool, double, etc.)

#### ints

* ints hold positive, negative, and zero numbers
* can't hold decimals
* ints range is from -2.5 bil to +2.5 bil

#### double

* same characteristics as ints, used for decimals numbers

#### booleans

* true of false

#### char

* hold any character data
* surround the character with apostrophes and not quotations

#### String

* `String` is capitalized because its actually and Class and not a primitive data type (common misconception)
* it also has its own methods and properties (length(), substring(), toUpperCase(), ex) (not possible with primitives)
* dont need to surround with () when declaring BECAUSE its not a primitive

### Manipulating Variabels

* modulo `%` finds the remainder
  
* compound assignment operators
   * `numCookies -= 3;` easy way of subtracting 3 from variable
   * same theory applies to all the other operators
 
* can use `>` or `<` operators in print statements to return `true` or `false
   * ex `System.out.print(creditsEarned > creditsToGraduate);` prints `false` in the terminal
 
* dont forget `==`, `!=`, `>=`, `<=`, `++`

* `.equals()` operator works similarly to `==`
   * ex. `System.out.println(person1.equals(person2));`
 
* `final` keyword used to

### Classes
https://www.codecademy.com/courses/learn-java/lessons/java-introduction-to-classes/exercises/introduction-to-classes
* 
