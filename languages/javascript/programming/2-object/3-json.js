var xiaoming = {
    name: '小明',
    age: 14,
    gender: true,
    height: 1.65,
    grade: null,
    'middle-school': '\"W3C\" Middle School',
    skills: ['JavaScript', 'Java', 'Python', 'Lisp']
};

var xm = JSON.stringify(xiaoming);  // stringify;
console.log(xm);

var xm2 = JSON.stringify(xiaoming, null, ' ');
console.log(xm2);

var xiaoming2 = {
    name: '小明',
    age: 14,
    gender: true,
    height: 1.65,
    grade: null,
    'middle-school': '\"W3C\" Middle School',
    skills: ['JavaScript', 'Java', 'Python', 'Lisp'],
    toJSON: function () {
        return { // 只输出name和age，并且改变了key：
            'Name': this.name,
            'Age': this.age
        };
    }
};

var xm3 = JSON.stringify(xiaoming2, null, ' ');
console.log(xm3);

var objxiaoming = JSON.parse(xm3);
console.log(objxiaoming.Name);
console.log(objxiaoming.Age);

