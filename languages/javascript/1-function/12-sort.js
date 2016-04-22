'use strict';

var arr = [1, 2, 5, 10, 18, 21];
for (let i = 0; i < arr.length; i++) {
    console.log(arr[i]);
}

console.log("after sort:");
var strsortarr = arr.sort();  // sort by string order, so fuck me!
for (let i = 0; i < strsortarr.length; i++) {
    console.log(strsortarr[i]);
}


console.log("after sort 2:");
var normalsort = arr.sort(function (x, y) {
        if (x < y) {
        return -1;
        } else if (x === y) {
        return 0;
        } else {
        return 1;
        }
        });
for (let i = 0; i < normalsort.length; i++) {
    console.log(normalsort[i]);
}
