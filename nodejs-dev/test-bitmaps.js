
var BitMaps = require("./BitMaps.js");

var bitmaps = new BitMaps(8, "0x234");

console.log(bitmaps.size());
console.log(bitmaps.toString());

bitmaps.set(2,3);
console.log(bitmaps.toString());
