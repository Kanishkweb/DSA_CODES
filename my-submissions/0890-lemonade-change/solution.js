/**
 * @param {number[]} bills
 * @return {boolean}
 */
var lemonadeChange = function (bills) {
    let map = {};
    // initailaization of the map;
    map[5] = 0;
    map[10] = 0;
    map[20] = 0;
    for (let i = 0; i < bills.length; i++) {
        let bill = bills[i];
        if (bill == 5) {
            map[bill]++;
        } else if (bill > 5) {
            // check what the change you have in your vault;
            if (bill == 10) {
                if (map[5]) {
                    map[5]--;
                    map[bill]++;
                } else {
                    return false;
                }
            } else if (bill == 20) {
                if (map[10] && map[5]) {
                    map[10]--;
                    map[5]--;
                    map[bill]++;
                } else if (map[5] > 2) {
                    map[5] -= 3;
                } else {
                    return false
                }
            }
        }
    }
    return true;
};
