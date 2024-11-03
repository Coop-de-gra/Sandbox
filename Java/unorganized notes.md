## notes

source: https://mylearn.oracle.com/ou/learning-path/java-explorer/79726

* Java API Documentation SE17

## What is a Java Program

* JVM is platform specific, JDK is platform independent. Byte code translated to machine code through JVM. Compile once method
* Class name begins with Capital letter ex. `public class Customer`
  * houses Data (fields), and Operations (methods)
* Package name begins with lowercase latter ex. `package customer.choice'
  * Package provides organization and grouping for classes
* Class = blueprint; Object = instance of the blueprint
## Handling Text and Numbers

#### Variables

* Variable refers to something that can change
  * initialized with a value
  * able to change
  * data specific identifiable
  * `Typeofdata variableName = variable value`; ex. `String firstName = "Mary";`
  * String, int, double, bool
  * camelCase
  * declared = `String customer;`
  * initalized & declared = `String customer = "Barbara"`

#### Data types and constants

* Primitive Data types
* Can't use methods with primitives
  * Integral (byte, short, int, long)
  * Floating point (float, double)
  * Textual (char)
  * Logical (boolean)
* values that shouldn't change should use the `final` keyword and be capitalized with underscore spaces ex. `final int DAY_COUNT = 28`
* String can be compared using operations `.equals` or `.equalsIgnoreCase`
* String is considered a system Class in Java that comes with Methods used to manupulate strings

#### Arrays Conditions & Loops

* Flow Control
  * if else (&&, ||, !)
    * both of the following are equal
    * ```
      boolean largeVenue
      if (attendees >= 5 && fee > 25){
        largeVenue = true;
      else {
        large venue = false;
      ```
     * `boolean largeVenue = (attendees >= 5 && fee > 25);`
   * short hand for if/else - Ternary Conditional Operator (?)
     * ` z = (y < x) ? x : y; ` - if y is less than x, set z equal to x, otherwise, set z equal to y
     * useful for simple if/else statements
   * switch statement
     * easier to read then if/else
     * offers better performance
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
* Arrays
  * manipulate multiple values programatically
  * coded like ` String[] names = {"Mary", "Bob", "Kelly"};` or `int[] ages = {25, 27, 48};`
  * or to leave it open-ended and assign variables at a later date
  * ```
    int[] ages1 = new int  [3];
    ages1[0] = 10;
    ages1[1] = 14;
    ages1[1] = 27;
    ```
    
* Loops
  * repeat blocks of statements until an expression is false or until x # of loops is reached
  * While loop - evaluates expression and then executes expression
  * do/while loop - executes at least once and then evaluates expression
  * for loop - repeats # of times
  * for each loop - iteration through collection of values (array)
  * *break* is a way of terminating the loop

## Defining classes and Creating Objects

* Modeling Classes
  * Class - blueprint that lays out the properties and behaviors of a future something
    * used at runtime for JVM to create new object instances
  * Object - an instance of a specific class
  * Classes are modeled using Unified Modelling Language diagrams

  * Class structure
    * Class decleration, Field definitions, Method definitions
    * ```
      //This is the decleration
      
      Class Customer

        //this is the start of the field definitions

        String name; 
        String Size = "S";

      //this is the start of the method definitions

      void serSide(string newSize) 
        size = newSize;

      String getSize()
        return size;
      ```
      
  * Methods
    * reusable unit of logic, distributes work performed by program, implements object behaviors
    * ```
      public void printWishlist ()
        String[] list = {"Golden Hat",  "Iron Boots"};
        for (String idea: list)
          System,out.println(idea);

      public double  getTotal (double price, int quantity)
        double total = price*quantity*tax;
        return  total;
      ```
    * `pubic` - access modifier
    * `printWishlist` - Name
    * `String[]... - println(idea;` Method Body
    * `double` return type
    * `(double price, int quantity)` Parameters
    * `return total` return statement

 * Scope and  Access
   * variables can only exist in the methods that call them
   * Parameters and Instance variable should not be named the same
   * access modifiers (public, protected, private, default)
     * public - all classes
     * protected - classes in the same package and subclasses
     * private - same class
     * default - same package
   * access modifiers enforce **encapsulation** //process by which methods and variables operate on data within one unit (class)
     * very organized
     * hiding variables and allowing access to data through methods only
     * creats stable and solid design
     * wont break code when changes are made to it
     * ex.
     * ```
       public class Clothing {
         private double price;
         public final double MIN_PRICE = 1.0;
         public final double TAX = 0.2;
         public void setPrice(double newPrice) {
           price = (newPrice > MIN_PRICE) ? newPrice : MIN_PRICE;
         }
         public double getPrice() {
           return price + price * TAX;
         }
       }
       ```
      * and
      * ```
        public class Shop {
          public static voide main(string() args) {
            Clothing c = new Clothing();
            c.setPrice(0.99);
            double total = c.getPrice();
        ```
  * Object instances
    * The dot operator (.) accesses the methods and fields of an object
    * array of objects - manage multiple instances of an object w/o creating seperate variables
   
## Working with Objects

  * Working with object references
    * An object reference works by referencing a variable that has a reference to an object in memory
    * following example: create new TV object ~ call on the method ~ TV is turned on 
    * ```
      TV remote1 = new TV();
      remote1.on();
      ```
    * two areas of memory created by JVM
      * stack (stores the variables)
      * heap (stores the objects)
    * Arrays are handled by an implicit array object
      * stored in the heap (object)
      * must be called like objects are called
   
  * Initialize objects with Constructor Method
    * Constructor methods are great for initialization and house keeping when the object is first created
    * constructor initializes an objects state
    * constructor is called automatically when the **new** keyword is used
    * ```
      public static void main (String[] args)
        Clothing item1 = new Clothing()
        Clothing item2 = new Clothing("Jacket", 20.99, "M")
      ```
  * Static Modifier
    * ```
      public class Example {
      public static int counter = 0;
      ```
    * means that the method/variable belongs to the class and is shared by all objects of the class
    * not specific to any object instance and belongs to all objects of a class
    * can be accessed without instantiating the class (Example myExample = new Example("Ex.")
    * Use Cases
      * method/variable belongs to a class (not object)
    * Ex.
      * ```
        public static void main(...)
        ```
      * `public` anybody can call this
      * `void` returns nothing
      * `main` name of the method
      * `static` indicates this is a `main` method on the Class (does not instantiate the class)
        
## Handling Exceptions

  * how java navigates unexpected sutiations
  * java creates an exception and then throws code at it and waits for an outcome
    * ex. looking for a file that dosent exist; looking for a number that is null; divides by zero; access a missing array index
  * **try/catch** block is how to handle exceptions
    * ```
      try {
        ...
        ...
      }
      catch (ExampleException e) {
      String errMsg = e.getMessage();
      e.printStackTrace();
      }
      catch (Exception e) {
      ...
      }
      ```
    *  NOTE: do not use these to fix programming mistakes - use it to **solve** them

## Object-Oriented Approach to Code Reuse

  * Inheritance
    * Classes form hierarchical relationships
    * Superclass is a parent type in the hierarchy and define common attributes and behaviors
    * subclass is a child type in the hierarchy and define specific attributes and behaviors
    * (object is the top-level class in the hierarchy)
      
  * Extending classes and Reusing Superclass Logic
    * a subclass inherits code of its parent suparclass and lays it alongside its own
    * the `extends` object is used to inherit
    * ```
      public class Dog aextends Animal {
      ...
      }
      ```
    * using the `super.` accesses data within the parent of the child
    
  * Polymorphism
    * core concept of object oriented programming
    * objects are treated as instances/interfaces of their parent class
    * two types: Moethod overloading & Method Overriding
      * Overloading - multiple methods have the same name but different parameters within the same class
      * Overriding - subclass provides specific implementation for a methods defined in the superclass
      * it is recommended that all Java classes override some operations defined by the object class (for ex.
        * ```
          public class CLothing }
            public String toString() {
              return description + ", " + price;
            }
          }
          ``` 
        * ```
          public class Shop {
            public static void main(string[] args) {
              Clothing tShirt = new Standard ("Java T-Shirt", 20.99);
              System.out.println(tShirt)
          ```
        * output: Java T-Shirt, 20.99

  * Abstract Classes
    * `Abstract` used to encourage class extensibility
      * becomes a design structure and a placeholder for code that we want subclasses to specifically implement
    * A sound subclass must **override** (polymorphism) all abstract methods of their abstract parent
      * ```
        public abstract class Clothing {
          public abstract double refund();
        }
        ```
      * ```
        public class Tailored extends Clothing {
          public double refund () {
            return 0
          }
        }
        ```
      * even though `refund` is abstract in Clothing, its required to be defined in Tailored (by any means really, hence `return 0`)
     
  * Interfaces (implementing common behavior)
    *  way to abstract out or define behavior thats common in multiple classes (specifically classes that are not part of the same class hierarchy)
    *  another way to use polymorphism
    *  resemble an abstract class, except no variables or regular concrete methods are allowed
    *  they can however contain constants and concrete methods (default, private, static)
      *  ```
         public interface Recyclable {
           void recycle();
         }
         ```
       * ```
         public class Clothing implements Recyclable{
           public void recycle() {
             ... clothing specific implementation ...
           }
         }
         ```
       * ```
         public class Bottle implements Recyclable
           public void recycle() {
             ... bottle specific implementation ...
           }
         }
         ```
     * Sometimes classes need inheritance from more than one parent (which isnt through simple inheritance)
     * this is where interfaces come in since classes can inherit as many iterfances as required
       * ```
         public class Clothing implements Recyclable, Comparable {
           public void recycle() {
             ...
           }
           public void compareTo(Object other) {
             ...
           }
         }
         ```
       * ```
         Recyclable[] rubbish = new Recyclable[3]
         rubbish[0] = new Tailored()
         rubbish[1] = new Stardard()
         rubbish[2] = new Bottle()
         for (Recyclable item: rubbish) {
           item.recycle()
         }
         Arrays.sort(rubbish)
         ```
       * `for (Recyclable item: rubbish) {` looks through array and JVM says hey `item` what are you? item says im `Tailored`, then it calls the recycle method from the Tailored class
       * then it walks through the rest of the array and asks the same questions
     * 
 
