
function countdown(number) {
    console.log(number);
    if (number === 0) return;
    countdown(number - 1);
}

function factorial(number) {
    if (number < 0) return 0;
    if (number === 0 || number === 1) return 1;
    return number * factorial(number - 1);
}

//countdown(10);

console.log('factorial(3) = ' + factorial(3));