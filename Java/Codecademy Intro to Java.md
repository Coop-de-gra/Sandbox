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
 * 
