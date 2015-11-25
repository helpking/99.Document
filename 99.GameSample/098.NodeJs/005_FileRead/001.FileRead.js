var fs = require("fs");

fs.readFile('/Users/b06685/Desktop/97.TestDir/99.GameSample/098.NodeJs/004.FileReadSync/999.Test.txt', function(err, data){
  if (err) return console.error(err);
  console.log(data.toString());
});
console.log("Program End");
