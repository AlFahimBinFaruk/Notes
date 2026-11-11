1. Async I/O
   Async I/O performs an I/O operation without blocking the JavaScript thread.

2. Event loop
   The event loop is the mechanism behind why async/await, promises, and callbacks work asynchronously. It is implemented by the runtime environment, such as a browser or Node.js, rather than being a standalone feature of the JavaScript language.

   The event loop ensures that JavaScript executes the appropriate callback when an I/O operation finishes. The event loop and async I/O work together.

   ```js
   const fs = require("node:fs/promises");

   async function readUsers() {
     console.log("A: Starting file read");

     /*
      * 1. Node.js delegates the file read to libuv's worker pool.
      * 2. await suspends this function, allowing other JS to run.
      * 3. Once reading finishes, the event loop processes
      *    the I/O completion, which fulfills the Promise.
      * 4. The function resumes after await via a microtask.
      */
     const data = await fs.readFile("users.json", "utf8");

     console.log("C: File loaded", data);
   }

   readUsers();

   console.log("B: Other JavaScript");
   ```

   Important distinction:
   - libuv worker pool: Performs the file-reading work.
   - Event loop: Processes the I/O completion callback.
   - Promise: Represents the eventual file-reading result.
   - await: Suspends the function until the Promise settles.
   - Microtask queue: Schedules the function's continuation after the Promise fulfills.

   Mental model: Async I/O handles the operation without blocking JavaScript; the event loop processes its completion, and the Promise microtask resumes the suspended function.

3. JavaScript executes code synchronously by default, but Node.js provides asynchronous, non-blocking APIs for operations like file I/O and networking.

4. Callback
   A callback is a function passed as an argument to another function, which can execute it when needed. There are 2 types of callbacks: synchronous and asynchronous.

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

5. Async/Await
   The `async` keyword declares a function as asynchronous and allows the use of `await` inside it. When JavaScript encounters `await`, execution of that function is suspended until the awaited Promise settles, while code outside the function can continue executing.

   Once the Promise resolves, execution resumes from the statement following `await`. If the Promise rejects, an error is thrown at the `await` expression.

   ```js
   async function readUsers() {
     const data = await fsPromises.readFile(
       "users.json", "utf8"
     );

     console.log(data);
   }
   ```

6. Promise
   A Promise in JavaScript is an object that represents the eventual success or failure of an operation, usually an asynchronous task such as reading a file, querying a database, or calling an API.

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

7. Libuv
   **Libuv** is a C library used by Node.js for asynchronous I/O, event-loop functionality, and thread-pool operations.