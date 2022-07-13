import React from "react"

// WSConnectComponent:
// A react component used by the user to enter a URL for the websocket server, and a Connect/Disconnect button.
export default class WSConnectComponent extends React.Component {

    constructor(props) {
        super(props);
        this.handleClick = this.handleClick.bind(this);
    }

    handleClick() {
        // the way we respond to a click depends on whether we're connected or not
        if (this.props.connected) {
            // if we are currently connected, it means the "DISCONNECT" button was shown.
            // so we call the disconnectHandler
            this.props.disconnectHandler();
        } else {
            // else, we were in disconnected state, so the user clicked "CONNECT"
            // we call connectHandler with the URL that the user typed in
            var serverAddress = document.getElementById("serverURLInput").value;
            this.props.connectHandler(serverAddress);
        }
    }

    render() {
        return (
            <div>
                <p>{this.props.connected ? "CONNECTED" : "NOT CONNECTED"}</p>
                <input disabled={this.props.connected} id="serverURLInput"></input>
                <div className="App-button-container">
                    <button className="App-button" onClick={this.handleClick}>{this.props.connected ? "DISCONNECT" : "CONNECT"}</button>
                </div>
            </div>);
    }
}