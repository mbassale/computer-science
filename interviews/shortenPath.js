
function shortenPath(path) {
    const isAbsolute = path[0] == '/';
    const pathParts = path.split('/');
    const stack = [];
    for (const token of pathParts) {
        if (token == '..') {
            if (isAbsolute) {
                if (stack.length > 0) {
                    stack.pop();
                }
            } else {
                if (stack.length > 0 && stack[stack.length - 1] != '..') {
                    stack.pop();
                } else {
                    stack.push('..');
                }
            }
        } else if (token == '.' || token == '/' || token == '') {
            continue;
        } else {
            stack.push(token);
        }
    }
    const resolvedPath = stack.join('/');
    return isAbsolute ? '/' + resolvedPath : resolvedPath;
}

const tests = [
    { path: '/foo/../test/../test/../foo//bar/./baz', expected: '/foo/bar/baz' },
    { path: '/../../foo/../../bar/baz', expected: '/bar/baz' },
    { path: '../../foo/../../bar/baz', expected: '../../../bar/baz' },
];

for (const test of tests) {
    const result = shortenPath(test.path);
    console.log('path:', test.path, 'expected:', test.expected, 'result:', result);
}