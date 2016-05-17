
var addon = require('./build/Release/callback');

addon(function(msg) {
        console.log(msg); // 'hello world'
        });
