/**
 * @param {number} n
 * @return {number}
 */
function alternateDigitSum(n) {
  const nStr = n.toString();
  let resp = parseInt(nStr[0]);
  let resm = 0;
  for (let i = 1; i < nStr.length; i++) {
    if (i % 2 === 1) {
      resm -= parseInt(nStr[i]);
    } else {
      resp += parseInt(nStr[i]);
    }
  }
  return resp + resm;
}

let n = 521;
let a = alternateDigitSum(n);
console.log(a);

