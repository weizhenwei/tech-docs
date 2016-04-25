
function abs(x) {
    if (x >= 0) {
        return x;
    } else {
        return -x;
    }
}

var origin = -23;
var x = abs(origin);
console.log("abs(%d) = %d", origin, x);

var goodabs = function (x) {
    return abs(x);
}

origin = -34;
x = abs(origin);
console.log("goodabs(%d) = %d", origin, x);


// arguments stores all the parameters;
function betterabs() {
    if (arguments.length === 0) {
        return 0;
    }
    var x = arguments[0];
    return x >= 0 ? x : -x;
}

origin = -44;
x = abs(origin);
console.log("betterabs(%d) = %d", origin, x);

function bestabs(a, b, ...rest) {
    console.log(a);
    console.log(b);
    console.log(rest);
}