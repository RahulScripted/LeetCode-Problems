// Given two promises promise1 and promise2, return a new promise. promise1 and promise2 will both resolve with a number. The returned promise should resolve with the sum of the two numbers.




var addTwoPromises = async function(promise1, promise2) {
    const [value1, value2] = await Promise.all([promise1, promise2]);
    return value1 + value2;
};

// Example usage:
const promise1 = new Promise((resolve) => setTimeout(() => resolve(5), 100));

const promise2 = new Promise((resolve) => setTimeout(() => resolve(10), 200));

addTwoPromises(promise1, promise2).then((result) => {
    console.log(result); 
});