import React from "react"

// StateComponent:
// A simple component that just displayed the state of the application
export default class StateComponent extends React.Component {

    constructor(props) {
        super(props);
    }

    render() {
        return (
            <div>
                <p>{this.props.wasmLoaded ? "WASM Module Loaded" : "WASM Module not available"}</p>
                <p>{"Workpackages processed: " + this.props.processedCount}</p>
                <p hidden={!this.props.busy}>{"Busy processing..."}</p>
            </div>);
    }
}