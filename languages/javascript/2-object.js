
var xiaoming = {
      name: "xiaoming",
      birth: 1999,
      'middle-school': "Hefei No.42 Middle school",
      'high-school': "Hefei No.1 High school",
      height: 170,
      weight: 70,
      score: 613
};

console.log(xiaoming.name);
console.log(xiaoming.birth);
console.log(xiaoming["middle-school"]);  // must access in this way;
console.log(xiaoming["high-school"]);
console.log(xiaoming.height);
console.log(xiaoming.weight);
console.log(xiaoming.score);

xiaoming.age = 18;  // add a parameter;
console.log(xiaoming.age);

delete xiaoming.score;  // delete a parameter;
console.log(xiaoming.score);  // undefined;

var hasGrade = 'grade' in xiaoming;  // not a good way;
console.log(hasGrade);  // false;
var hasToString = 'toString' in xiaoming; // derived from object;
console.log(hasToString);  // true;
var hasName = xiaoming.hasOwnProperty("name");  // good way;
console.log(hasName);  // true;


