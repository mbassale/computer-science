
class PrintManager {
    queue = [];

    queuePrintJob(document) {
        this.queue.push(document);
    }

    run() {
        while (this.queue.length > 0) {
            this.print(this.queue.shift());
        }
    }

    print(document) {
        console.log(`Printing Document ${document}`)
    }
}

let printManager = new PrintManager();
printManager.queuePrintJob('First Document');
printManager.queuePrintJob('Second Document');
printManager.queuePrintJob('Third Document');
printManager.run();
