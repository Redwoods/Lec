// http server : http_server.js

var http = require('');
port = ;

var server = http.createServer(function(request, response) {
  response.writeHeader(, {
    "Content-Type": "text/plain"
  });
  response.write("Hello HTTP server from node.js in Brackets"); // WEB response
  response.write("\nMy ID is !");
  response.;

});

server.listen(port);
console.log("Server Running on " + port + 
	".\nLaunch http://localhost:" + port);