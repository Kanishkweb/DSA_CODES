/**
 * @param {string} expression
 * @return {boolean}
 */
var parseBoolExpr = function (expression) {
  let stack = [];
  let i = 0;
  let lastExp = [];
  while (i < expression.length) {
    if (expression[i] == "!") {
      // logical NOT
      lastExp.push(expression[i]);
    } else if (expression[i] == "&") {
      // logical AND
      lastExp.push(expression[i]);
    } else if (expression[i] == "|") {
      // logical OR
      lastExp.push(expression[i]);
    }
    // when ever you find
    if (expression[i] == ")") {
      let map = {};
      while (stack[stack.length - 1] != lastExp[lastExp.length - 1]) {
        // start poping until lastExpressstion
        let pop = stack.pop();
        if (pop == "t" || pop == "f") {
          if (!map[pop]) {
            map[pop] = 1;
          } else {
            map[pop]++;
          }
        }
      }
      stack.pop();
      let exp = lastExp.pop();
      stack.push(helper(exp, map));
    }
    if (i == expression.length - 1) {
      break;
    }
    stack.push(expression[i]);
    i++;
  }
  // now check the stack if there is true or false;
  if (stack[0] == "t") {
    return true;
  } else {
    return false;
  }
};

function helper(expression, map) {
  if (expression == "!") {
    // logical NOT
    if (map["t"]) {
      return "f";
    } else return "t";
  } else if (expression == "&") {
    // logical AND
    if (map["f"]) {
      return "f";
    } else {
      return "t";
    }
  } else if (expression == "|") {
    // logical OR
    if (map["t"] && map["f"]) {
      return "t";
    } else if (!map["t"]) {
      return "f";
    } else {
      return "t";
    }
  }
}

