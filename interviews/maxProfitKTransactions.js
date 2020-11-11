
function maxProfitWithKTransactions(prices, k) {
    if (prices.length == 0) {
        return 0;
    }
    const profits = [];
    for (let maxTransactions = 0; maxTransactions <= k; maxTransactions++) {
        profits[maxTransactions] = prices.slice().map(p => 0);
        let maxProfit = -Infinity;
        for (let day = 1; maxTransactions > 0 && day < prices.length; day++) {
            maxProfit = Math.max(maxProfit, profits[maxTransactions - 1][day - 1] - prices[day-1]);
            profits[maxTransactions][day] = Math.max(profits[maxTransactions][day - 1], prices[day] + maxProfit);
        }
    }
    return profits[k][prices.length - 1];
}

const tests = [
    { prices: [5, 11, 3, 50, 60, 90], k: 2, expected: 93 }
];

for (const test of tests) {
    const result = maxProfitWithKTransactions(test.prices, test.k);
    console.log('prices:', test.prices, 'k:', test.k, 'expected:', test.expected, 'result:', result);
}