'use strict';

// window display the browser window;
alert("window inner size:" + window.innerWidth + "*" + window.innerHeight);
alert("window outer size:" + window.outerWidth + "*" + window.outerHeight);

// navigator indicates the browser's message,
alert("appName = " + navigator.appName + "\n" +
        "appVersion = " + navigator.appVersion + "\n" +
        "language = " + navigator.language + "\n" +
        "platform = " + navigator.platform + "\n" +
        "userAgent = " + navigator.userAgent);

// screen indicates the screen message;
alert("screen width = " + screen.width + "\n" +
        "screen height = " + screen.height + "\n" +
        "screen colordepth = " + screen.colorDepth);

// location indicates current page's url
// location.assign(): load a new page;
// loacation.reload(): reload current page;
var url = location.href;
alert("Current page's url:" + url);
alert("Current page's protocol:" + location.protocol + "\n" +
        "host:" + location.host + "\n" +
        "port:" + location.port + "\n" +
        "pathname:" + location.pathname + "\n" +
        "search:" + location.search + "\n" +
        "hash:" + location.hash);


// document indicates current page: the root node of DOM;
alert("Current page's title:" + document.title);
document.title = "Learn Javascript hard!";
alert("Current page's title:" + document.title);


var i, s, menu, drinks;
menu = document.getElementById("drink-menu");
drinks = document.getElementsByTagName("dt");
alert("drinks.length = " + drinks.length);
s = "the drinks offered:"
for (i = 0; i < drinks.length; i++) {
    s = s + drinks[i].innerHTML + ",";
}
alert(s);


// cookie
alert("Current page's cookie:" + document.cookie);

