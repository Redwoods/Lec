// http server : http_server.js

var http = require('http');
port = 3000;

var server = http.createServer(function(request, response) {
  response.writeHeader(200, {
    "Content-Type": "text/plain"
  });
  response.write("Hello HTTP server from node.js in Brackets"); // WEB response
  response.write("\nMy ID is MS00, COMSI!");
  response.end();

});

server.listen(port);
console.log("Server Running on " + port + 
	".\nLaunch http://localhost:" + port);