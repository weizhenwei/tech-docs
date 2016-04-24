'use strict';

// my compiler didn't support generator

function* foo(x) {
    yield x + 1;
    yield x + 2;
    yield x + 3;
    yield x + 4;
    yield x + 5;
}

var f = foo(5);

console.log(f.next());
console.log(f.next());
console.log(f.next());
console.log(f.next());

