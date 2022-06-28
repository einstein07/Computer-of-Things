# CoThings - WebSocket server

A simple WebSocket server written in Python, used during development for CoThings.

The Websocket server is responsible for:
- listening, accepting and managing websocket connections from WASM workers (clients)
- keeping track of all WASM workers that have *active* connections
- accepting work-packages from external drivers, in the form of Python objects generated from the work-package Flatbuffers schema
- distributing work-packages to connected WASM workers
- 

The Websocket server is NOT responsibly for:
- serving the worker web application to clients

# Before you get started

The CoThings websocket server uses the [Poetry framework](https://python-poetry.org/) to ease development and building of the project and its dependencies. In order to get started with the websocket server, first install Poetry by [following installation steps](https://python-poetry.org/docs/#installation).

# Quickstart

To quickly test the websocket server environment, navigate into the `websocket-server` directory and install the Python package:

```shell
$ cd {project-root}/websocket-server
$ poetry install -v
```

Poetry reads the `pyproject.toml` file, and installs the CoThings websocket server, along with all it's dependencies, into an isolated Python environment (see Python virtual environments). The `-v` outputs more verbose information.

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



