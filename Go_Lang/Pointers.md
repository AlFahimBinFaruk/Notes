```go
func pass_by_value(nums []int){
	fmt.Println(nums)
}

func pass_by_reference(nums *[]int){
	fmt.Println(nums)
	fmt.Println(*nums)
}

func main(){

	// x:=[]int{1,2,3,4,5}
	x:=345
	a:=&x // a stores address of x."&"" is called ampersand.
	fmt.Println(a) // prints address of x
	fmt.Println(*a) // value at address a, which is x


	fmt.Println("------------------------------")

	*a=789 // changing value at address a, which is x
	fmt.Println(x) // prints changed value of x


	y:=[]int{1,2,3,4,5}

	pass_by_value(y)
	pass_by_reference(&y)
}
```
