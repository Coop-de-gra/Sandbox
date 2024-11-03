# organized notes

source: https://mylearn.oracle.com/ou/learning-path/java-explorer/79726

* Java API Documentation SE17

## basics of a java program

* Java is a two step language: **compile and interpret**
  * Code is developed in and Integrated Development Environment (IDE) using the Java Development Kit (JDK)
  * When ***compiling***, the JDK converts the code into byte code
  * the byte code can then be taken an run on any Operating System (OS) via a Java Virtual Machine (JVM)
  * The JVM takes the byte code and ***interprets*** it to OS specific machine code
</br></br>

## influencing text and numbers

#### variables
* a named container that holds a value
* each variable has a data type (Primitive or Reference)
  * Primitive = `double`, `float`, `int`,`byte`,`short`,`long`, `char`, `bool`
  * Reference = store a memory address and refer to things (like objects) instead of holding values
* if you don't want the variable to change, use the `final` modifier
  * final variables are names with all capitals, ex. `final int = FINAL_VALUE`
* String is considered a Java system class that comes with its own methods
  * because string is a class, it will always be typed with a capital S

## parts of a method
#### access modifiers

* `public`, `private`, `protected`

#### return type

* `void` : no value will be returned
* `int, string, etc.` : method will return a value of this type

#### method name

* short, to the point, following camelCase
* `calculateSum`, `printMessage`

## `main` method

* first method that the JVM looks for - won't run without one
* executes code inside `main` sequentially

```
public class HelloWorld {

    public static void main(String[] args) {
        System.out.println("Hello, world!");
    }
}
```

## flow control
* Flow control in Java is the mechanism that dictates the order in which code is executed
* Flow control enables programs to make decisions, repeat actions, and handle conditions dynamically

#### conditional statements
  * `if/else`  executes on whether conditions are true or false (&&, ||, !)
  * good ex. `z = (y < x) ? x : y;` - "if y is less than x, set z equal to x, otherwise, set z equal to y"
    
    * ```
      bool largeVenue;
        if (attendees >= 5 && fee > 25){
          largeVenue = true;
        } else {
          largeVenue = false;
        }
      ```
  * `swtich: case` chooses actions based on multiple options
    
    * ```
      switch (condition) {
        case "Damaged" :
          ...
        case "Used" :
          ...
        default:
          ...
      }
      ```
#### loops   
  * `for/while/do-while loops`  repeat a block of code specific # of times or until a condition is met
    * `for` iterates a number of times & ideal for when **you know** the needed # of loops
      * ```
        for (int i = 0; i < 5; i++) {
          System.out.println("Iteration: " + i);
        }
        ```
    * `while` iterates a # of times & is ideal for when you **dont know** the needed # of loops
    * evaluates expression and then executes loop
      * ```
        int i = 1;
        while (i <= 5) {
          System.out.println("Number: " + i);
          i++;
        }
        ```
    * `do-while` similar to while
    * executes loop once and then evaluates expressions
      * ```
        int i = 1;
        do {
          System.out.println("Number: " + i);
          i++;
        } while (i <= 5);
        ```
    * `for-each` loops through elements in a collection or array
    * called an *enhanced for loop*
      * ```
        int[] numbers = {1, 2, 3, 4, 5};
        for (int num : numbers) {
          System.out.println("Number: " + num);
        }
        ```
#### branching statments
  * change the flow by altering the codes natural progression
  * `break` exits a loop or switch statment early
    * ```
      for (int i = 0; i < 10; i++) {
        if (i == 5) {
            break; // Exit the loop when i reaches 5
        }
        System.out.println("i: " + i);
      }
      ```
  * `continue` skips the current loop iteration and proceeds to the next one
    * ```
      for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            continue; // Skip even numbers
        }
        System.out.println("i: " + i);
      }
      ```
  * `return` exits a method and if applicable returns a value
    * ```
      public int square(int number) {
        if (number < 0) {
          return -1; // Exit early if the number is negative
          }
        return number * number; // Otherwise, return the square
      }

      ```

#### exception handling
  * controls the flow when errors or unexpected conditions occur
  * `try-catch-finally` allows code to handle potential runtime errors gracefully
  * not to be used as a substitution to fixing bad code
    * ```
      try {
        int result = 10 / 0; // Will cause an exception
      } catch (ArithmeticException e) {
        System.out.println("Division by zero is not allowed.");
      }
      ```
  * `throw` used when we want to explicitly thow an exception to aviod certain situations
    * ```
      public class Main {
        public static void checkPositiveNumber(int number) {
          if (number < 0) {
              // Throwing an exception if the number is negative
              throw new IllegalArgumentException("Number must be positive!");
          } else {
              System.out.println("The number is positive: " + number);
        }
      }
      ```
## arrays
  * fixed size containers that hold values of the same type
  * provide a way to organize data under a single variable name, with each item remaining accessible by its position in the array

#### initializing and declaring an array

  * specify its type and size
    * ```
      int[] numbers = new int[5];
      ```
  * access items via their index number
    * ```
      numbers[0] = 10; // Sets the first element to 10
      System.out.println(numbers[0]); // Prints 10
      ```
  * you can also initialize an array with all its values
    * ```
      int[] scores = {90, 85, 78, 88, 92};
      ```
  * arrays are often used in loops to process or access each element
    * ```
      for (int i = 0; i < scores.length; i++) {
        System.out.println("Score " + i + ": " + scores[i]);
      }
      ```
