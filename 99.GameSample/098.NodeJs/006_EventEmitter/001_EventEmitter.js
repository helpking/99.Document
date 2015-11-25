// import events module
var events = require('events');
// create an eventEmitter object
var eventsEmitter = new events.EventEmitter();

// create a function connected which is to bo executed
// When 'connected' event occurs
var connected = function connected(){
  console.log('Connection succesful!!');

  // fire the data_received event
  eventsEmitter.emit('data_received');
}

// bind the connection event with the connected function
eventsEmitter.on('connection', connected);

// bind the data_received event with the anonymous function
eventsEmitter.on('data_received', function(){
  console.log('data received succesfully.');
});

// fire the connection event
eventsEmitter.emit('connection');

console.log("Program Ended.");
