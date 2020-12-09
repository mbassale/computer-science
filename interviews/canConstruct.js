const {performance} = require('perf_hooks');

function canConstruct(target, wordBank, memoize = {}) {
    if (target in memoize) return memoize[target];
    if (target === '') return true;

    for (const word of wordBank) {
        const index = target.indexOf(word);
        if (index === 0) {
            const remainder = target.substring(word.length);
            if (canConstruct(remainder, wordBank, memoize)) {
                memoize[target] = true;
                return true;
            }
        }
    }

    memoize[target] = false;
    return false;
}


function measure(n, array, func) {
    const startTime = performance.now();
    const result = func(n, array);
    const endTime = performance.now();
    return [endTime - startTime, result];
}

const tests = [
    { target: 'abcdef', wordBank: ['ab', 'abc', 'cd', 'def', 'abcd'], expected: true },
    { target: 'skateboard', wordBank: ['bo', 'rd', 'ate', 't', 'ska', 'sk', 'boar'], expected: false },
    { target: 'enterapotentpot', wordBank: ['a', 'p', 'ent', 'enter', 'ot', 'o', 't'], expected: true},
    { target: 'eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef', wordBank: [
        'e',
        'ee',
        'eee',
        'eeee',
        'eeeee',
        'eeeeee'
    ], expected: false }
];

for (const test of tests) {
    const [deltaTime, result] = measure(test.target, test.wordBank, canConstruct);
    console.log('target:', test.target, 'wordBank:', test.wordBank, 'expected:', test.expected, 'result:', result, 'deltaTime:', deltaTime);
}
