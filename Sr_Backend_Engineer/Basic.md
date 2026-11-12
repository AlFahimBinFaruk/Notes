- Process: An instance of a running program with its own memory space and resources.
- Thread: A unit of execution inside a process that the CPU can execute.

### Process has
- A unique process ID (PID)
- Its own virtual memory address space
- Resources such as file handles and network sockets
- At least one or more threads that execute instructions

- Child process: A separate operating system process launched by your Node.js application. Unlike worker threads, child processes have their own independent memory space. They are useful for executing external programs such as Python scripts, FFmpeg, or system commands.

### Mental model
- Process = Restaurant: Has its own kitchen, equipment, and resources.
- Thread = Chef: Executes tasks using the restaurant's resources.
- CPU core = Cooking station: Where a chef can actively perform work.
- Operating system scheduler = Manager: Decides which chef gets access to a station and when.



### CPU Bound Operation Vs I/O Bound Operation:

| Type | CPU-bound | I/O-bound |
| --- | --- | --- |
| Primary bottleneck | CPU computation | Waiting for external I/O |
| Examples | Image processing, large calculations, data compression | Database queries, HTTP requests, file reads |
| Requires | CPU execution time | Disk/network/service response |
| Typical Node.js approach | Worker Threads | Async I/O + Event Loop |
| Main concern | Blocking the event loop | I/O latency and throughput |