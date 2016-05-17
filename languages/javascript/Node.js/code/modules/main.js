
var hello = require("./hello1");
hello.world();

var Hello = require("./hello2");
hello = new Hello();
hello.setName("gy");
hello.sayHello();

