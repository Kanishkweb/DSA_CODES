var ProductOfNumbers = function() {
    this.list = [];
    this.prod = 1;
};

/** 
 * @param {number} num
 * @return {void}
 */
ProductOfNumbers.prototype.add = function(num) {
    if (num === 0) {
        this.list = [];
        this.prod = 1;
    } else {
        this.prod *= num;
        this.list.push(this.prod);
    }
};

/** 
 * @param {number} k
 * @return {number}
 */
ProductOfNumbers.prototype.getProduct = function(k) {
    if (this.list.length < k) return 0;
    if (this.list.length === k) return this.list[this.list.length - 1];
    return this.list[this.list.length - 1] / this.list[this.list.length - k - 1];
};
