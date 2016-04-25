'use strict';


function pow(x) {
    return x * x;
}

var arr = [1, 2, 3, 4, 5, 6, 7, 8, 9];
for (let i = 0; i < arr.length; i++) {
    console.log(arr[i]);
}

arr.map(pow);  // arr is unchanged, but the result store in another array;
for (let i = 0; i < arr.length; i++) {
    console.log(arr[i]);
}

var arr2 = arr.map(pow);  // assign result to another array;
for (let i = 0; i < arr2.length; i++) {
    console.log(arr2[i]);
}

arr = arr.map(pow);  // or assign result to itself;
for (let i = 0; i < arr.length; i++) {
    console.log(arr[i]);
}

function add(x, y) {
    return x + y;
}

var sum = arr.reduce(add);
console.log("Sum of array is %d", sum);


