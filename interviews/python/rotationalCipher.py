def rotationalCipher(input, rotationFactor):
    alphabet = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    digits = '0123456789'
    encrypted = ''
    for char in input:
        plainChar = char.upper()
        isUpperCase = plainChar == char
        if plainChar in alphabet:
            alphabetIndex = alphabet.index(plainChar)
            encryptedIndex = (alphabetIndex + rotationFactor) % len(alphabet)
            if isUpperCase:
                encrypted += alphabet[encryptedIndex]
            else:
                encrypted += alphabet[encryptedIndex].lower()
            continue
        if plainChar in digits:
            digitsIndex = digits.index(plainChar)
            encryptedIndex = (digitsIndex + rotationFactor) % len(digits)
            encrypted += digits[encryptedIndex]
            continue
        encrypted += char
    return encrypted

tests = [
    { 'input': 'All-convoYs-9-be:Alert1.', 'rotationFactor': 4, 'expected': 'Epp-gsrzsCw-3-fi:Epivx5.' },
    { 'input': 'abcdZXYzxy-999.@', 'rotationFactor': 200, 'expected': 'stuvRPQrpq-999.@' }
]

for test in tests:
    result = rotationalCipher(test['input'], test['rotationFactor'])
    print('input:', test['input'], 'rotationFactor:', test['rotationFactor'], 'expected:', test['expected'], 'result:', result)