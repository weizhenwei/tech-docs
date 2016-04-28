var s = 'JavaScript, VBScript, JScript and ECMAScript';
var re=/[a-zA-Z]+Script/g;

console.log(re.exec(s));  // ['JavaScript']
console.log(re.lastIndex);  // 10

console.log(re.exec(s));  // ['VBScript']
console.log(re.lastIndex);  // 20

console.log(re.exec(s));  // ['JScript']
console.log(re.lastIndex);  // 29

console.log(re.exec(s));  // ['ECMAScript']
console.log(re.lastIndex);  // 44


var reg2  = new RegExp('ABC\\-001', 'g');
var s2 = "ABC-001ABC-001sdfsdfABC-001sd";
console.log(reg2.exec(s2));
console.log(reg2.lastIndex);
console.log(reg2.exec(s2));
console.log(reg2.lastIndex);
console.log(reg2.exec(s2));
console.log(reg2.lastIndex);
console.log(reg2.test(s2));
console.log(reg2.test(s));


