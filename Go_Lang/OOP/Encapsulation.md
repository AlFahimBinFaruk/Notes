### Encapsulation in Go.
* Go, encapsulation is more of a convention rather than being enforced with explicit keywords like private, protected, or public in C++ or Java.
```go
type BankAccount struct{
	balance int;
}

// constructor function
func NewBankAccount() *BankAccount{
	// return &BankAccount{};default balance will be 0
	return &BankAccount{balance: 0};
}

func (bankAccount *BankAccount) deposit(amount int){
	bankAccount.balance+=amount;
}

func (bankAccount *BankAccount) getBalance() int{
	return bankAccount.balance;
}

func main(){
	tc:=NewBankAccount();
	tc.deposit(100);
	tc.deposit(1000);
	fmt.Println(tc.getBalance());
}
```
