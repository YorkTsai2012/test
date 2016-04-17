
var util = require("util");

var Worker = function() {
    this.name = "york";
    this.age = 28;
} 

Worker.prototype.Println = function() {
    var self = this;
    console.log("name = " + self.name);
    console.log("age = " + self.age);
    console.log(util.inspect(self));
};


if (require.main == module) {
    var worker = new Worker();
    worker.Println();
}
