import React, { useState, useEffect, useRef } from "react";
import './App.css';
import WSConnectComponent from './components/WSConnectComponent';
import StateComponent from './components/StateComponent';
import createModule from "./ComputerOfThings.mjs";

// Webassembly: shared objects?
// https://stackoverflow.com/questions/67655485/webassembly-possible-to-have-shared-objects
// WebAssemby Javascript interaction
// https://dominoc925.blogspot.com/2020/12/how-to-setup-c-webassembly-component-to.html 
// How to grab byte array after srialization in c++
// https://stackoverflow.com/questions/51483768/how-to-grab-byte-array-after-serialization
function dec2bin(dec) {
  return (dec >>> 0).toString(2);
}
/**
* @param {Module}
**/
function wrapProcessWorkPackage(Module) {
  // JS-friendly wrapper around the WASM call
  return function (request) {
    
    const flatInputData = new Uint8Array(request);
    
    console.log ("Request buffer size: " + flatInputData.length);
    
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
    // get the buffer size
    const bufferSize = Module.ccall(
      "getResponseLength",
      "number",
      []
    );
    console.log("Response buffer size: " + bufferSize);  
    var index = 0;
    const result = [];
    const binResult = [];
    for (let i = 0; i < bufferSize; i++) {
      result.push(
        Module.getValue(resultPointer+i, "i8")
      );
      
      binResult.push(dec2bin(Module.getValue(resultPointer+i, "i8")));
    }
    // Release memory
    Module._free(buffer);
    Module._free(resultBuffer);
    return result;
  };
}

function App() {
  //////////////////////////////////////////////////////////////////////////////
  // States and variables
  //////////////////////////////////////////////////////////////////////////////
  const [processWorkPackages, setProcessWorkPackage] = useState();
  const reader = new FileReader();
  
  // App state variables
  const [wasmLoaded, setWasmLoaded] = useState(false);
  const [websocketConnected, setWebSocketConnected] = useState(false);
  const [workpackagesCount, setWorkPackagesCount] = useState(0);
  const [busyProcessing, setBusyProcessing] = useState(false);
  const [websocketConnection, setConnection] = useState(null);

  useEffect(
    // useEffect here is roughly equivalent to putting this in componentDidMount
    // for a class component
    () => {
      createModule().then((Module) => {
        // need to use callback form (() => function) to ensure that `add` is
        // set to the function if you use setX(myModule.cwrap(...)) then React
        // will try to set newX = myModule.cwrap(currentX), which is wrong
        setProcessWorkPackage(() => wrapProcessWorkPackage(Module));
        setWasmLoaded(true);
      });
    },
    []
  );

  function connectHandler(url) {
    /*
    When the user clicks Connect, we create a new WebSocket connection using the specified URL.
    An event listener is added to the WebSocket connection, which listens for incoming messages.
    When a message is received, it is simply passed as raw bytes to the Wasm module for processing.
    The Wasm module will return a response, again as raw bytes, which is then sent back on the WebSocket connection.
    */

    // Create a WebSocket connection
    if (!url.startsWith("ws://")) {
      url = "ws://" + url;
    }
    var websocket = new WebSocket(url);
    websocket.binaryType = 'arraybuffer';

    // Add event listener for when a message is received on the websocket connection
    websocket.onmessage = function (evt) {

      var request = new Uint8Array(evt.data);

      setBusyProcessing(true);
      console.log("Request workpackage received - processing. . .");
      var response = processWorkPackages(request);
      setBusyProcessing(false);

      console.log("Sending response workpackage to server. . .");
      websocket.send(response);

      // update the workpackage count
      setWorkPackagesCount(prevCount => prevCount + 1);
    };

    // Add event listener for when websocket connection is opened
    websocket.onopen = () => {
      console.log("WebSocket connection established.");
      setWebSocketConnected(true);
    }

    // Add event listener for when websocket connection is closed
    websocket.onclose = () => {
      console.log("WebSocket disconnected.");
      setWebSocketConnected(false);
    }

    setConnection(websocket);
  }

  function disconnectHandler() {
    /*
    When a user clicks Disconnect, we simply want to close the WebSocket connection.
    Any work packages that are still being processed should be safely dropped.
    */
    websocketConnection.close();
  }

  return (
    <div className="App">
      <header className="App-header">
        <h1>Computer of Things</h1>
      <WSConnectComponent connected={websocketConnected} connectHandler={connectHandler} disconnectHandler={disconnectHandler} />
      <StateComponent wasmLoaded={wasmLoaded} processedCount={workpackagesCount} busy={busyProcessing} />
      </header>
    </div>
    ); 
}

export default App;
