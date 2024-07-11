/**
 * @param {string} s
 * @return {string}
 */
var reverseParentheses = function (s) {
    let stack = [];
    let temp = "";
    // loop for pushing the element in the stack
    for (let i = 0; i <= s.length - 1; i++) {
        if (s[i] == ")") {
            temp = "";
            let j = i;
            while (stack[stack.length - 1] != "(") {
                temp += stack.pop();
            }
            if (stack.length > 0) stack.pop();
            // now push the temp to the stack;
            for (let i = 0; i < temp.length; i++) {
                stack.push(temp[i]);
            }
        } else {
            stack.push(s[i]);
        }
    }
    temp = "";
    // iterate stack;
    for (let i = 0; i < stack.length; i++) {
        temp += stack[i];
    }
    return temp;
};
