import sys


def trace_call(p: int, q: int, depth: int):
    indent = "".join([" " for _ in range(depth)])
    print(f"{indent}gdc({p}, {q})")


def gdc(p: int, q: int, depth: int = 0) -> int:
    trace_call(p, q, depth)
    if q == 0:
        return p
    r = p % q
    return gdc(q, r, depth + 1)


if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("Missing arguments")
        sys.exit(1)
    p = int(sys.argv[1])
    q = int(sys.argv[2])
    print(f"gcd({p}, {q}) = {gdc(p, q)}")
