
var fs = require("fs");
var util = require("util");

fs.readdir('.', function (err, files) {
    if (err)
        throw new Error(err);
    var stats = [];

	console.log(' files ' + util.inspect(files));	

    files.map(function (file, idx) {
        fs.stat(file, function (err, stat) {
            if (err)
                throw new Error(err);
            stats[idx] = stat;
            if (stats.length === files.length)
                console.log(stats);
        });
    })
})

