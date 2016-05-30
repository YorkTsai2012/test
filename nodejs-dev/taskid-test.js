

var taskid = function () {
    var _id = 1;
    return function() {
        return _id++;
    }   
}();

for (var i = 0; i < 10; i++) {
	console.log(taskid());
}
