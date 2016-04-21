// 'use strict';

function foo() {
    var x = 1;
    x = x + 1;
    console.log("in function foo(), x = %d", x);

    function bar() {
        var y = x + 1;
        console.log("in function bar(), x = %d, y = %d", x, y);
    }
    bar();
}

foo();


function foo1() {
    // please define all variable in the begining of the function;
    var y = "Bob";
    var x = "Hello " + y;
    console.log(x);
    // var y = "Bob";
}
foo1();


// global variable domain;
var course = "Learn Javascript";
console.log(course);
// console.log(window.course);


// namespace;
var wzwNamespace = {};
wzwNamespace.name = "weizhenwei";
wzwNamespace.age = "28";
wzwNamespace.gender = "male";
console.log(wzwNamespace.name);
console.log(wzwNamespace.age);
console.log(wzwNamespace.gender);


// local variable;
for (var i = 0; i < 10; i++) {
    console.log(i);
}
console.log(i);  // i is still available, NOTE: this is different from C/C++;

// for (let j = 0; j < 10; j++) {
//     console.log(j);
// }
// // console.log(j);  // syntax error;

// const;
const PI = 3.1415;
console.log(PI);




