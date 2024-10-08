var minSwaps = function(s) {
    let st = []; // Stack to track unbalanced parentheses
    
    for (let i of s)
        if (i === '[')
            st.push(i); // Push opening bracket to the stack
        else if (st.length > 0 && st[st.length - 1] === '[')
            st.pop(); // Excluding balanced pairs
        else
            st.push(i); // Push closing bracket to the stack
    
    let unbalancedPairs = st.length / 2;
    let swaps = Math.ceil(unbalancedPairs / 2.0);
    return swaps;
};
