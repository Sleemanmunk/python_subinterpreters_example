# Python Subinterpreters Example
An example project of how to use subinterpreters in the lastest version of the Python C API (Python 3.9.7) without threads.

Many examples online use an old, deprecated version where the GIL had to be locked and unlocked manually. These examples no longer work.

# How to Run the Code

This example code may be built via the following steps:

1. Update the commented lines of code in CmakeLists.txt to point to your machine's python
2. Run the following command and observe the output


```
$bash run.sh
Interpreter 0 Initializing val to 0
Interpreter 1 Initializing val to 0
Interpreter 2 Initializing val to 0
Interpreter 0 has been called 1 times
Interpreter 1 has been called 1 times
Interpreter 2 has been called 1 times
Interpreter 0 has been called 2 times
Interpreter 1 has been called 2 times
Interpreter 2 has been called 2 times
Interpreter 0 has been called 3 times
Interpreter 1 has been called 3 times
Interpreter 2 has been called 3 times
Interpreter 0 shutting down now...
Interpreter 1 shutting down now...
Interpreter 2 shutting down now...
```