```py
class BankAccount:
    def __init__(self,balance):
        self.__balance=balance # __ means private
    def deposit(self,amount):
        self.__balance+=amount
    def getBalance(self):
        return self.__balance
    

tc=BankAccount(100)
tc.deposit(2000)
print(tc.getBalance())
```
