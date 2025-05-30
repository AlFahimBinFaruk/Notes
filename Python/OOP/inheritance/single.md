```py
class Animal:
    def speak(self):
        print("Animal makes a sound.")

class Dog(Animal):
    def bark(self):
        print("Dog barks!")

# Usage
dog = Dog()
dog.speak()  # Inherited method
dog.bark()   # Dog-specific method
```
