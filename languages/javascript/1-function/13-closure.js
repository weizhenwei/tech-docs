
function lazy_sum(arr) {
    var sum = function() {
        return arr.reduce(function(x, y) {
                return x + y;
                });
    }

    return sum;
}

var func1 = lazy_sum([1, 2, 3, 4, 5]);

console.log("Invoke lazy_sum():");
var sum = func1();
console.log("sum = %d", sum);


function count() {
    var arr = [];
    for (var i = 1; i <= 3; i++) {
        arr.push((function (n) {
                    return function() {
                    return n * n;
                    }
                    })(i));
    }

    return arr;
}

var results = count();
var f1 = results[0];
var f2 = results[1];
var f3 = results[2];

console.log(f1());
console.log(f2());
console.log(f3());

// anonymous function define and invoke instantly.
var res = (function(x) {
        return x * x;
        })(5);
console.log(res);


// class encapsulation
function create_counter(initial) {
    var x = initial || 0;
    return {
        inc: function() {
                 x += 1;
                 return x;
             }
    }
}

var c1 = create_counter();
console.log(c1.inc());
console.log(c1.inc());
console.log(c1.inc());

var c2 = create_counter(10);
console.log(c2.inc());
console.log(c2.inc());
console.log(c2.inc());


