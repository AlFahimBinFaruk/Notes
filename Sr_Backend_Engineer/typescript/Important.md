# TypeScript: 7 Core Concepts with Real-World Backend Examples

We'll use examples from a typical Node.js / Express backend, including authentication, user management, API responses, database operations, and request validation.

Each topic covers what it is, a practical code example, and why you'd use it in production.

## 1. Strict Mode

Definition: Strict mode enables additional compile-time type checks to catch potential bugs before your application runs.

Enable it in `tsconfig.json`:

```

{
  "compilerOptions": {
    "strict": true
  }
}

```

### Real-world example: Finding a user in a database

```

interface User {
  id: number;
  name: string;
}

const users: User[] = [
  { id: 1, name: "Fahim" }
];

function getUser(id: number) {
  return users.find(user => user.id === id);
}

const user = getUser(99);

console.log(user.name); // TypeScript error

```

What happens?

- `Array.find()` returns `User | undefined`.
- User `99` doesn't exist, so the result is `undefined`.
- With `strictNullChecks` enabled through strict mode, TypeScript flags `user.name` as potentially unsafe.

Correct implementation:

```

const user = getUser(99);

if (!user) {
  throw new Error("User not found");
}

console.log(user.name);

```

Production use: Prevents null/undefined access bugs in database queries, API responses, and optional configuration values.

Strict mode also enables checks such as `noImplicitAny` and `strictPropertyInitialization`.&#x20;

