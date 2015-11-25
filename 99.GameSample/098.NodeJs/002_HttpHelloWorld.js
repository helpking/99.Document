var http = require("http");
http.createServer(function (request, response) {
  // Http Status : 200 : OK
  // Content Type : text/plain
  response.writeHead(200, {'Content-Type' : 'text/plain'});
  // send the response body as "Hello World"
  response.end('Hello World\n');
}).listen(8081);
// console will print the message
console.log('Server is running ad http://127.0.0.1:8081');

