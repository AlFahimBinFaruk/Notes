* A child class inherit from multiple parent class.
```py
class Animal:
    def speak(self):
        print("Animal makes a sound.")

class Mammal:
    def walk(self):
        print("Mammal walks on land.")

class Dog(Animal, Mammal):
    def bark(self):
        print("Dog barks!")

# Usage
dog = Dog()
dog.speak()  # Inherited from Animal
dog.walk()   # Inherited from Mammal
dog.bark()   # Dog-specific method
```
