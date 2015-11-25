
var fs = require("fs");

//create a readable stream
var readerStream = fs.createReadStream('/Users/b06685/Desktop/97.TestDir/99.GameSample/098.NodeJs/012_Pipe/999.ReadFile.txt');

//create a writable stream
var writerStream = fs.createWriteStream('/Users/b06685/Desktop/97.TestDir/99.GameSample/098.NodeJs/012_Pipe/999.WriteFile.txt');

//pipe the read and write operations
//read test.txt and write data to test2.txt
readerStream.pipe(writerStream);

console.log("Program Ended");

