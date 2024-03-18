/**
 * @param {number[][]} intervals
 * @param {number[]} newInterval
 * @return {number[][]}
 */
var insert = function (intervals, newInterval) {
    let isTaskDone = false;
    if (intervals.length == 0) {
        return [newInterval];
    }
    // first step is to iterate on the intervals and also newInterval
    for (let i = 0; i < intervals.length; i++) {
        let element = intervals[i];
        // 3 > 2 then merge
        if (element[1] >= newInterval[0] && element[0] <= newInterval[1]) {
            // merge
            let first = Math.min(element[0], newInterval[0]);
            let last = Math.max(element[1], newInterval[1]);
            let arr = [first, last];
            intervals[i] = arr;
            isTaskDone = true;
            break;
        }
    }
    // now second loop for merging and doing all the stuff
    let lastIndex = 0;
    let i = 1;
    while (i < intervals.length) {
        let lastEle = intervals[lastIndex];
        let currEle = intervals[i];
        if (lastEle[1] >= currEle[0]) {
            // do merging;
            let first = Math.min(lastEle[0], currEle[0]);
            let last = Math.max(lastEle[1], currEle[1]);
            let arr = [first, last];
            intervals.splice(i, 1); // delete one element
            intervals[lastIndex] = arr;
        } else {
            i++;
            lastIndex++;
        }
    }
    if (isTaskDone == false) {
        intervals.push(newInterval);
    }
    // covert all element in acending order
    intervals.sort((a, b) => {
        return a[0] - b[0];
    });
    return intervals;
};
