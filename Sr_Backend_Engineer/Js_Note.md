1. Eventloop: The Event Loop is a mechanism that allows JavaScript to handle asynchronous operations without blocking the execution of other code. It is the mechanism behid why async/await , promises,callback work(execute code asynchronously). Eventloop is implemented by the runtime environment, such as a browser or Node.js, rather than being a standalone feature of the JavaScript language.

1. JavaScript executes code synchronously by default, but Node.js provides asynchronous, non-blocking APIs for operations like file I/O and networking.

2. Callback: A callback is a function passed as an argument to another function, which can execute it when needed. There are 2 types of callbacks: synchronous and asynchronous.
   - Synchronous

   ```js
   function greet(name, callback) {
     console.log("Hello " + name);
     callback();
   }

   function sayGoodbye() {
     console.log("Goodbye!");
   }

   greet("Fahim", sayGoodbye);
   ```

   - Asynchronous

   ```js
   console.log("1. Start");

   setTimeout(() => {
     console.log("2. Data received");
   }, 2000);

   console.log("3. End");
   ```

3. Async/Await: The `async` keyword declares a function as asynchronous and allows the use of `await` inside it. When JavaScript encounters `await`, execution of that function is suspended until the awaited Promise settles, while code outside the function can continue executing.

   Once the Promise resolves, execution resumes from the statement following `await`. If the Promise rejects, an error is thrown at the `await` expression.

   ```js
   async function readUsers() {
     const data = await fsPromises.readFile(
       "users.json", "utf8"
     );

     console.log(data);
   }
   ```

4. Promise: A Promise in JavaScript is an object that represents the eventual success or failure of an operation, usually an asynchronous task such as reading a file, querying a database, or calling an API.

   ```js
   const promise = new Promise((resolve, reject) => {
     setTimeout(() => {
       resolve("User data loaded");
     }, 2000);
   });

   promise
     .then(data => console.log(data))
     .catch(error => console.log(error));

   console.log("Outside code");
   ```