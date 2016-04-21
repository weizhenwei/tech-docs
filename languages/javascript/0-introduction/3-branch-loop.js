
var age = 1;
if (age >= 18) {
    console.log("adult");
} else if (age >= 6) {
    console.log("teenager");
} else {
    console.log("kid");
}


var x = 0;
for (var i = 0; i <= 1000; i++) {
    x += i;
}
console.log(x);

var arr = [1, 2, 3, 4, 5, 6];
for (var elem in arr) {
    // x += elem;  // NOTE: the elem is string, not number;
    x += parseInt(elem);
}
console.log(x);

var i = 0;
while (i < 100) {
    x += i;
    i++;
}
console.log(x);

do {
    x += i;
    i++;
} while (i < 200);
console.log(x);

while (i < 300) {
    if (i % 2 == 0) {
        i++;
        continue;
    } else {
        x += i;
        i++;
    }
}
console.log(x);



