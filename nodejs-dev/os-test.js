
var os = require('os');
var util =  require('util');
console.log('os.type ' + util.inspect(os.type()));
console.log('os.platform ' + util.inspect(os.platform()));
console.log('os.arch ' + util.inspect(os.arch()));
console.log('os.release ' + util.inspect(os.release()));

console.log('process.env.HOME ' + process.env.HOME);
console.log('process.env.HOMEPATH ' + process.env.HOMEPATH);
console.log('process.env.USERPROFILE ' + process.env.USERPROFILE);
