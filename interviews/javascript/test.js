// IMPORT LIBRARY PACKAGES NEEDED BY YOUR PROGRAM
// SOME FUNCTIONALITY WITHIN A PACKAGE MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED

function sendFileAdjacent(x, y, serversWaitList, rows, columns, grid)
{
    let coordsList = [
        [x-1, y],
        [x+1, y],
        [x, y-1],
        [x, y+1]
    ];
    for (let i = 0; i < coordsList.length; i++) {
        let coords = coordsList[i];
        if (coords[0] >= 0 && coords[0] < rows && coords[1] >= 0 && coords[1] < columns) {
            if (grid[coords[0]][coords[1]] === 0) {
                grid[coords[0]][coords[1]] = 1;
                serversWaitList.push(coords);
            }
        }
    }
}

function minimumHours(rows, columns, grid)
{
    let numHours = 0;
    let keepRunning = true;
    while (keepRunning) {
        let serversWaitList = [];
        for (let i = 0; i < rows; i++) {
            for (let j = 0; j < columns; j++) {
                // if server received a file, wait for next hour
                let isWaiting = false;
                for (let k = 0; k < serversWaitList.length; k++) {
                    let coords = serversWaitList[k];
                    if (coords[0] === i && coords[1] === j) {
                        isWaiting = true;
                        break;
                    }
                }
                if (!isWaiting && grid[i][j] === 1) {
                    sendFileAdjacent(i, j, serversWaitList, rows, columns, grid);
                }
            }
        }
        numHours++;

        // check if file is in all servers
        keepRunning = false;
        for (let i = 0; i < rows; i++) {
            for (let j = 0; j < columns; j++) {
                if (grid[i][j] === 0) {
                    keepRunning = true;
                    break;
                }
            }
        }
    }

    return numHours;
}
// FUNCTION SIGNATURE ENDS

console.log('NumHours:', minimumHours(5, 5, [[1, 0, 0, 0, 0], [0, 1, 0, 0, 0], [0, 0, 1, 0, 0], [0, 0, 0, 1, 0], [0, 0, 0, 0, 1]]));
console.log('NumHours:', minimumHours(5, 6, [[0, 0, 1, 0, 0, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 1], [0, 0, 0, 0, 0, 0], [0, 1, 0, 0, 0, 0]]));