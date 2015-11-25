var fs = require("fs");

fs.readFile('Test.txt', function(err, data){

  if (err){
    console.log(err.stack);
    return;
  }
  console.log(data.toString());
});

console.log("Program Ended.");
