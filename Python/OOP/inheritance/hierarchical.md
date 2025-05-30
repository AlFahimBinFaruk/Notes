* Multiple class Inherit from a sinple parent class.
```py
class Animal:
    def speak(self):
        print("Animal makes a sound.")

class Dog(Animal):
    def bark(self):
        print("Dog barks!")

class Cat(Animal):
    def meow(self):
        print("Cat meows!")

# Usage
dog = Dog()
dog.speak()  # Inherited from Animal
dog.bark()   # Dog-specific method

cat = Cat()
cat.speak()  # Inherited from Animal
cat.meow()   # Cat-specific method
```
