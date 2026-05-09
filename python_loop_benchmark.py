from time import perf_counter

length: int = 2048 * 2048

def perform_arithmetic():
    start_time = perf_counter()
    
    total: int = 1
    for i in range(1, length):
        total +=i
    
    end_time = perf_counter()
    
    time_taken: float = float(end_time - start_time)
    print(f"Time Taken: {time_taken}")
    

def main():
    perform_arithmetic()

if __name__ == "__main__":
    main()