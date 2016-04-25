'use strict';

// my compiler didn't support generator

function* foo(x) {
    yield x + 1;
    yield x + 2;
    yield x + 3;
    yield x + 4;
    yield x + 5;
}


// method 1: use next() function to iterate;
var f = foo(5);
var obj = f.next();
while (obj.done != true) {
    console.log(obj.value);
    obj = f.next();
}

// method 2: use of to iterate;
for (var x of foo(15)) {
    console.log(x);
}



// generate_id
function* next_id() {
    var i = 0;
    while (i++ < 65535) {
        yield i;
    }
}

var obj2 = next_id();
console.log(obj2.next());
console.log(obj2.next());
console.log(obj2.next());
console.log(obj2.next());

