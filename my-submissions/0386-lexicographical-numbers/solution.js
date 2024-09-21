var lexicalOrder = function(n) {
    let res=[]
    function rec_adder (x,n){
        if(x>n)return 
        res.push(x)
        let pe = x*10
        for(let i=0;i<10;i++){
            rec_adder(pe+i,n)
        }
    }
    for(let i=1;i<10;i++){
        rec_adder(i,n)
    }
    return res
};
