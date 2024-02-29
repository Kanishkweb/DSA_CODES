/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} n
 * @return {ListNode}
 */
var removeNthFromEnd = function (head, n) {
    let enco = head;
    let temp = head;
    let count = 0;
    // corner case if head = [1];
    if (head.next == null) return null;
    // loop for going to the last
    while (temp.next != null) {
        temp = temp.next;
        if (count != n) {
            count++;
        } else if (count >= n) {
            head = head.next;
        }
    }
    if (count + 1 == n) {
        head = head.next;
        return head;
    }
    head.next = head.next.next;
    return enco;
};
