

function Student(args) {
    this.name = args.name || "unnamed";
}

Student.prototype.hello = function() {
    console.log("Hello, " + this.name + "!");
}

var s = new Student({
name: "xiaoming"
});
s.hello();


function PrimaryStudent(args) {
    Student.call(this, args);
    this.grade = args.grade || 1;
}

function F() {
}

F.prototype = Student.prototype;

PrimaryStudent.prototype = new F();
PrimaryStudent.prototype.constructor = PrimaryStudent;

PrimaryStudent.prototype.getGrade = function() {
    return this.grade;
}

var xiaoming = new PrimaryStudent({
name: 'xiaoming',
grade: 2
});

console.log(xiaoming.name);
console.log(xiaoming.grade);
console.log(xiaoming.__proto__ === PrimaryStudent.prototype);
console.log(xiaoming.__proto__.__proto__ === PrimaryStudent.prototype);
console.log(xiaoming instanceof PrimaryStudent);
console.log(xiaoming instanceof Student);


