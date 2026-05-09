# Cache Locality Benchmarking

> Thought I'd brush up on basic computer architecture concepts. This repo explores cache locality and overhead by comparing speed differences when accessing array values row-by-row, col-by-col, or random access. Also, this compares loop performance difference between C, a compiled language against Python, an interpreted language.

# Instructions to Run
To compile the C files:
- `cache_benchmark.c`
- `c_loop_benchmark.c`

Simply run the Makefile through `make setup_all`, which will compile both files into executables, in which they can be ran using:
```
./cache_benchmark.exe
./c_loop_benchmark.exe
```

For the Python file, run
```
python3 python_loop_benchmark.py
```

Additionally, simply running `make` will compile, run the executables + Python script, and clean up the executables. 

# My Benchmark Results

C Cache Benchmark (Avg. of 5 Trials):
```
Sequential Access Average: Time taken = 0.0005472799530253 seconds
Strided Access Average: Time taken = 0.0023689002264291 seconds
Random Access Average: Time taken = 0.0533745177090168 seconds
```

C Loop Benchmark (Avg. of 5 Trials):
```
Time taken = 0.0003729000000000
```

Python Loop Benchmark (Avg. of 5 Trials):
```
Time Taken: 0.6427855000001728
```

# Discussion

Interpreting the C Cache Benchmark, it appears that sequential access is the fastest with an average of ~0.0004 seconds, travelling row by row is faster because it uses the entire cache line and takes advantage of spatial locality, resulting in more cache hits. In comparison, strided access accesses a new cache line every time, resulting in more cache misses, requiring refetching from a lower level cache or the RAM (RAM has 100+ cycles of delay so that is undesireable). The random access has the same issue, but even worse because is isn't predictable with non-fixed strides for each new iteration. Therefore being slower than both sequential and strided access.

For the looping benchmarks, C code is considerably faster than Python code (~1723 times faster) because C directly compiles to machine code, while Python requires interpretation, and rather than compiling into pure machine code. It uses CPython to compile source to bytecode, then the interpreter executes the bytecode. Overall, Python code has much more overhead, causing slowdowns and becomes significantly slower than C.

In a Raspberry Pi, since it has a weaker CPU and smaller RAM, it is important to use best practices such as sequential accesses when traversing in loops, for rapid calculation tasks, it is good to use a compiled language, which is why instead of using pure Python for calculation, a library such as NumPy or PyTorch may be used.
