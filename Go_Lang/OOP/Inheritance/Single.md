### Single Inheritance in Go.
* Go don't have traditional inheritance, so we can implement it's features using the concept of composition.
```go
type Animal struct{}

func (animal Animal) speak(){
	fmt.Println("Animal makes sound")
}

type Dog struct{
	Animal
}

func (dog Dog) bark(){
	fmt.Println("Dog barks.")
}

func main() {
    	dog:=Dog{}
	dog.speak()
	dog.bark()
}

```