[image](https://www.google.com/s2/favicons?domain=https://www.typescriptlang.org\&sz=32)

typescriptlang.org



## 2. Type Narrowing

Definition: Narrowing is the process by which TypeScript determines a more specific type using conditional checks.

### Real-world example: Payment processing

Suppose your backend accepts two payment methods:

```

type Payment =
  | {
      method: "card";
      cardNumber: string;
    }
  | {
      method: "bkash";
      phoneNumber: string;
    };

function processPayment(payment: Payment) {
  if (payment.method === "card") {
    console.log(payment.cardNumber);
  } else {
    console.log(payment.phoneNumber);
  }
}

processPayment({
  method: "bkash",
  phoneNumber: "01712345678"
});

```

How it works:

Initially, `payment` can be either a card payment or a bKash payment.

When TypeScript encounters:

```
if (payment.method === "card")
```

It narrows the type to:

```
{
  method: "card";
  cardNumber: string;
}
```

Inside that block, accessing `phoneNumber` produces a compile-time error.

This is called a discriminated union, a common pattern for payment methods, API results, and event-driven systems.&#x20;

[image](https://www.google.com/s2/favicons?domain=https://www.typescriptlang.org\&sz=32)

Narrowing



## 3. Generics

Definition: Generics allow you to build reusable functions, classes, and interfaces that work with different types while preserving type safety.

### Real-world example: Standardized API responses

Suppose your backend has these endpoints:

- `GET /users/1`
- `GET /products/1`

Both return the same response structure, but different data.

Without generics, you might duplicate interfaces.

With generics:

```

interface ApiResponse<T> {
  success: boolean;
  data: T;
}

interface User {
  id: number;
  name: string;
}

interface Product {
  id: number;
  price: number;
}

const userResponse: ApiResponse<User> = {
  success: true,
  data: {
    id: 1,
    name: "Fahim"
  }
};

const productResponse: ApiResponse<Product> = {
  success: true,
  data: {
    id: 10,
    price: 500
  }
};

```

Here, `T` is a type parameter.

- `ApiResponse<User>` means `data` must be a `User`.
- `ApiResponse<Product>` means `data` must be a `Product`.

You can also create a generic function:

```

function createResponse<T>(data: T): ApiResponse<T> {
  return {
    success: true,
    data
  };
}

const response = createResponse({
  id: 1,
  name: "Fahim"
});

// TypeScript infers the data type
console.log(response.data.name);

```

Production use: API response wrappers, reusable repositories, pagination, caching utilities, and typed HTTP clients.

## 4. Utility Types

Definition: Utility types transform existing types without requiring you to redefine interfaces.

### Real-world example: User management API

Consider a database entity:

```

interface User {
  id: number;
  name: string;
  email: string;
  passwordHash: string;
  age: number;
}

```

Different API operations need different subsets of `User`.

### A. `Partial<T>` — Update an existing user

```

type UpdateUserDto = Partial<User>;

const update: UpdateUserDto = {
  name: "Updated Fahim"
};

```

All properties become optional.

Useful for `PATCH /users/:id`, although production DTOs should exclude fields that clients must not modify.

### B. `Pick<T, K>` — Select specific fields

```

type LoginDto = Pick<User, "email">;

const login: LoginDto = {
  email: "user@example.com"
};

```

Useful for creating DTOs with a limited set of fields.

### C. `Omit<T, K>` — Exclude fields

```

type PublicUser = Omit<User, "passwordHash">;

const publicUser: PublicUser = {
  id: 1,
  name: "Fahim",
  email: "user@example.com",
  age: 24
};

```

Useful for representing user information without sensitive fields.

Note that `Omit` only changes the TypeScript type; it does not remove a property from an actual JavaScript object.

### D. `Record<K, V>` — Create a typed dictionary

```

type Role = "admin" | "user" | "guest";

const permissions: Record<Role, string[]> = {
  admin: ["read", "write", "delete"],
  user: ["read", "write"],
  guest: ["read"]
};

console.log(permissions.admin);

```

Useful for role-based access control, configuration maps, and lookup tables.&#x20;

[image](https://www.google.com/s2/favicons?domain=https://www.typescriptlang.org\&sz=32)

Utility Types



## 5. Type Inference

Definition: Type inference means TypeScript automatically determines a variable's or function's type without requiring explicit type annotations.

### Real-world example: Calculating order totals

```

interface OrderItem {
  price: number;
  quantity: number;
}

function calculateTotal(items: OrderItem[]) {
  return items.reduce(
    (total, item) => total + item.price * item.quantity,
    0
  );
}

const total = calculateTotal([
  { price: 500, quantity: 2 },
  { price: 200, quantity: 1 }
]);

console.log(total); // 1200

```

Even though we didn't declare a return type, TypeScript infers:

```
function calculateTotal(items: OrderItem[]): number
```

Therefore:

```
const total: number = calculateTotal([]);
```

Type inference also works with objects:

```

const user = {
  id: 1,
  name: "Fahim",
  active: true
};

// Inferred:
// {
//   id: number;
//   name: string;
//   active: boolean;
// }

user.name = "Rahim"; // Valid
user.name = 123;     // Compile-time error

```

Production use: Reduces unnecessary type declarations while preserving compile-time safety. Explicit types remain valuable at public API and module boundaries.&#x20;

[image](https://www.google.com/s2/favicons?domain=https://www.typescriptlang.org\&sz=32)

Type Inference



## 6. Decorators

Definition: Decorators are functions that customize classes or class members, commonly used for logging, authorization, routing, and dependency injection.

### Real-world example: Logging service method execution

Suppose you want to log whenever an order service method executes, without writing logging code inside every method.

```

function Log(
  originalMethod: (...args: any[]) => any,
  context: ClassMethodDecoratorContext
) {
  return function (this: any, ...args: any[]) {
    console.log(`Calling ${String(context.name)}`);

    return originalMethod.apply(this, args);
  };
}

class OrderService {
  @Log
  createOrder(productId: number) {
    console.log(`Order created for ${productId}`);
  }
}

const service = new OrderService();

service.createOrder(101);

```

Output:

```
Calling createOrder
Order created for 101
```

How it works:

1. `@Log` decorates `createOrder`.
2. The decorator receives the original method.
3. It returns a wrapper that logs before executing the original method.
4. The original method executes normally.

You can apply the same decorator to multiple service methods.

Production use: Cross-cutting concerns such as logging, metrics, tracing, and auditing.

This example uses modern standard decorators, supported since TypeScript 5.0. Frameworks such as NestJS also use legacy experimental decorators, which have different signatures and compiler requirements.&#x20;

[image](https://www.google.com/s2/favicons?domain=https://www.typescriptlang.org\&sz=32)

TypeScript 5.0



## 7. Runtime Validation

Definition: Runtime validation checks actual incoming data while the application is executing.

TypeScript types only exist during development and compilation. They cannot guarantee that external JSON data matches your interface.

### Real-world example: Registering a user through Express

Suppose your API accepts:

```
POST /users
Content-Type: application/json
```

Expected body:

```
{
  "name": "Fahim",
  "email": "fahim@example.com",
  "age": 24
}
```

But a client sends:

```
{
  "name": 123,
  "email": "invalid-email",
  "age": "twenty"
}
```

TypeScript alone won't reject this HTTP request.

### Solution: Zod

Install:

```
npm install express zod
```

```

import express from "express";
import { z } from "zod";

const app = express();
app.use(express.json());

const UserSchema = z.object({
  name: z.string().min(2),
  email: z.email(),
  age: z.number().int().min(18)
});

type User = z.infer<typeof UserSchema>;

app.post("/users", (req, res) => {
  const result = UserSchema.safeParse(req.body);

  if (!result.success) {
    return res.status(400).json({
      errors: result.error.issues
    });
  }

  const user: User = result.data;

  return res.status(201).json({
    message: "User validated successfully",
    user
  });
});

app.listen(3000);

```

How it works:

- `safeParse()` performs actual runtime validation.
- If validation fails, the API returns HTTP `400`.
- If validation succeeds, `result.data` contains validated, strongly typed data.
- `z.infer` generates the TypeScript type from the Zod schema.

This avoids maintaining duplicate TypeScript interfaces and validation schemas.&#x20;

[image](https://www.google.com/s2/favicons?domain=https://zod.dev\&sz=32)

Zod



## Quick comparison

| Concept            | Main purpose                  | Backend use case          |
| ------------------ | ----------------------------- | ------------------------- |
| Strict mode        | Catch unsafe code             | Prevent undefined access  |
| Narrowing          | Refine union types            | Payment processing        |
| Generics           | Reusable, type-safe code      | API response wrappers     |
| Utility types      | Transform existing types      | CRUD DTOs                 |
| Inference          | Automatically determine types | Service return types      |
| Decorators         | Add reusable behavior         | Logging and authorization |
| Runtime validation | Validate actual data          | HTTP request validation   |

Important distinction: The first six concepts primarily improve development-time type safety or code organization. Decorators can also add runtime behavior. Runtime validation specifically protects your application from malformed external input.

For a production Node.js backend, I recommend prioritizing strict mode → narrowing → generics → utility types → inference → runtime validation → decorators. These concepts become particularly useful when building typed service layers, reusable repositories, and reliable API boundaries.