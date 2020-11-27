
function isValidDisk(otherDisk, currentDisk) {
    return otherDisk[0] < currentDisk[0] && otherDisk[1] < currentDisk[1] && otherDisk[2] < currentDisk[2];
}

function diskStacking(disks) {
    disks.sort((a, b) => a[2] - b[2]);
    console.log(disks);
    const heights = disks.map(disk => disk[2]);
    console.log(heights);

    const selectedDiskIndexes = new Array(disks.length).fill(null);

    // dinamic programming, find maximum tower that can be build for each disk.
    let maxHeightIdx = 0;
    for (let i = 1; i < disks.length; i++) {
        const currentDisk = disks[i];;
        for (let j = 0; j < i; j++) {
            const otherDisk = disks[j];
            if (isValidDisk(otherDisk, currentDisk)) {
                const newHeight = currentDisk[2] + heights[j];
                if (newHeight >= heights[i]) {
                    heights[i] = newHeight;
                    selectedDiskIndexes[i] = j;
                }
            }
        }
        if (heights[i] >= heights[maxHeightIdx]) maxHeightIdx = i;
    }

    console.log('heights:', heights, 'maxHeightIdx:', maxHeightIdx, 'indexes:', selectedDiskIndexes);

    const result = [];
    let currentIndex = maxHeightIdx;
    while (currentIndex !== null) {
        result.unshift(disks[currentIndex]);
        currentIndex = selectedDiskIndexes[currentIndex];
    }
    return result;
}

const tests = [
    { disks: [[2, 1, 2], [3, 2, 3], [2, 2, 8], [2, 3, 4], [1, 3, 1], [4, 4, 5]], expected: [[2, 1, 2], [3, 2, 3], [4, 4, 5]] }
];

for (const test of tests) {
    const result = diskStacking(test.disks);
    console.log('disks:', test.disks, 'expected:', test.expected, 'result:', result);
}