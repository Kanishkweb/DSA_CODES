/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {number[]}
 */
var nodesBetweenCriticalPoints = function (head) {
    let temp = head;
    if (temp.next.next == null) return [-1, -1]; // critical point canoot be possible in two length LL;
    let arr = [];
    // Step - 1 - Iterate on the Linked List;
    let lenOfMiddle = 2;
    while (temp.next.next != null) {
        let a = temp.val;
        let m = temp.next.val;
        let c = temp.next.next.val;
        if (a > m && m < c || a < m && m > c) {
            // condition for local minima and local maxima;
            arr.push([m, lenOfMiddle]);
        }
        temp = temp.next;
        lenOfMiddle++;
    }
    // if there are fewer than 2 critical point then
    if (arr.length < 2) return [-1, -1];
    // Now calculate the maxDistance; 
    let firstNodeP = arr[0][1];
    let lastNodeP = arr[arr.length - 1][1];
    let maxDistance = lastNodeP - firstNodeP;
    // Now calculate the minDistance;
    let minDistance = Infinity;
    for (let i = 0; i <= arr.length - 2; i++) {
        let firstP = arr[i][1];
        let secondP = arr[i + 1][1];
        minDistance = Math.min(minDistance, (secondP - firstP));
    }
    return [minDistance,maxDistance];
};
