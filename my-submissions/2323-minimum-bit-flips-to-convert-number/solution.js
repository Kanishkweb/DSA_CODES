/**
 * @param {number} start
 * @param {number} goal
 * @return {number}
 */
var minBitFlips = function(start, goal) {
    // XOR to find differing bits between start and goal
    let xorResult = start ^ goal;
    let count = 0;
    
    // Count the number of 1's in the XOR result
    while (xorResult > 0) {
        count += xorResult & 1;  
        xorResult >>= 1;        
    }
    
    return count;
};
