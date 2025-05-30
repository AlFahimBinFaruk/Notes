### Composition
* It's like inheritance where main purpose is re-usability but it's loosely coupled,easier to modify and extend.
```py
class Engine:
    def start(self):
        print("Engine started")

class Car:
    def __init__(self):
        self.engine = Engine()

    def start(self):
        self.engine.start()

# Creating object
my_car = Car()
my_car.start()  # Output: Engine started
```
```py
class Engine:
    def __init__(self, engine_type):
        self.engine_type = engine_type

    def start(self):
        print(f"The {self.engine_type} engine is starting.")

class Car:
    def __init__(self, make, model, engine):
        self.make = make
        self.model = model
        self.engine = engine  # Engine object as a composition

    def drive(self):
        print(f"Driving the {self.make} {self.model}.")
        self.engine.start()  # Calling the start method from the Engine class

# Creating an Engine object
car_engine = Engine("V8")

# Creating a Car object with the Engine object passed as a parameter
my_car = Car("Ford", "Mustang", car_engine)

# Using the Car object
my_car.drive()
```
