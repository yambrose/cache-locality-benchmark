# Architecture Benchmarking

> A "for-fun" repo made to explore . as well as performance difference between C, a compiled language against Python, an interpreted language.

# Instructions to Run
To compile the C files:
- `c_cache_benchmark.c`
- `c_loop_benchmark.c`

Simply run the Makefile through `make`, which will compile both files into executables, in which they can be ran using:
```
./c_cache_benchmark.exe
./c_loop_benchmark.exe
```

For the Python file, run
```
python python_loop_benchmark.py
```

Additionally, `make run all` will compile, run the executables along with the Python script, and cleanup afterwards. 

# My Benchmark Results

C Cache Benchmark (Avg. of 5 Trials):
```
Sequential Access: Time taken = 0.002648 seconds
Strided Access: Time taken = 0.006858 seconds
Random Access: Time taken = 0.055739 seconds
```

C Loop Benchmark (Avg. of 5 Trials):
```
Time taken = 0.010065 seconds
```

Python Loop Benchmark (Avg. of 5 Trials):
```
Time Taken: 0.19075189996510744
```

# Discussion

Interpreting the C Cache Benchmark, it appears that sequential access is the fastest with an average of 0.002648 seconds, travelling row by row is faster because it uses the entire cache line and takes advantage of spatial locality, resulting in more cache hits. In comparison, strided access accesses a new cache line every time, resulting in more cache misses, requiring refetching from a lower level cache or the RAM (RAM has 100+ cycles of delay so that is undesireable). The random access has the same issue, but even worse because is isn't predictable with non-fixed strides for each new iteration. Therefore being slower than both sequential and strided access.

For the looping benchmarks, C code is considerably faster than Python code because C directly compiles to machine code, while Python requires interpretation, and rather than compiling into pure machine code. It uses CPython to compile source to bytecode, then the interpreter executes the bytecode. Overall, Python code has much more overhead, causing slowdowns and becomes significantly slower than C.

In a Raspberry Pi, since it has a weaker CPU and smaller RAM, it is important to use best practices such as sequential accesses when traversing in loops, for rapid calculation tasks, it is good to use a compiled language, which is why instead of using pure Python for calculation, a library such as NumPy or PyTorch may be used. For the capstone, the ML pipeline should default to sending structured alerts, not images/videos due to privacy first.