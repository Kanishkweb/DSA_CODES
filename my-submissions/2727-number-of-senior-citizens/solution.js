/**
 * @param {string[]} details
 * @return {number}
 */
var countSeniors = function(details) {
    // iterate over the details array;
    let noOfPassenger = 0;
    for(let i = 0;i< details.length;i++){
        let ps = details[i];
        if(ps[11] == 6 && ps[12] == 0) continue;
        if(ps[11] >= 6){
            noOfPassenger++
        }
    }
    return noOfPassenger;
};
