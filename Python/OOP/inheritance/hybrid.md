### Hybrid Inheritance
* Combination of two or more types of inheritance.
```py
class Animal:
    def speak(self):
        print("Animal makes a sound.")

class Mammal(Animal):
    def walk(self):
        print("Mammal walks on land.")

class Bird(Animal):
    def fly(self):
        print("Bird flies in the sky.")

class Bat(Mammal, Bird):
    def screech(self):
        print("Bat screeches!")

# Usage
bat = Bat()
bat.speak()   # Inherited from Animal
bat.walk()    # Inherited from Mammal
bat.fly()     # Inherited from Bird
bat.screech() # Bat-specific method
```
