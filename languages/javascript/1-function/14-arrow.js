// 'use strict';

// node -v = v5.9.1

// my js compiler currently didn't support arrow function;
var fn = x => x * x;
console.log(fn(3));


var square = (x, y) => x * x + y * y;


console.log(square(3, 4));


var obj = {
    birth: 1990,
    getAge: function() {
        var b = this.birth;
        var fn = () => new Date().getFullYear() - this.birth;
        return fn();
    }
}

console.log(obj.getAge());


