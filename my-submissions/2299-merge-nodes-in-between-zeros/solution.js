/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
function createNode(val, head) {
    return {
        val: val,
        next: head
    }
}

function removeZero(head) {
    // Step - 1 -  remove the first zero;
    head = head.next;
    // Step - 2- remove the last zero;
    let temp = head;
    while (temp.next.next != null) {
        temp = temp.next;
    }
    temp.next = null;
    // Step - 3 - remove all zeroes from the middle 
    let original = head;
    let start = head;
    let middle = head;
    while (head.next != null) {
        head = head.next // for looping
        if (head.val == 0) {
            head = head.next;
        }
        middle = head;
        // time to merge;
        start.next = middle;
        start = middle;
    }
    return original;
}



var mergeNodes = function (head) {
    if (head == null) return head;
    // now iterate over the linked list
    let op = head;
    let lastZero = head;
    while (head.next != null) {
        let temp = 0;
        head = head.next;
        while (head.val != 0) {
            temp += head.val;
            head = head.next;
        }
        // head have the next zero pointer
        lastZero.next = createNode(temp, head);
        lastZero = head; // to update the lastZero pointer
    }
    // Step - 2 :- To remove all zerors
    let result = removeZero(op);
    return result;
};
