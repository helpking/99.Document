
var fs = require("fs");

//Asynchronous read
fs.readFile('/Users/b06685/Desktop/97.TestDir/99.GameSample/098.NodeJs/013_AysncAndSyncReadFile/999.Test.txt', function (err, data) {
    if (err) return console.error(err);
    console.log("Asynchronous read: " + data.toString());
});

//Synchronous read
var data = fs.readFileSync('/Users/b06685/Desktop/97.TestDir/99.GameSample/098.NodeJs/013_AysncAndSyncReadFile/999.Test.txt');
console.log("Synchronous read: " + data.toString());

console.log("Program Ended");

