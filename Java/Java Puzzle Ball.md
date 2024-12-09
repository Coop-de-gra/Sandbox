# Java Coding & Concepts with a Game: Java Puzzle Ball

https://apexapps.oracle.com/pls/apex/f?p=44785:50:112868272522157:::50:P50_EVENT_ID,P50_PREV_PAGE,P50_COURSE_ID:5710,175,134

## methodology

1. Play a puzzle
2. Watch a presentation
3. Code it yourself

//NOTE: Issue with WebGL on Oracle server - no game time BUT still have access to learnings

## Objects and Classes

the class is the blueprint and the object is the instance 

combinations of properties and behaviors fundamentally define an object

there can be many instances of the same object

all instances of the same object type, share the same behaviors

properties are referred to as *fields*

objects are referred to as *methods*

```
public class BlueBumper {              /
  private Color color = Color.Blue;    /
  private Shape shape = Shape.RECT;    /  THESE ARE THE PROPERTIES (fields)
  private int xPosition;               /
  private int yPosition;               /


  public void ping(){                  /
    System.out.Println("Ping")         /
  }                                    /
  public void flash(){                 /  THESE ARE THE BEHAVIORS (methods)
    System.out.println("Flash")        /
  }                                    /
}
```
