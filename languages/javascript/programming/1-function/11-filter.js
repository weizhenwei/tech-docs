'use strict';

var arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
for (let i = 0; i < arr.length; i++) {
    console.log(arr[i]);
}
var oddarr = arr.filter(function (x) {
        return x % 2 === 1;
        });
for (let i = 0; i < oddarr.length; i++) {
    console.log(oddarr[i]);
}



// test prime;
function get_primes(arr) {
    function isPrime(x) {
        if (x === 1) {
            return false;
        }

        var sqrtVal = Math.sqrt(x);
        var i = 2;
        while (i <= sqrtVal) {
            if (x % i === 0) {
                return false;
            } else {
                i++;
            }
        }
        return true;
    }

    return arr.filter(isPrime);
}

var x, r, arr = [];
for (x = 1; x < 100; x++) {
        arr.push(x);
}
r = get_primes(arr);

console.log("get prime");
for (let i = 0; i < r.length; i++) {
    console.log(r[i]);
}
console.log(r.toString());
if (r.toString() === [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47,
        53, 59, 61, 67, 71, 73, 79, 83, 89, 97].toString()) {
    console.log('test pass!');
} else {
    console.log('test fail:' + r.toString());
}

