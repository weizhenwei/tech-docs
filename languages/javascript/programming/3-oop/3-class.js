'use strict'

function Student(name) {
    this.name = name;
}

Student.prototype.hello = function () {
    console.log('Hello, ' + this.name + '!');
}

var xiaoming = new Student("xiaoming");
xiaoming.hello();

// use /usr/local/Cellar/node/5.9.1/bin/node to run this script;
class Student2 {
    constructor(name) {
        this.name = name;
    }

    hello() {
        console.log("Hello, " + this.name + "!");
    }
}

var xiaoming2 = new Student2("xiaoming2");
xiaoming2.hello();


class PrimaryStudent extends Student2 {
    constructor(name, grade) {
        super(name);
        this.grade = grade;
    }

    getGrade() {
        console.log("I am at grade " + this.grade);
    }
}

var ps = new PrimaryStudent("xiaohong", 3);
ps.hello();
ps.getGrade();


class Animal {
    constructor(name) {
        this.name = name;
    }
}

class Cat extends Animal {
    constructor(name) {
        super(name);
    }

    say() {
        console.log("Hello, " + this.name);
    }
}

var cat = new Cat("kitty");
cat.say();


