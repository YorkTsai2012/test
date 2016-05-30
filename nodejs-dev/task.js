var Fibers = require('fibers');
var future = require('fibers/future');
var wait = future.wait;

var taskid = function () {
    var _id = 1;
    return function() {
        return _id++;
    }
}();

var _innerQueue = function() {
    var self = this;
    this.queue = {};
}

_innerQueue.prototype.add = function(task) {
    this.queue[task.id] = task;
}

_innerQueue.prototype.get = function(id) {
    return this.queue[id];
}

_innerQueue.prototype.del = function(id) {
    delete this.queue[id];
}

_innerQueue.prototype.dump = function() {
    console.log(this.queue);
}

var taskQueue = function() {
    var _t = new _innerQueue();
    return function() {
        return _t;
    }
}();

function task(func) {
    var self = this;
    this.id = taskid();
    this.func = func;
    this.yieldRun = false;

    this.f = Fibers(function(arg) {
        self.func.apply(self, arg);
        taskQueue().del(self.id);
        self.f = null;
    });

    taskQueue().add(this);
}

task.prototype.run = function() {
    if ( this.yieldRun ) {
        this.f.run(arguments[0]);
    }
    else {
        this.yieldRun = true;
        this.f.run(arguments);
    }
}

task.prototype.wait = function() {
}

task.prototype.yield = Fibers.yield;
task.prototype.reset = Fibers.reset;

exports.task = task;
exports.taskQueue = taskQueue;
exports.yield = Fibers.yield;
exports.future = future;

if ( require.main == module ) {
    t = new task(null);
    t1 = new task(null);
}
