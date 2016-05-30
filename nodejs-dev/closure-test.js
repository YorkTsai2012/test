
//javascript  闭包 关键  自调用函数只执行一次

function add_plain() {
    var counter = 0;
    function plus() {counter += 1;}
    plus();    
    return counter; 
}

//closure
var add = (function () {
    var counter = 0;
    return function () {
        return counter += 1;
    }
})();

console.log(add());
console.log(add());
console.log(add());

//another example closure
var taskid = function () {
    var _id = 10001;
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

/* explain 



The variable add is assigned the return value of a self-invoking function.

The self-invoking function only runs once. It sets the counter to zero (0), and returns a function expression.

This way add becomes a function. The "wonderful" part is that it can access the counter in the parent scope.

This is called a JavaScript closure. It makes it possible for a function to have "private" variables.

The counter is protected by the scope of the anonymous function, and can only be changed using the add function.


    A closure is a function having access to the parent scope, even after the parent function has closed.

*/



(function () {
    console.log("anonymous function");
})();


for(var i = 0; i < 5; i++) {
    setInterval( function() {
            console.log(i);
    }, 1000);
}

var name = "The Window";
var object = {
    name : "My Object",
　　getNameFunc : function(){
　　    var that = this;
　　　　return function() {
            return that.name;
　　    }
    }
};
console.log(object.getNameFunc()());
