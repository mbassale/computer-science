import time
from multiprocessing import Process, Lock, Value, cpu_count


def add_500_lock(total: Value, lock: Lock):
    for i in range(100):
        time.sleep(0.01)
        lock.acquire()
        total.value += 5
        lock.release()


def sub_500_lock(total: Value, lock: Lock):
    for i in range(100):
        time.sleep(0.01)
        lock.acquire()
        total.value -= 5
        lock.release()


if __name__ == '__main__':
    total = Value('i', 500)
    lock = Lock()
    print(f'Total Before: {total.value}')
    add_process = Process(target=add_500_lock, args=(total, lock))
    sub_process = Process(target=sub_500_lock, args=(total, lock))

    add_process.start()
    sub_process.start()

    add_process.join()
    sub_process.join()

    print(f'Total After: {total.value}')
