/**
 * @param {number[][]} classes
 * @param {number} extraStudents
 * @return {number}
 */
var maxAverageRatio = function(classes, extraStudents) {
    const getDiff = (a,b) => (a+1)/(b+1) - a/b;
    const queue = new MaxPriorityQueue();
    for(let [pass, total] of classes) {
        queue.enqueue([pass,total], getDiff(pass,total))
    }
    while(extraStudents > 0) {
        const [pass,total] = queue.dequeue().element;
        queue.enqueue([pass+1,total+1], getDiff(pass+1,total+1))
        extraStudents--;
    }
    let sum = 0;
    while(queue.size()) {
        const [pass,total] = queue.dequeue().element;
        sum += pass/total;
    }
    return sum/classes.length;
};
