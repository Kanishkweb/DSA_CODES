/**
 * @param {number[]} gifts
 * @param {number} k
 * @return {number}
 */
var pickGifts = function(gifts, k) {
    let total = 0;
    for (let gift of gifts) {
        total += gift;
    }
    
    // Create a max-heap
    gifts.sort((a, b) => b - a);
    
    for (let i = 0; i < k; i++) {
        // Extract the largest gift
        let largest = gifts[0];
        // Calculate the new value after taking the square root
        let new_value = Math.floor(Math.sqrt(largest));
        // Update the total value
        total -= (largest - new_value);
        // Replace the largest gift with the new value
        gifts[0] = new_value;
        // Sort the array again to maintain the max-heap property
        gifts.sort((a, b) => b - a);
    }
    
    return total;
};
