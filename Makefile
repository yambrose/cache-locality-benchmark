
cache_bm = c_cache_benchmark
loop_bm = c_loop_benchmark
py_loop_bm = python_loop_benchmark.py


.PHONY setup_all:
	gcc $(cache_bm).c -o $(cache_bm).exe
	gcc $(loop_bm).c -o $(loop_bm).exe

.PHONY setup_cache_benchmark:
	gcc $(cache_bm).c -o $(cache_bm).exe

.PHONY setup_loop_benchmark:
	gcc $(loop_bm).c -o $(loop_bm).exe

run:
	./$(cache_bm).exe
	./$(loop_bm).exe
	python $(py_loop_bm)

clean:
	rm $(cache_bm).exe
	rm $(loop_bm).exe