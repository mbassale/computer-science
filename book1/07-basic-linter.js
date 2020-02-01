
class Linter {

    stack = [];

    constructor() {}

    lint(text) {
        this.stack = [];
        for (let i = 0; i < text.length; i++) {
            let character = text.charAt(i);
            if (this.isOpeningBrace(character)) {
                this.stack.push(character);
            } else if (this.isClosingBrace(character)) {
                if (this.isClosingMostRecentOpeningBrace(character)) {
                    this.stack.pop();
                } else {
                    console.error('Incorrect closing brace: ' + character + ' at index ' + i);
                }
            }
        }

        if (this.stack.length > 0) {
            console.error(this.stack[this.stack.length - 1] + ' does not have a closing brace');
        }
    }

    isOpeningBrace(character) {
        return ['(', '[', '{'].includes(character);
    }

    isClosingBrace(character) {
        return [')', ']', '}'].includes(character);
    }

    isClosingMostRecentOpeningBrace(character) {
        return this.openingBraceOf(character) === this.stack[this.stack.length - 1];
    }

    openingBraceOf(character) {
        switch (character) {
            case ')':
                return '(';
            case ']':
                return '[';
            case '}':
                return '{';
        }
        return null;
    }
}

let linter = new Linter();
linter.lint('( var x = { y: [1, 2, 3] } )');

linter.lint('( var x = { y: [1, 2, 3] ) }');