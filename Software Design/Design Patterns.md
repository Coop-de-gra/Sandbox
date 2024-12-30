Design Patterns - tried and tested solutions to common software design problems 

- templates NOT code
- provides a structured approach to building flexible code

Types of patterns

- Structural
- Creational
- Behavioral
- Concurrency


#### Creational

_Purpose_

- Handle object creation and initialization (flexibility & reuse)

_Types_

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

_Purpose_

- simplify design by defining relationships between entities

_Types_

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

_Purpose_

- Focus on interaction and communication between objects

_Types_

- Chain of responsibility
  - passes a request onto a chain of handlers until one handles it
 
- Command
  - Encapsulates a request as an object, allowing parameterization and queuing of requests
 
- Iterator
  - provides a way to sequentially access elements of a collection without exposing it implementation
 
- Mediator
  - Centralizes communication between objects    

#### Concurrency

_Purpose_

- addresses multi threading and synchronization patterns

_Types_

- Thread pool
  - reusues a fixed # of threads for executing tasks
 
- Producer-Conosumer
  - manages communication between threads via shared resources
 
- Read-Write lock
  - optimizes thread safe access by allowing mulitple readers or one writer at a time to
 
- Future
  - handles asynchronous computation results

