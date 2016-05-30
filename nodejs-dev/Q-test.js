
var fs = require("fs");
var Q = require("q");


/*
var fs_readFile = Q.denodeify(fs.readFile);
var promise = fs_readFile('Hello.java');
promise.then(console.log, console.error);
*/


var fs_readFile = function(file, encoding) {
  var deferred = Q.defer()
  fs.readFile(file, encoding, function (err, data) {
    if (err) deferred.reject(err) // rejects the promise with `er` as the reason
    else deferred.resolve(data) // fulfills the promise with `data` as the value
  })
  return deferred.promise // the promise is returned
};
fs_readFile('Hello.java').then(console.log, console.error);
console.log("after fs");

/*
var allPromise = Q.all([ fs_readFile('Hello.java'), fs_readFile('os-test.js') ]);
allPromise.then(console.log, console.error);
*/
