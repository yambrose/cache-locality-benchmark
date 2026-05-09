from time import perf_counter

trials: int = 5
length: int = 2048 * 2048

def perform_arithmetic(trial: int) -> float:
    start_time: float = perf_counter()
    
    total: int = 1
    for i in range(1, length):
        total +=i
    
    end_time: float = perf_counter()
    
    time_taken: float = float(end_time - start_time)
    print(f"TRIAL {trial}: Time Taken = {time_taken} seconds, total = {total}")

    return time_taken
    
if __name__ == "__main__":
    total_time_taken: float = 0.0
    
    print("RUNNING PYTHON LOOP BENCHMARK")
    for trial in range(1, trials + 1):
        total_time_taken += perform_arithmetic(trial)
    
    print("Pyton Loop Average: {total_time_taken} seconds.")
