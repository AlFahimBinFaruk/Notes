```go
type Animal struct{}

func (animal Animal) speak(){
	fmt.Println("Animal makes sound.")
}

type Mammal struct{}

func (mammal Mammal) walk(){
	fmt.Println("Mammal walk on land.")
}

type Dog struct{
	Animal
	Mammal
}

func (dog Dog) bark(){
	fmt.Println("Dog barks.")
}

func main() {
    dog:=Dog{}
	dog.speak()
	dog.walk()
	dog.bark()
}
```
