```go
// Animal.
type Animal struct{}

func (animal Animal) Speak(){
	fmt.Println("Animal makes sound.")
}

// Mammal
type Mammal struct{
	Animal
}

func (mammal Mammal) Walk(){
	fmt.Println("Mammal walk on land.")
}


// Bird
type Bird struct{
	Animal
}

func (bird Bird) Fly(){
	fmt.Println("Bird Fly.")
}


// Bat
type Bat struct{
	Mammal
	Bird
}

func (bat Bat) Screech(){
	fmt.Println("Bat screech.");
}



func main() {
    bat:=Bat{}
	bat.Screech()
	bat.Walk()
	bat.Fly()
	bat.Mammal.Speak()
	bat.Bird.Speak()
}

```
