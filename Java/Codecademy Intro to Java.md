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

* template for creating objects
      * object oriented programming -> objects are the lifeline of the programs
* outlines the necessary components and how they interact with eachother
* good example of class structure
      * https://www.codecademy.com/courses/learn-java/lessons/java-introduction-to-classes/exercises/introduction-to-classes

#### Constructors

* initialize fields when a class instance is created
* must have the same name as the class itself
* generally defined as `public`
```
public class Car { 
 
 public Car() { // Constructor

   // instructions for creating a Car instance 
 }   
}
```
```
public class Main{
  public static void main(String[] args){
    Car Supra = new Car(); 
  }
}
```
#### Instances

* characteristics of an object are known as instance variables or instance fields
* each object gets its own copy of the initial instance variables
'''
public class Dog{
  // below are the instances
  String name;
  String breed;
  double weight;

  public Dog(){
    // this object will have its own uniqque instance variables
  }
}
'''

#### constructor parameters

* parameters are placeholders we can use to pass information to a method
* two types of parameters: formal & actual
      * below, `String carColor` is a formal parameter because it will store data that is passed onto a method
* a method can be understood by its signature (Name, number of, and parameters of the method)
      * below, `Car(String carColor)` is the signature
```
public class Car { 
  public String color; 

  // constructor method with a parameter 
  public Car(String carColor) { 
    // parameter value assigned to the field 
    color = carColor; 
  } 
} 
```
* when we create the new instance of `Car`:
      * we pass onto it a String value through the constructor
      * we store it in in `CarColor`
      * we can now use it however we want so we assign it to the instance field color

#### assigning values to instance fields

* following the previous notes, the constructor will now accept values for parameters
* these values will be known as **arguments**
* following the past two examples, we will pass `red` as the `carColor parameter`
```
class Main{ 
  public static void main(String[] args){ 
  Car Supra = new Car("red"); 
  } 
}  
```
* also, we can now use dot operators to access the value, ex. `Supra.color;`

#### multiple fields within a class

* you can add differnt fields when initializng a class within the main method
* ex. `public Store(String product, int count, double price)`
```
//STORE CLASS
public class Store {
  // instance fields
  public String productType;
  public int inventoryCount;
  public double inventoryPrice;
  // constructor method
  public Store(String product, int count, double price) {
    productType = product;
    inventoryCount = count;
    inventoryPrice = price;
  }
}
```
```
//MAIN
public class Main{
  public static void main(String[] args) {    
    Store cookieShop = new Store("cookies", 12, 3.75);
  }
}
```

### methods

* repeatable, reusable, modular, blocks of code used to accomplish specific tasks
* a task that an object of a class performs
* method goal: `procedural abstraction` - knowing what a method does, but now how it accomplished it

#### defining methods

* `public void checkBalance()` is the method declaration
   * `public` - its viewable outside this class
   * `void` - no specific output
   * `checkBalance` - method name
```
public void checkBalance(){
  System.out.println("Hello!");
  System.out.println("Your balance is " + balance);
}
```

#### calling methods

* first reference the object, then we call the method, and connect them via dot operator
* code generally runs from top to bottom, but compilers ignore methods unless the are called

#### scope

* we cant access variables that are delared inside a method, ouside the scope of the method

#### parameters

* addiing parameters changes the methods signature
* parameters must be called in the order they are declared
* 
