// 原型对象:
var Student = {
    name: 'Robot',
    height: 1.2,
    run: function () {
        console.log(this.name + ' is running...');
    }
};

var xiaoming = {
    name: "xiaoming"
};
xiaoming.__proto__ = Student;
console.log(xiaoming.name);
console.log(xiaoming.height);
xiaoming.run();

// use Object.create() instead of __proto__ assignment;
function createStudent(name) {
    var s = Object.create(Student);
    // 初始化新对象:
    s.name = name;
    return s;
}

var xiaoming2 = createStudent('小明');
xiaoming2.run(); // 小明 is running...
console.log("Is Xiaoming tudent:" + (xiaoming2.__proto__ === Student)); // true


