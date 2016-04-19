
'use strict';

var m = new Map([["Michael", 95], ["Bob",  75], ["Tracy", 85]]);
var score = m.get("Michael");
console.log("Michael's score = %d", score);
m.set("Phiebe", 96);
m.set("Kobe", 100);
if (m.has("Kobe")) {
    console.log("Has Kobe's score = %d", m.get("Kobe"));
} else {
    console.log("Don't have Kobe's score");
}

var s = new Set([1, 2, 3,]);
s.add(4);
s.add(5);
s.add(6);
s.delete(1);
console.log("set's length = %d", s.length);  // use s.size, not s.length;
console.log("set's size = %d", s.size);
console.log("set has 2 = ", s.has(2));
for (let item of s) {
    console.log(item);
}

