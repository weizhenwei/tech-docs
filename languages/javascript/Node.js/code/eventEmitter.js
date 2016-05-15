var events = require("events");

var eventEmitter = new events.EventEmitter();

eventEmitter.on("some_event", function() {
    console.log("some_event invoked!");
});

setTimeout(function() {
    eventEmitter.emit("some_event");
}, 1000);


eventEmitter.on("someEvent", function(arg1, arg2) {
    console.log("someEvent listener1", arg1, arg2);
});
eventEmitter.on("someEvent", function(arg1, arg2) {
    console.log("someEvent listener2", arg1, arg2);
});
eventEmitter.emit("someEvent", "arg1", "arg2");


var listener1 = function listener1() {
    console.log("listener1 invoked");
}

var listener2 = function listener2() {
    console.log("listener2 invoked");
}
eventEmitter.addListener("connection", listener1);
eventEmitter.on("connection", listener2);

var eventListeners = require("events").EventEmitter.listenerCount(eventEmitter, "connection");
console.log(eventListeners + " listeners added");

eventEmitter.emit("connection");

eventEmitter.removeListener("connection", listener1);
console.log("listener1 is removed");
eventEmitter.emit("connection");

eventListeners = require("events").EventEmitter.listenerCount(eventEmitter, "connection");
console.log(eventListeners + " listeners added");

console.log("Done");

