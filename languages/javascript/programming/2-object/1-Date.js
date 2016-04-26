
var now = new Date();
console.log(now);
console.log("full year:%d", now.getFullYear());
console.log("month:%d", now.getMonth());
console.log("date:%d", now.getDate());
console.log("day:%d", now.getDay());
console.log("hours:%d", now.getHours());
console.log("minutes:%d", now.getMinutes());
console.log("seconds:%d", now.getSeconds());
console.log("milliseconds:%d", now.getMilliseconds());
console.log("time:%d", now.getTime());

var d = new Date(2015, 5, 19, 20, 15, 30, 123);
console.log(d);

// var dd = Date.parse('2015-06-24T19:49:22.875+08:00');
// console.log(dd);
// 
// var ddd = new Date('1435146562875');
// console.log(ddd);

var today = new Date();
if (today.getMonth() === 1 && today.getDate() === 14) {
        console.log('亲爱的，我预定了晚餐，晚上6点在餐厅见！');
} else {
        console.log("亲爱的，今天不是情人节");
}

