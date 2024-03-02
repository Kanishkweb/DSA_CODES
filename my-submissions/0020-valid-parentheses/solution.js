/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
  // for iterating over the string
  let temp = [];
  for (i = 0; i < s.length; i++) {
    temp.push(s[i]);
    if (temp.length - 1 > 0) {
      let prev = temp[temp.length - 2];
      let curr = temp[temp.length - 1];
      if (prev == "(" && curr == ")") {
        temp.pop();
        temp.pop();
      } else if (prev == "{" && curr == "}") {
        temp.pop();
        temp.pop();
      } else if (prev == "[" && curr == "]") {
        temp.pop();
        temp.pop();
      }
    }
  }
  if (temp.length == 0) return true;
  else return false;
};
