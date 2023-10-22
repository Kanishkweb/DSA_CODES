/**
 * @param {number} num
 * @return {number}
 */
let num = 38;

function addDigits(num) {
  const nStr = num.toString();
  let sum = 0;
  for (let i = 0; i < nStr.length; i++) {
    sum = sum + parseInt(nStr[i]);
  }
  console.log("The sum is :", sum);

  if (sum.toString().length == 1) {
    return sum;
  } else if (sum.toString().length > 1) {
    return addDigits(sum); // Add the 'return' statement here
  }
}

let a = addDigits(num);
console.log(`The result is : ${a}`);



