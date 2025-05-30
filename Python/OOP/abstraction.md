### Abstraction
* When we are going to use the car and bike class methods we are going to reffer to the vehicle class.
* Virtual class can have non-abstract method. But if any virtual class have only abstract method its called interface.
```py
from abc import ABC,abstractmethod

# Abstract class
class Vehicle(ABC):
    @abstractmethod
    def start(self):
        pass
    
    @abstractmethod
    def stop(self):
        pass

# Concrete class - Provides different implementation details
class Car(Vehicle):
    def start(self):
        print("Car engine started!")
    
    def stop(self):
        print("Car engine stopped!")

# Concrete class - Provides different implementation details
class Bike(Vehicle):
    def start(self):
        print("Bike engine started!")
    
    def stop(self):
        print("Bike engine stopped!")


car=Car()
car.start()

bike=Bike()
bike.start()
```
