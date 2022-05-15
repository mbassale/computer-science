
const {performance} = require('perf_hooks');

function specialSubstringCount(s) {
    
    const charList = [];
    let charCount = 0;
    let currentChar = null;
    for (const char of s) {
        if (char == currentChar) {
            charCount++;
        } else {
            if (currentChar) {
                charList.push([currentChar, charCount]);
            }
            currentChar = char;
            charCount = 1;
        }
    }
    charList.push([currentChar, charCount]);

    let specialCount = charList.reduce((count, charSpec) => {
        return count + (charSpec[1] * (charSpec[1] + 1) / 2);
    }, 0);

    for (let i = 1; i < charList.length - 1; i++) {
        if (charList[i - 1][0] == charList[i + 1][0] && charList[i][1] == 1) {
            specialCount++;
        }
    }

    return specialCount;
}

function measure(s, func) {
    const startTime = performance.now();
    const result = func(s);
    const endTime = performance.now();
    return [endTime - startTime, result];
}

const tests = [
    { s: 'mnonopoo', expected: 12 },
    { s: 'asasd', expected: 7 }
];

for (const test of tests) {
    const [deltaTime, result] = measure(test.s, specialSubstringCount);
    console.log('s:', test.s, 'expected:', test.expected, 'result:', result, 'deltaTime:', deltaTime);
}