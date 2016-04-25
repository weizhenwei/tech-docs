

console.log(typeof 123);
console.log(typeof NaN);
console.log(typeof "string");
console.log(typeof true);
console.log(typeof undefined);
console.log(typeof Math.abs);
console.log(typeof null);
console.log(typeof []);
console.log(typeof {});


// wrapped object;
var n = new Number(123);
var b = new Boolean(true);
var s = new String("str");

// wrapped object doesn't equal to original value;
if (n === 123) {
    console.log("object === number");
} else {
    console.log("object != number");
}

