
var js = document.getElementById("js");
var list = document.getElementById("list");
list.appendChild(js);

var haskell = document.createElement("p");
haskell.id = "haskell";
haskell.innerText = "Haskell";
list.appendChild(haskell);

var python = document.getElementById('python');
var cpp = document.createElement("p");
cpp.id = "cpp";
cpp.innerText = "CPP";
list.insertBefore(cpp, python);
list.insertBefore(haskell, python);


