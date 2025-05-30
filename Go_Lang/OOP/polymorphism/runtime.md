### Method overriding or Runtime polymorphism.
```go
type Vehicle interface{
	start() string;
}

type Car struct{}

// ----> Pointer receiver.changes will impact original instance
// func (car *Car) start() string{
// 	return "Car engine started.";
// }

// -----> Copy receiver
func (car Car) start() string{
	return "Car engine started.";
}

type Bike struct{}

func (bike Bike) start() string{
	return "Bike engine started.";
}

// ----> As we have interface as func arguments it will figure out weateher i am passing pointer or copy.
func makeVehicleStart(vehicle Vehicle){
	fmt.Println(vehicle.start());
}

func main() {
    // car:=&Car{};
    car:=Car{};
    bike:=Bike{};
    makeVehicleStart(car);
    makeVehicleStart(bike);
}
```
