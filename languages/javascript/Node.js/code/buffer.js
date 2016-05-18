
var buf = new Buffer(256);
var len = buf.write("Hello, world!");
console.log("write " + len + " bytes");

var str = buf.toString('utf8', 0, len);
console.log(str);

// var json = buf.toJSON(buf);
// console.log(json);


var buf1 = new Buffer("Hello, world!");
var buf2 = new Buffer("Are you OK?");
var buf3 = Buffer.concat([buf1, buf2]);
console.log(buf3.length);
console.log(buf3.toString());

