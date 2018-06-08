// hr_node_mongodb.js

var serialport = require('serialport');
var portName = 'COM7';  // check your COM port!!
var port    =   process.env.PORT || 3000;

var io = require('socket.io').listen(port);

// MongoDB
var mongoose = require('mongoose');
var Schema = mongoose.Schema;
// MongoDB connection
mongoose.connect('mongodb://localhost:27017/hrv'); // DB name
    var db = mongoose.connection;
    db.on('error', console.error.bind(console, 'connection error:'));
    db.once('open', function callback () {
        console.log("mongo db connection OK.");
});
// Schema
var hrSchema = new Schema({
    date : String,
    hr : String
});
// Display data on console in the case of saving data.
hrSchema.methods.info = function () {
    var hrInfo = this.date
    ? "Current date: " + this.date +", HR: " + this.hr 
    : "I don't have a date"
    console.log("hrInfo: " + hrInfo);
}

// serial port object
var sp = new serialport(portName,{
    baudRate: 115200,   // 9600  19200  38400
    dataBits: 8,
    parity: 'none',
    stopBits: 1,
    flowControl: false,
    parser: serialport.parsers.readline('\r\n')  
});

var readData = '';  // this stores the buffer
var hrv ='';
var mdata =[]; // this array stores date and data from multiple sensors
var firstcommaidx = 0;
var Sensor = mongoose.model("Sensor", hrSchema);  // sensor data model

sp.on('data', function (data) { // call back when data is received
    readData = data.toString(); // append data to buffer
    firstcommaidx = readData.indexOf(','); 
    // parsing data into signals
    if (firstcommaidx > 0) {
        hrv = readData.substring(firstcommaidx + 1);
        readData = '';       
        dStr = getDateString();
        mdata[0]=dStr;  // Date
        mdata[1]=hrv;  // hr data
        var iot = new Sensor({date:dStr, hr:hrv});
        // save iot data to MongoDB
        iot.save(function(err, iot) {
            if(err) return handleEvent(err);
            iot.info();  // Display the information of iot data  on console.
        })
        io.sockets.emit('message', mdata);  // send data to all clients 
    } else {  // error 
        console.log(readData);
    }
});

// helper function to get a nicely formatted date string for IOT
function getDateString() {
    var time = new Date().getTime();
    // 32400000 is (GMT+9 Korea, GimHae)
    // for your timezone just multiply +/-GMT by 3600000
    var datestr = new Date(time +32400000).
    toISOString().replace(/T/, ' ').replace(/Z/, '');
    return datestr;
}

io.sockets.on('connection', function (socket) {
    // If socket.io receives message from the client browser then 
    // this call back will be executed.
    socket.on('message', function (msg) {
        console.log(msg);
    });
    // If a web browser disconnects from Socket.IO then this callback is called.
    socket.on('disconnect', function () {
        console.log('disconnected');
    });
});

