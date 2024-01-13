/**
 * @param {number[][]} matches
 * @return {number[][]}
 */
var findWinners = function (matches) {
    // Winner list
    let winner = {};
    let looser = {};
    for (i = 0; i < matches.length; i++) {
        // Condition for winner
        if (winner[matches[i][0]]) {
            winner[matches[i][0]]++;
        } else {
            winner[matches[i][0]] = 1;
        }
        // Condition for looser
        if (looser[matches[i][1]]) {
            looser[matches[i][1]]++;
        } else {
            looser[matches[i][1]] = 1;
        }
    }
    let WinnerArr = Object.keys(winner);
    let result = [];
    // Iterate both object to cheak the value
    let test = [];
    // Loop
    for (i = 0; i < WinnerArr.length; i++) {
        if (!looser[WinnerArr[i]]) {
            test.push(WinnerArr[i]);
        }
    }
    let winnerArr = test.map(Number);
    result.push(winnerArr); // answer[0]
    let test2 = Object.keys(looser).filter((key) => looser[key] === 1);
    let LooserArr = test2.map(Number);
    result.push(LooserArr); // answer[1]
    return result;
};
