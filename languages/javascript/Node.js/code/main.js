 var events = require("events");

 var eventEmitter = new events.EventEmitter();

 var connectHandler = function connected() {
     console.log("connected succeed!");
     eventEmitter.emit("data_received");
 };

eventEmitter.on("connection", connectHandler);

eventEmitter.on("data_received", function() {
     console.log("data received!");
});

eventEmitter.emit("connection");


var fs = require("fs");
fs.readFile("input.txt", function(err, data) {
    if (err) {
        console.log(err.stack);
        return;
    }
    console.log(data.toString());
});
console.log("program ended!");


