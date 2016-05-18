
var fs = require("fs");
var data = "";

var readStream = fs.createReadStream("input.txt");
readStream.setEncoding('utf8');

readStream.on("data", function(chunk) {
        data += chunk;
    });
readStream.on("end", function() {
        console.log(data);
    });
readStream.on("error", function(err) {
        console.log(err.stack);
    });

console.log("program end");

