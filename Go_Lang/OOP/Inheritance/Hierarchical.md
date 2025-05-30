```go
type Animal struct{}

func (animal Animal) speak(){
	fmt.Println("Animal makes sound.")
}


type Dog struct{
	Animal
}

func (dog Dog) bark(){
	fmt.Println("Dog barks.")
}


type Cat struct{
	Animal
}

func (cat Cat) meow(){
	fmt.Println("Cat meows.");
}

func main() {
    dog:=Dog{}
	dog.speak()
	dog.bark()

	cat:=Cat{}
	cat.speak()
	cat.meow()
}
```
