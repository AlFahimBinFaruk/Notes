### Method overloading or Compile time polymorphism.
* Go does not support traditional method overloading, but we can achieve a similar effect using variadic functions or interface parameters.
```go
func print(value interface{}){
	fmt.Println(value);
}

func main(){
	print(33);
	print(33.333);
	print("Fahim");
}
```
