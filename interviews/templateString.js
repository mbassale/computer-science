
function templateString(s, template) {
    
    // build char counts char
    const charCounts = {};
    for (let i = 0; i < s.length; i++) {
        const currentChar = s[i];
        if (currentChar in charCounts) {
            charCounts[currentChar]++;
        } else {
            charCounts[currentChar] = 1;
        }
    }

    // using template, build a new string
    let result = '';
    for (let i = 0; i < template.length; i++) {
        const templateChar = template[i];
        if (!(templateChar in charCounts)) {
            continue;
        }
        while (charCounts[templateChar] > 0) {
            result += templateChar;
            charCounts[templateChar]--;
        }
    }
    return result;
}

const tests = [
    { s: 'aabbcddd', template: 'cdafb', expected: 'cdddaabb' },
    { s: 'cccbaaaadddd', template: 'abc', expected: 'aaaabccc' }
];

for (const test of tests) {
    const result = templateString(test.s, test.template);
    console.log('s:', test.s, 'template:', test.template, 'expected:', test.expected, 'result:', result);
}