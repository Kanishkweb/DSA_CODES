/**
 * @param {number[][]} customers
 * @return {number}
 */
var averageWaitingTime = function (customers) {
    let finishTime;
    let waitTime = 0;
    let lastFinishTime = 0;
    let op = true;
    for (let i = 0; i <= customers.length - 1; i++) {
        let arrivalTime = customers[i][0];
        let prepTime = customers[i][1];
        if (lastFinishTime <= arrivalTime) {
            op = true;
        }
        if (op) {
            finishTime = arrivalTime + prepTime;
            op = false;
        } else {
            finishTime = lastFinishTime + prepTime;
        }
        waitTime += finishTime - arrivalTime;
        lastFinishTime = finishTime;
    }
    return waitTime / customers.length;
};
