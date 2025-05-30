### Runtime polymorphism or method overriding
```py
class Animal:
    def speak(self):
        return "Animal is making sound."

class Dog(Animal):
    # overridden
    def speak(self):
        return "Woof woof."
    

animal=Animal()
dog=Dog()

print(animal.speak())
print(dog.speak())
```
