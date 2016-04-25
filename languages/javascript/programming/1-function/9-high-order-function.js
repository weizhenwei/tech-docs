
function square(x) {
    return x * x;
}

function cube(x) {
    return x * x * x;
}

function square_and_cube(x, y, n) {
    return x(n) + y(n);
}

var x = 10;
var y = square_and_cube(square, cube, x);
console.log(y);


