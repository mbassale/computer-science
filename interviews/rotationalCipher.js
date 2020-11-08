
function rotationalCipher(input, rotationFactor) {
    const alphabet = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ';
    const digits = '0123456789';
    let encrypted = '';
    // O(n) time
    for (let i = 0; i < input.length; i++) {
        const textChar = input[i].toUpperCase();
        const isUpperCase = textChar == input[i];
        // check for alphabetic character
        const alphabetIndex = alphabet.indexOf(textChar);
        if (alphabetIndex >= 0) {
            const encryptedIndex = (alphabetIndex + rotationFactor) % alphabet.length;
            const encryptedChar = alphabet[encryptedIndex];
            encrypted += isUpperCase ? encryptedChar : encryptedChar.toLowerCase();
            continue;
        }

        // check for a digit
        const digitsIndex = digits.indexOf(textChar);
        if (digitsIndex >= 0) {
            const encryptedIndex = (digitsIndex + rotationFactor) % digits.length;
            const encryptedChar = digits[encryptedIndex];
            encrypted += encryptedChar;
            continue;
        }

        // fallback, just append
        encrypted += textChar;
    }
    return encrypted;
}

const tests = [
    { input: 'All-convoYs-9-be:Alert1.', rotationFactor: 4, expected: 'Epp-gsrzsCw-3-fi:Epivx5.' },
    { input: 'abcdZXYzxy-999.@', rotationFactor: 200, expected: 'stuvRPQrpq-999.@' }
];

for (const test of tests) {
    const result = rotationalCipher(test.input, test.rotationFactor);
    console.log('input:', test.input, 'rotationFactor:', test.rotationFactor, 'expected:', test.expected, 'result:', result);
}