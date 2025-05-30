* A class inherits from another class, which in turn inherits from another class, forming a chain.
```py
class Animal:
    def speak(self):
        print("Animal makes a sound.")

class Mammal(Animal):
    def walk(self):
        print("Mammal walks on land.")

class Dog(Mammal):
    def bark(self):
        print("Dog barks!")

# Usage
dog = Dog()
dog.speak()  # Inherited from Animal
dog.walk()   # Inherited from Mammal
dog.bark()   # Dog-specific method
```
