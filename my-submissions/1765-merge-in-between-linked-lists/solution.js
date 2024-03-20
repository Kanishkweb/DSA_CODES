/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} list1
 * @param {number} a
 * @param {number} b
 * @param {ListNode} list2
 * @return {ListNode}
 */
var mergeInBetween = function (list1, a, b, list2) {
    let temp = list1;
    let i = 0;
    let tempA = null;
    let tempB = null;
    // iterate on list 1;
    while (temp != null) {
        if (a-1 == i) {
            tempA = temp;
        } else if (b+1 == i) {
            tempB = temp;
            break;
        }
        i++;
        temp = temp.next;
    }
    // now step -2;
    tempA.next = list2;
    while (tempA.next != null) {
        tempA = tempA.next;
    }
    tempA.next = tempB;
    return list1
};