#### `ArrayList`

  * works like an array but is more flexible and easier to work with
  * useful when you need an array but dont know the # of items 
  * to use ArrayList, you need to import it
    * ```
      import java.util.ArrayList;
      ```
  * When initializing, you must specify the type of data
    * ```
      ArrayList<String> names = new ArrayList<>();
      ```
  * use the `add()` method to insert array elements
    * ```
      names.add("Alice");
      names.add("Bob");
      ```
  * 

## defining classes and creating objects

#### class

*blueprint that lays out the properties and behaviors for a future something*
  * helps with encapsulation - bundling related data and methods to create modularity
  * defined with the `class` keyword, followd by the class name
  * contains fields (variables) and methods (actions to be performed)
    
#### object

*an instance of a specific class*
  * using the `new` keyword, multiple unique objects can be made
  * ```
    Car myCar = new Car(); // Create a Car object  
    ```
  * you can access an objects fields and methdos by using a `.` operator
    * this allows to set or retrieve field values or call the methods into action
  * ```
    myCar.color = "red";        // Set the color of myCar
    myCar.speed = 60;           // Set the speed of myCar
    myCar.drive();              // Calls the drive method
    ```
#### constructors

*method that runs when an object is created*
  * allows you to set initial values for the fields
  * same name as the class but need no return type
  * ```
    public class Car {
      String color;
      int speed;
  
      // Constructor
      public Car(String color, int speed) {
          this.color = color;
          this.speed = speed;
      }
    }
    Car myCar = new Car("blue", 80); // Initializes color and speed
    ```
## encapsulation
* bundling of data and methods to restrict access to some of an objects components
* ensures that an objects internal state can be changed in controlled ways

#### how it works fundamentaly 

* Private variables
  * variables in a class are private so they cant be directly accessed
* Public methods
  * public "getter" and "setter" methods to control access

#### benefits
* controlled access, data validation, easier maintenance, improved security

#### example
```
public class BankAccount {
    private double balance; // Private field

    // Constructor to set the initial balance
    public BankAccount(double initialBalance) {
        this.balance = initialBalance;
    }

    // Getter method for balance
    public double getBalance() {
        return balance;
    }

    // Setter method to add money to the balance
    public void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }
}
```
    
## object modifiers
  * define rules around who can access or change parts of a class
  * control scope, lifespan, and mutability
    </br>
#### access modifiers
  * `public` accessible from any other class
  * `private` access within same class only
  * `protected` access within the same package and by the same subclasses
#### `static`
  * used on variables or methods
  * makes whatever belong to the class itself rather than instances (objects)
  * commonly used for shared data or utilities that dont depend on instance data
  * ```
    public static int sharedCounter = 0;
    public static void incrementCounter() {
        sharedCounter++;
    }
    ```
#### `final`
  * prevents a variable, method, or class from being changed or overridden
  * commonly used to define constants or restict inheritance
  * ```
    public final int MAX_SCORE = 100; // A constant
    ```
#### `abstract`
  * means a class or method must be implemeneted or extended by a subclass
  * used in inheritance to define general concepts in a superclass and require specific implementation in a subclass
  * ```
    public abstract class Animal {
    public abstract void makeSound(); // Must be implemented by subclasses
    }
    ```
## code re-use
#### inheritance ("is-a" relationship)
  * inherit properties and methohds from a parent class (super class) without re-writing code
  * use when classes are genuinely related by an "is-a" form of expressions
    * ex. car is-a vehicla, dog is-a animal
  * overusing can lead to rigid hierarchies
  * ```
    public class Vehicle {
      int speed;
      
      public void start() {
          System.out.println("Vehicle started");
      }
    }
   
    public class Car extends Vehicle {
        // Inherits 'speed' and 'start()' method from Vehicle
    }
    ```
#### composition ("has-a" relationship)
  * creating classes that contain instances of other classes
  * more flexible than inheritance
  * use when one class should contain or use another class
    * ex. car has-a enginge, house has-a room
  * ```
    public class Engine {
      public void startEngine() {
        System.out.println("Engine started");
      }
    }
    
    public class Car {
      private Engine engine;

      public Car() {
        engine = new Engine(); // Composition: Car has an Engine
    }

      public void start() {
          engine.startEngine();
          System.out.println("Car started");
      }
    }
    ```
#### interfaces and polymorphism
  * interfaces - allow multiple classes to share common behavior
  * polymorphism - enables methods to operate on objects of different classes than implement a shared interface
    </br>
  * promotes resuable and maintainable code
  * provides standardized way to implement functionality across unrelated classes
  * ```
    public interface PaymentMethod {
      void processPayment(double amount);
    }

    public class CreditCard implements PaymentMethod {
        public void processPayment(double amount) {
            System.out.println("Processing credit card payment: $" + amount);
        }
    }
    
    public class PayPal implements PaymentMethod {
        public void processPayment(double amount) {
            System.out.println("Processing PayPal payment: $" + amount);
        }
    }
    ```
#### delegation (sharing responsbilities)
  * lets an object pass off work to a helper class
  * keeps each class focusing on what its good at
  * code becomes simpler
  * encourages code reuse
  * ```
    public class Printer {
      public void printDocument(String content) {
          System.out.println("Printing: " + content);
      }
    }
      
    public class OfficeWorker {
      private Printer printer;  // Composition
  
      public OfficeWorker(Printer printer) {
          this.printer = printer;
      }
  
      public void printReport(String report) {
          printer.printDocument(report); // Delegation
      }
    }
    ```
      * `OfficeWorker` dosen't need to know how to print; just tells `Printer` how to do it 

## garbage collection

  * Java automatically garbage collects
  * its built in garbage collection periodically searches for unreferenced objects and recaimes the memory occupied

