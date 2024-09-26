// Write a function expect that helps developers test their code. It should take in any value val and return an object with the following two functions.

// 1.   toBe(val) accepts another value and returns true if the two values === each other. If they are not equal, it should throw an error "Not Equal".

// 2.   notToBe(val) accepts another value and returns true if the two values !== each other. If they are equal, it should throw an error "Equal".





var expect = function(val) {
    return{
        toBe : (val2) => {
            if(val !== val2) throw new Error("Not Equal");
            else return true;
        },
        notToBe : (val2) => {
            if(val === val2) throw new Error("Equal");
            else return true; 
        }
    }
};

try {
    console.log(expect(5).toBe(5)); 
} 
catch (e) {
    console.error(e.message);
}

try {
    console.log(expect(5).notToBe(5));
} 
catch (e){
    console.error(e.message); 
}