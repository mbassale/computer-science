
def isValidNumber(c: str) -> bool:
    return c != '.'


def char2num(c: str) -> int:
    return ord(c[0]) - ord('0')


def getBox(row: int, col: int) -> int:
    box = int(row / 3) * 3
    if col >= 3 and col < 6:
        box += 1
    elif col >= 6 and col < 9:
        box += 2
    return box
    

def isValidSudoku(board: list[list[str]]) -> bool:
    rows = [0 for _ in range(9)]
    cols = [0 for _ in range(9)]
    boxes = [0 for _ in range(9)]

    for row in range(9):
        for col in range(9):

            c = board[row][col]
            if not isValidNumber(c):
                continue

            num = char2num(c)
            mask = 1 << (num - 1)
            
            if rows[row] & mask:
                return False
            if cols[col] & mask:
                return False
            box = getBox(row, col)
            if boxes[box] & mask:
                return False

            rows[row] |= mask
            cols[col] |= mask
            boxes[box] |= mask

    return True


def runTestCase(board: list[list[str]]) -> None:
    for row in board:
        print(" ".join([str(n) for n in row]))
    isValid = isValidSudoku(board)
    print(f"IsValid: {isValid}")
        

if __name__ == "__main__":
    runTestCase([['5', '3', '.', '.', '7', '.', '.', '.', '.'],
                ['6', '.', '.', '1', '9', '5', '.', '.', '.'],
                ['.', '9', '8', '.', '.', '.', '.', '6', '.'],
                ['8', '.', '.', '.', '6', '.', '.', '.', '3'],
                ['4', '.', '.', '8', '.', '3', '.', '.', '1'],
                ['7', '.', '.', '.', '2', '.', '.', '.', '6'],
                ['.', '6', '.', '.', '.', '.', '2', '8', '.'],
                ['.', '.', '.', '4', '1', '9', '.', '.', '5'],
                ['.', '.', '.', '.', '8', '.', '.', '7', '9']])

    runTestCase([["8","3",".",".","7",".",".",".","."],
                 ["6",".",".","1","9","5",".",".","."],
                 [".","9","8",".",".",".",".","6","."],
                 ["8",".",".",".","6",".",".",".","3"],
                 ["4",".",".","8",".","3",".",".","1"],
                 ["7",".",".",".","2",".",".",".","6"],
                 [".","6",".",".",".",".","2","8","."],
                 [".",".",".","4","1","9",".",".","5"],
                 [".",".",".",".","8",".",".","7","9"]])

