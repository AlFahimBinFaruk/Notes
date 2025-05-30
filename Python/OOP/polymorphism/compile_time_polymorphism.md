### Compile Time Polymorphism or Method overloading
* Python dosen't support traditional method overloading.However, we can achieve it using default arguments.
```py
class MathOp:
    def add(self,a,b,c=0):
        return a+b+c

tc=MathOp()

print(tc.add(2,3))
print(tc.add(2,3,4))
```
