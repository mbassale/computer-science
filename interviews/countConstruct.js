const {performance} = require('perf_hooks');

function countConstruct(target, wordBank, memoize = {}) {
    if (target in memoize) return memoize[target];
    if (target.length == 0) return 1;

    let count = 0;
    for (const word of wordBank) {
        const index = target.indexOf(word);
        if (index == 0) {
            const remainder = target.substring(word.length);
            count += countConstruct(remainder, wordBank, memoize);
        }
    }

    memoize[target] = count;
    return count;
}


function measure(n, array, func) {
    const startTime = performance.now();
    const result = func(n, array);
    const endTime = performance.now();
    return [endTime - startTime, result];
}

const tests = [
    { target: 'purple', wordBank: ['purp', 'p', 'ur', 'le', 'purpl'], expected: 2 },
    { target: 'abcdef', wordBank: ['ab', 'abc', 'cd', 'def', 'abcd'], expected: 1 },
    { target: 'skateboard', wordBank: ['bo', 'rd', 'ate', 't', 'ska', 'sk', 'boar'], expected: 0 },
    { target: 'enterapotentpot', wordBank: ['a', 'p', 'ent', 'enter', 'ot', 'o', 't'], expected: 4},
    { target: 'eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef', wordBank: [
        'e',
        'ee',
        'eee',
        'eeee',
        'eeeee',
        'eeeeee'
    ], expected: 0 }
];

for (const test of tests) {
    const [deltaTime, result] = measure(test.target, test.wordBank, countConstruct);
    console.log('target:', test.target, 'wordBank:', test.wordBank, 'expected:', test.expected, 'result:', result, 'deltaTime:', deltaTime);
}
