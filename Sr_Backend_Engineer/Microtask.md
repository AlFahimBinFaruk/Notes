A microtask is a small unit of JavaScript work scheduled to execute after the current synchronous code finishes, but before the Event Loop processes the next regular task (such as a timer callback).

**Microtasks are primarily about execution ordering, not background processing.**
Promises and async/await use the "microtask" queue behind the scenes.

- queueMicrotask
```js

function getUser(id, callback) {
  const cached = cache.get(id);

  if (cached) {
    queueMicrotask(() => callback(cached));
  } else {
    db.findUser(id).then(callback);
  }
}

console.log("Start");

getUser(1, user => {
  console.log("User retrieved");
});

console.log("End");
```
Now, regardless of whether the user is cached, the callback executes asynchronously.