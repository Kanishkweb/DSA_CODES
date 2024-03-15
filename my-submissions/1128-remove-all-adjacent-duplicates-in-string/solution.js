/**
 * @param {string} s
 * @return {string}
 */
var removeDuplicates = function (s) {
    let st = [];
    // now iterate on the string;
    st.push("dummy"); // push first character of the string
    let last = s.length - 1;
    //   st.push(s[last]); // push first character of the string
    let i = last;
    // Time : O(n)
    while (i >= 0) {
        let front = st.length - 1;
        if (s[i] == st[front]) {
            st.pop();
            i--;
        } else {
            st.push(s[i]);
            i--;
        }
    }
    // now convert st to string and return
    // Time : O(n)
    let str = "";
    while (st.length != 1) {
        str += st.pop();
    }
    return str;
};
