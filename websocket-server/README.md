# Computer-of-Things : WebSocket server

A simple WebSocket server written in Python, used during development for the Computer-of-Things.

The Websocket server is responsible for:
- listening, accepting and managing websocket connections from clients
- keeping track of all clients that have *active* connections
- accepting work-packages from external drivers, in the form of Python objects generated from the work-package Flatbuffers schema
- distributing work-packages to connected clients

The Websocket server is NOT responsibly for:
- serving the client web-app

# Before you get started

The Computer-of-Things websocket server uses the [Poetry framework](https://python-poetry.org/) to ease development and building of the project and its dependencies. In order to get started with the websocket server, first install Poetry by [following installation steps](https://python-poetry.org/docs/#installation).

# Quickstart

To quickly test the websocket server environment, navigate into the `websocket-server` directory and install the Python package:

```shell
$ cd {project-root}/websocket-server
$ poetry install -v
```

Poetry reads the `pyproject.toml` file, and installs the Computer-of_Things websocket server, along with all it's dependencies, into an isolated Python environment (see Python virtual environments). The `-v` outputs more verbose information.

With the package installed, start up the websocket server by running:

```shell
poetry run python3 -m cothings.websocket.server
```

The websocket server is now running, and listening on port 8765 for websocket connections from clients. 

To simulate a client, open up a new terminal, navigate to the `websocket-server` directory, and run:

```shell
poetry run python3 -m websockets ws://localhost:8765/
```

Type in a few messages, and see what gets returned!

# Design

Work in progress


