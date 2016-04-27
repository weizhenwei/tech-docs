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

console.log(re.exec(s));  // null，直到结束仍没有匹配到

