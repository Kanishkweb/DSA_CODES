/**
 * @param {number} n
 * @return {number}
 */
var nthUglyNumber = function (n) {
    let currentVal;
    let st = new Set();
    st.add(1);
    for (let i = 0; i < n; i++) {
        currentVal = Math.min(...st);
        st.delete(currentVal);
        st.add(currentVal * 2)
        st.add(currentVal * 3)
        st.add(currentVal * 5)
    }
    return currentVal;
};
