/**
 * @param {number} numBottles
 * @param {number} numExchange
 * @return {number}
 */
var numWaterBottles = function (numBottles, numExchange) {
    let total = 0;
    let r = 0;
    while (numBottles != 1 || r != 0) {
        total += numBottles;
        if((numBottles + r) < numExchange) break;
        if(r > 0){
            numBottles += r;
            r = 0;
        }
        if (numBottles % numExchange == 0) {
            numBottles = numBottles / numExchange
        } else if (numBottles > numExchange){
            r = numBottles % numExchange;
            numBottles = Math.floor(numBottles / numExchange);
        }
        if((numBottles + r) < numExchange){
            total += numBottles
            break;
        }
    }
    return total;
};
