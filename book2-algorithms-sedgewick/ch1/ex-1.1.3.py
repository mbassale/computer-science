import sys

if __name__ == "__main__":
    if len(sys.argv) == 4:
        print("equal" if sys.argv[1] == sys.argv[2] == sys.argv[3] else "not equal")
    else:
        print("Usage: python ex-1.1.3.py <arg1> <arg2> <arg3>")

