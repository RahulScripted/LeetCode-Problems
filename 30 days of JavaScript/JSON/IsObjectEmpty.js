// Given an object or an array, return if it is empty. An empty object contains no key-value pairs. An empty array contains no elements. You may assume the object or array is the output of JSON.parse.




// Function to check if an object or array is empty
var isEmpty = function(obj) {
    if (Array.isArray(obj)) return obj.length === 0;
    else return Object.keys(obj).length === 0;
};

// Test cases
console.log(isEmpty([]));
console.log(isEmpty([1, 2, 3]));
console.log(isEmpty({}));     
console.log(isEmpty({ a: 1, b: 2 }));
console.log(isEmpty(''));  
console.log(isEmpty(null)); 
console.log(isEmpty(undefined));
console.log(isEmpty({ length: 0 }));
