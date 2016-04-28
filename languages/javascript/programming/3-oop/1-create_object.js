
function Student(name) {
    this.name = name;
    this.height = 1.3;
    this.hello = function () {
        console.log('Hello, ' + this.name + '!');
    }
}

var xiaoming = new Student("Xiaoming");
console.log(xiaoming.name);
console.log(xiaoming.height);
xiaoming.hello();
var xiaoHua = new Student("XiaoHua");
console.log(xiaoHua.name);
console.log(xiaoHua.height);
xiaoHua.hello();
console.log(xiaoming.hello === xiaoHua.hello);



console.log();
function Student2(name) {
    this.name = name;
    this.height = 1.2;
}
Student2.prototype.hello = function() {
    console.log('Hello, ' + this.name + '!');
};

var xiaohong = new Student2("xiaohong");
console.log(xiaohong.name);
console.log(xiaohong.height);

var xiaoli = new Student2("xiaoli");
console.log(xiaoli.name);
console.log(xiaoli.height);
console.log(xiaohong.hello === xiaoli.hello);

