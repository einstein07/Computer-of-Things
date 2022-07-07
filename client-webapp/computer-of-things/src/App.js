import logo from './logo.svg';
import './App.css';
import Module from "./ComputerOfThings.mjs";
// Webassembly: shared objects?
// https://stackoverflow.com/questions/67655485/webassembly-possible-to-have-shared-objects
/**
* @param {Module}
* @return {Array} - an array of fft values
**/
function wrapProcessWorkPackages(Module) {
  // JS-friendly wrapper around the WASM call
  return function (inputData) {
    const length = inputData.length;

    // set up input arrays with the input data -- remove holes if any
    const flatInputData = new Float32Array(inputData);

    const buffer = Module._malloc(
      flatInputData.length * flatInputData.BYTES_PER_ELEMENT
    );
    Module.HEAPF32.set(flatInputData, buffer >> 2);

    // allocate memory for the result array
    const resultBuffer = Module._malloc(
      flatInputData.length * flatInputData.BYTES_PER_ELEMENT
    );

    // make the call
    const resultPointer = Module.ccall(
      "process_work_packages",
      "number",
      ["number", "number"],
      [buffer, resultBuffer]
    );

    // get the data from the returned pointer into an flat array
    const result = [];
    for (let i = 0; i < length; i++) {
      result.push(
        Module.HEAPF32[resultPointer / Float32Array.BYTES_PER_ELEMENT + i]
      );
    }
    // Release memory
    Module._free(buffer);
    Module._free(resultBuffer);
    return result;
  };
}


function App() {

  return (
    <div className="App">
      <header className="App-header">
        <h1> Computer of Things </h1>  
      </header>
      <div className="App-content">
        <text>Connected</text>
        
      <textarea ></textarea>
          <div className="App-button-container">
            <button className="App-button" >Connect</button>
            </div>

        </div>
    </div>
    
  );
}

export default App;
