'use strict';  // must included with quotes;

var s = "hello, world!";
console.log(s);
s = s.toUpperCase();
console.log(s);
s = s.toLowerCase();
console.log(s);

s.toUpperCase();  // s didn't changed unless assign result to it;
console.log(s);

var sub = s.substring(7, 10);
console.log(sub);

var i = 2344;
console.log(i);
if (i % 2 === 0) {
    console.log("i is even");
} else {
    console.log("i is odd");
}


