'use strict';

var xiaoming = {
    name: "Xiaoming",
    birth: 1990,
    age: function () {  // bind function to attribute;
        // var y = new Date().getFullYear();
        // return y - this.birth;  // "this" indicates current object;

        var that = this;
        function getAgeFromBirth() {
            var y = new Date().getFullYear();
            return y - that.birth;  // "this" indicates current object;
        }
        return getAgeFromBirth();
    }
}

console.log(xiaoming.age());

// var func = xiaoming.age;
// console.log(func());  // NaN!!! in strict mode, this causes compile error;



// use of apply;
function getAge2() {
    var y = new Date().getFullYear();
    return y - this.birth;
}

var xiaoming2 = {
    name: 'xiaoming2',
    birth: 1990,
    age: getAge2
};

console.log(xiaoming2.age()); // 26
console.log(getAge2.apply(xiaoming2, []));  // 26, this points to xiaoming, parameters is null;
console.log(getAge2.call(xiaoming2));       // 26, this points to xiaoming, parameters is null;

