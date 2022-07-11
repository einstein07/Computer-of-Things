import React, { useState, useEffect, useRef } from "react";
import logo from './logo.svg';
import './App.css';
import Wasm from "react-wasm";
import createModule from "./ComputerOfThings.mjs";

// Webassembly: shared objects?
// https://stackoverflow.com/questions/67655485/webassembly-possible-to-have-shared-objects
// WebAssemby Javascript interaction
// https://dominoc925.blogspot.com/2020/12/how-to-setup-c-webassembly-component-to.html 
// How to grab byte array after srialization in c++
// https://stackoverflow.com/questions/51483768/how-to-grab-byte-array-after-serialization
/**
* @param {Module}
**/
function wrapProcessWorkPackage(Module) {
  // JS-friendly wrapper around the WASM call
  return function (request) {
    
    const flatInputData = new Uint8Array(request);
    
    console.log ("request length: " + flatInputData.length);
    console.log ("request bytes per element: " + flatInputData.BYTES_PER_ELEMENT);
    console.log("Request byte array:");
    console.log(flatInputData);
    
    const buffer = Module._malloc(
      flatInputData.length * flatInputData.BYTES_PER_ELEMENT 
    );
    
    Module.HEAP32.set(flatInputData, buffer >> 2);

    // allocate memory for the result array
    const resultBuffer = Module._malloc(
      flatInputData.length * flatInputData.BYTES_PER_ELEMENT 
    );
    // make the call
    const resultPointer = Module.ccall(
      "processWorkPackages",
      "number",
      "number",
      [buffer, resultBuffer]
    );
    console.log(  Module.getValue(resultPointer, "i8") );
    console.log( Module.getValue(resultPointer+4, "i8") );  
    console.log( Module.getValue(resultPointer+8, "i8") );
    console.log( Module.getValue(resultPointer+12, "i8") );
    console.log( Module.getValue(resultPointer+16, "i8") );      

    // Release memory
    Module._free(buffer);
    Module._free(resultBuffer);
    return resultPointer;
  };
}

/**async function getByte() {

  var importObject = {
    imports: {
      imported_func: function(arg) {
        console.log(arg);
      }
    }
  };
  
  fetch('ComputerOfThings.wasm').then(response =>
    response.arrayBuffer()
  ).then(bytes =>
    WebAssembly.instantiate(bytes, importObject)
  ).then(result =>
    result.instance.exports.exported_func()
  );
}*/

function App() {
  //////////////////////////////////////////////////////////////////////////////
  // States and variables
  //////////////////////////////////////////////////////////////////////////////
  const [connectionState, setConnectionState] = useState(false);
  const [receiveState, setReceiveState] = useState(false);
  const [processWorkPackages, setProcessWorkPackage] = useState();
  const reader = new FileReader();
  var serverAddress;
  var websocket;
  var request;

  useEffect(
    // useEffect here is roughly equivalent to putting this in componentDidMount
    // for a class component
    () => {
      createModule().then((Module) => {
        // need to use callback form (() => function) to ensure that `add` is
        // set to the function if you use setX(myModule.cwrap(...)) then React
        // will try to set newX = myModule.cwrap(currentX), which is wrong
        setProcessWorkPackage(() => wrapProcessWorkPackage(Module));
      });
    },
    []
  );
  const onProcessConnectButtonClick = () => {
    serverAddress = document.getElementById("serverTextArea").value;
    var completeAddress = "ws://" + serverAddress;
    //const websocket = new WebSocket("ws://localhost:8765/");
    websocket = new WebSocket(completeAddress);
    websocket.binaryType = 'arraybuffer';
    var buffer;

    websocket.onmessage = function (evt) {
      
        /*console.log("blob");
        var reader = new FileReader();
        reader.readAsArrayBuffer(evt.data);
        reader.addEventListener("loadend", function(e)
        {
            buffer = new Uint16Array(e.target.result);  // arraybuffer object
            setReceiveState(true);
            Array.prototype.slice.call(buffer.slice());

        });*/
        var buf = new ArrayBuffer(8);
        var request = new Uint8Array(evt.data);

        console.log(request)
        setReceiveState(true);
        
        console.log("ready to process data");
        //console.log("Recieved data:\n" + request);
        var response = processWorkPackages( request);

        console.log("Sending response. . .");
        websocket.send(response);
        
    };

    websocket.onopen = () => {
      console.log("Connected");
      setConnectionState(true);

      //setInterval(function() {
      //console.log("receive state: " + receiveState);
      // Im' not busy anymore - set a flag or something like that
      //if(/**websocket.bufferedAmount == 0 &&*/ receiveState){
        
      //}
        /**if (websocket.bufferedAmount == 0){
          
        }*/
      //}, 50);
    }

    /**websocket.addEventListener("message", ({ data }) => {
    
      console.log("receiving data . . .");
      
      request = data;
      setReceiveState(true);

      
      
      
    });*/
    /**websocket.addEventListener("open", () =>{
      
    });*/
  }
  const onProcessDisconnectButtonClick = () => {
    setConnectionState(false);
    websocket.close();
  }
 //getByte();
 if (!connectionState) {
  return (
    <div className="App">
      <header className="App-header">
        <h1> Computer of Things</h1>
        <h4> Not connected to server</h4>

        <textarea id="serverTextArea"></textarea>
        <div className="App-button-container">
          <button className="App-button" onClick={onProcessConnectButtonClick}>Connect</button>
        </div>
      </header>
      
        
    </div>
    );
}
if(connectionState){
  return (
    <div className="App">
      <header className="App-header">
        <h1> Computer of Things </h1>  
        <h4> Connected to server {serverAddress}</h4>
        <div className="App-button-container">
          <button className="App-button" onClick={onProcessDisconnectButtonClick}>Disconnect</button>
        </div>

      </header>

      
    </div>
    
  );
}
  
}

export default App;
