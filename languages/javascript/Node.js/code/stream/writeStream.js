
var fs = require("fs");
var data = "Hello, the NodeJS world!\n";

var writeStream = fs.createWriteStream("output.txt");
writeStream.write(data, 'utf8');
writeStream.end();

writeStream.on("finish", function() {
        console.log("write finished!");
    });

writeStream.on("error", function(err) {
        console.log(err.stack);
    });

console.log("program end");

