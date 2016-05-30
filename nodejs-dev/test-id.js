
var taskid = function () {
    var _id = 1;
    var a = 2;
    var b = 3;
    console.log("_id = " + _id);
    console.log("a = " + a);
    console.log("b = " + b);
    return function() {
        // IEEE 754 Math.pow(2, 53) + 1 == Math.pow(2, 53)
        if (_id === 9007199254740992) {
            _id = 32768;
        }   
        return _id++;
    }   
}();

console.log(taskid());
console.log(taskid());
console.log(taskid());
