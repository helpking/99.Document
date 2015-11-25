
var fs = require("fs");
var data = '';
//create a readable stream
var readerStream = fs.createReadStream('/Users/b06685/Desktop/97.TestDir/99.GameSample/098.NodeJs/010_ReadStream/999.Test.txt');

//set the encoding to be utf8. 
readerStream.setEncoding('UTF8');

//handle stream events
readerStream.on('data', function(chunk) {
   data += chunk;
});

readerStream.on('end',function(){
   console.log(data);
});

readerStream.on('error', function(err){
   console.log(err.stack);
});
console.log("Program Ended");

