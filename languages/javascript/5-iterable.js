'use strict';

// Array, Map, Set are so called iterable object;

var a = [1, 2, 3, 4, 5];
for (var x of a) {
    console.log(x);
}
// function(element, index, array);
a.forEach(function(element, index, array) {
        console.log("a[%d] = %d", index, element);
});


var s = new Set(['a', 'b', 'c']);
for (var x of s) {
    console.log(x);
}
s.forEach(function(element, sameElement, set) {
        console.log("set[i] = %s", element);
});


var m = new Map([[1, "one"], [2, "two"], [3, "three"]]);
for (var x of m) {
    console.log("%d:%s", x[0], x[1]);
}
m.forEach(function(value, key, map) {
    console.log("map[%s] = %s", key, value);
});


