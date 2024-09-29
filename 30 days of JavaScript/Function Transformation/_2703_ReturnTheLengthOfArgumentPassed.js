// Write a function argumentsLength that returns the count of arguments passed to it.




/**
 * @param {...(null|boolean|number|string|Array|Object)} args
 * @return {number}
 */
var argumentsLength = function(...args) {
    // Approach 1
    return args.length;

    // Approach 2
    // let i =0;
    // args.forEach(()=>{i++;})
    // return i;
};

// Testcase
console.log(argumentsLength(1, 2, 3)); 
console.log(argumentsLength());
console.log(argumentsLength(null, "hello", [1, 2, 3], {key: "value"}));
console.log(argumentsLength(42));
console.log(argumentsLength(true, false, undefined));