// ecg_express.js  
// Express with CORS
var express = require('express');
var cors = require('cors');  // CORS: Cross Origin Resource Sharing
var app = express();
app.use(cors());  // CORS 

var web_port = 3030;  // express port

// MongoDB
var mongoose = require('mongoose');
var Schema = mongoose.Schema;  // Schema object
// MongoDB connection
mongoose.connect('mongodb://localhost:27017/ecg'); // DB name
var db = mongoose.connection;    
db.on('error', console.error.bind(console, 'connection error:'));
db.once('open', function callback () {
        console.log("mongo db connection OK.");
});
// Schema
var ecgSchema = new Schema({
    date : String,
    ecg : String
});
var Sensor = mongoose.model("Sensor", ecgSchema);  // sensor data model

// Web routing address
app.get('/', function (req, res) {  // localhost:3030/
  res.send('Hello Arduino-ECG IOT!');
});
// find all data & return them
app.get('/ecg', function (req, res) {
    Sensor.find(function(err, data) {
        res.json(data);
    });
});
// find data by id
app.get('/ecg/:id', function (req, res) {
    Sensor.findById(req.params.id, function(err, data) {
        res.json(data);
    });
});

// Express WEB
app.use(express.static(__dirname + '/public'));  // WEB root folder
app.listen(web_port);  // port 3030
console.log("Express_ECG_IOT is running at port:3030");
