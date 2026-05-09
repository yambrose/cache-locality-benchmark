CC = gcc
CFLAGS = -O3

cache_bm = cache_benchmark
loop_bm = c_loop_benchmark
py_loop_bm = python_loop_benchmark.py

.PHONY: setup_all setup_cache setup_loop_benchmark run clean

run_all: setup_all setup_cache setup_loop_benchmark run clean

setup_all: setup_cache_benchmark setup_loop_benchmark

setup_cache_benchmark:
	$(CC) $(CFLAGS) $(cache_bm).c -o $(cache_bm).exe

setup_loop_benchmark:
	$(CC) $(CFLAGS) $(loop_bm).c -o $(loop_bm).exe

run:
	./$(cache_bm).exe
	./$(loop_bm).exe
	python3 $(py_loop_bm)

clean:
	rm -f $(cache_bm).exe $(loop_bm).exe