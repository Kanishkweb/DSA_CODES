/**
 * @param {number} n
 * @param {number[][]} roads
 * @return {number}
 */
var maximumImportance = function (n, roads) {
    // first step is to make an frequency map
    let op = {};
    // now loop over the array
    for (i = 0; i <= roads.length - 1; i++) {
        let roadone = roads[i][0];
        let roadtwo = roads[i][1];
        if (op[roadone]) {
            op[roadone]++;
        } else if (!op[roadone]) {
            op[roadone] = 1;
        }
        // same conditions for road two
        if (op[roadtwo]) {
            op[roadtwo]++;
        } else if (!op[roadtwo]) {
            op[roadtwo] = 1;
        }
    }
    // now convert freq map into array
    let arr = Object.entries(op);
    // Allot the importance to the op
    // do sorting the array according to the high to low frequency
    arr = arr.sort((a, b) => {
        if (b[1] !== a[1]) {
            return b[1] - a[1];
        } else {
            return b[0] - a[0];
        }
    });
    // return sortedArr;
    for (i = 0; i <= arr.length - 1; i++) {
        // now we have to reflect the inportance interger to op freq map;
        if (op[arr[i][0]]) {
            op[arr[i][0]] = n;
        }
        n--;
    }
    // return arr;
    let totalImp = 0;
    for (i = 0; i <= roads.length - 1; i++) {
        let roadone = roads[i][0]; // 0
        let roadtwo = roads[i][1]; // 1
        let temp = op[roadone] + op[roadtwo];
        totalImp = totalImp + temp;
    }
    // when the loop end then print the totalImportance
    return totalImp;
};
