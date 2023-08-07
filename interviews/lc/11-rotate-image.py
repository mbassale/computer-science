from typing import List

def transpose(matrix: List[List[int]]) -> None:
    for i in range(len(matrix)):
        for j in range(0, i):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]


def mirrorX(matrix: List[List[int]]) -> None:
    for i in range(len(matrix)):
        left = 0
        right = len(matrix[i]) - 1
        while left < right:
            matrix[i][left], matrix[i][right] = matrix[i][right], matrix[i][left]
            left += 1
            right -= 1


def rotateImage(image: List[List[int]]) -> None:
    transpose(image)
    mirrorX(image)


def dumpImage(image: List[List[int]]) -> None:
    for i in range(len(image)):
        rowStr = " ".join([str(n) for n in image[i]])
        print(rowStr)


def runTestCase(image: List[List[int]]) -> None:
    print('Original:')
    dumpImage(image)
    print('Rotated:')
    rotateImage(image)
    dumpImage(image)


if __name__ == "__main__":
    runTestCase([
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9]
    ])
    runTestCase([
        [5,1,9,11],
        [2,4,8,10],
        [13,3,6,7],
        [15,14,12,16]
    ])
