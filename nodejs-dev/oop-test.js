
var util = require("util");

var Worker = function() {
    this.name = "york";
    this.age = 28; 
} 

Worker.prototype.Println = function() {
    console.log("name = " + this.name);
    console.log("age = " + this.age);
    console.log(util.inspect(this));
};


if (require.main == module) {
    var worker = new Worker();
    worker.Println();
}
