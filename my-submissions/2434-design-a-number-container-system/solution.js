
var NumberContainers = function() {
    
};

/** 
 * @param {number} index 
 * @param {number} number
 * @return {void}
 */
NumberContainers.prototype.change = function(index, number) {
    
};

/** 
 * @param {number} number
 * @return {number}
 */
var NumberContainers = function() {
    this.m = new Map();
    this.d = new Map();
};
NumberContainers.prototype.change = function(i, n) {
    if(this.m.has(i) && this.m.get(i)==n)return;
    this.m.set(i, n);
    if(!this.d.has(n)) this.d.set(n, new MinHeap());
    this.d.get(n).push(i);
};
NumberContainers.prototype.find = function(n) {
    if(!this.d.has(n)) return -1;
    let h = this.d.get(n);
    while(h.size() && this.m.get(h.peek())!==n) h.pop();
    return h.size()? h.peek() : -1;
};
function MinHeap() {
    this.a = [];
}
MinHeap.prototype.push = function(x) {
    this.a.push(x);
    let i = this.a.length - 1;
    while(i>0){
        let p = (i-1)>>1;
        if(this.a[p] <= this.a[i]) break;
        [this.a[p], this.a[i]] = [this.a[i], this.a[p]];
        i = p;
    }
};
MinHeap.prototype.pop = function() {
    let r = this.a[0], l = this.a.pop();
    if(this.a.length){
        this.a[0] = l;
        let i = 0, n = this.a.length;
        while(true){
            let l = i*2+1, r = i*2+2, m = i;
            if(l < n && this.a[l] < this.a[m]) m = l;
            if(r < n && this.a[r] < this.a[m]) m = r;
            if(m === i) break;
            [this.a[i], this.a[m]] = [this.a[m], this.a[i]];
            i = m;
        }
    }
    return r;
};
MinHeap.prototype.peek = function() {
    return this.a[0];
};
MinHeap.prototype.size = function() {
    return this.a.length;
};

/** 
 * Your NumberContainers object will be instantiated and called as such:
 * var obj = new NumberContainers()
 * obj.change(index,number)
 * var param_2 = obj.find(number)
 */
