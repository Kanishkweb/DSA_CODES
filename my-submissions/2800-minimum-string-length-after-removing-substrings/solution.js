var minLength = function(s) {
    let stack = []
    for(let x of s){
        if(x=='B' && stack[stack.length-1]=='A'){
            stack.pop()
        }
        else if(x=='D' && stack[stack.length-1]=='C'){
            stack.pop()
        }
        else stack.push(x)


    }
    return stack.length
};
