
var arr = [1, 2, 3, 4, 5, 6, 7];
var len = arr.length;
console.log(len);
arr.length = 10;
len = arr.length;
console.log(len);
arr[7] = 8;
arr[8] = 9;
arr[9] = 10;

var index = arr.indexOf(7);  // index starts at 0, so the index of element 7 is 6;
console.log(index);


var subarr = arr.slice(0, 4);
console.log(subarr.length);
subarr.push(32324);
console.log(subarr.length);
subarr.pop();
subarr.pop();
console.log(subarr.length);
subarr.unshift(123);
console.log(subarr[0]);


var newarr = arr.concat(subarr);
console.log(arr.length);  // arr didn't changed;
console.log(newarr.length);

var long_str = newarr.join('-');
console.log(long_str);


for (var i = 0; i < newarr.length; i++) {
    console.log("newarr[%d] = %d", i, newarr[i]);
}

console.log("*******************After shitf*********************************");
newarr.shift();
newarr.shift();
for (var i = 0; i < newarr.length; i++) {
    console.log("newarr[%d] = %d", i, newarr[i]);
}



