Design Patterns - tried and tested solutions to common software design problems 

- templates NOT code
- provides a structured approach to building flexible code

Types of patterns

- Structural
- Creational
- Behavioral


#### Creational

Purpose

- Handle object creation and initialization (flexibility & reuse)

Types

- Singleton
  - only one instance of a class exists and provides a global access point
    
- Factory Method
  - defines an interface for creating objects, letting subclasses decide the instantiation
    
- Abstract Factory
  - provides a way to create families of related objects without specifying their concrete classes
   
- Builder
  - Contructs complex objects, step by step

- Prototype
  - creates new objects by copying a existing instance
 
#### Structural

Purpose

- simplify design by defining relationships between entities

Types

- Adapter
  - converts the interface of one class to on of another as expected by the client
 
- Bridge
  - separates abstraction from implementation, allowing them to vary independently
 
- Composite
  - treats individual objects and groups of objects uniformly (tree structures)
 
- Decorator
  - adds behavior to objects dynamically without altering their structure
 
- Facade
  - provides a simplified interface to a complex system of classes
 
- Flyweight
  - Shares objects to minimize memory usage
 
- Proxy
  - provides surrogate or placeholder to control acces to an object
 
#### Behavioral

Purpose

- Focus on interaction and communication between objects

Types

- Chain of responsibility
  - passes a request onto a chain of handlers until one handles it
 
- Command
  - Encapsulates a request as an object, allowing parameterization and queuing of requests
 
- Iterator
  - provides a way to sequentially access elements of a collection without exposing it implementation
 
- Mediator
  - Centralizes communication between objects    
