# Computer-of-Things 🖥️📱💡🖨️📡

Computer-Of-Things is a project aimed at creating a distributed processing framework, utilizing the portability of [WebAssembly](https://webassembly.org/) (WASM). 

This repository consists of various components that make up Computer-of-Things, with each component living in a respectively named root subdirectory:

- `client-wasm` - The WASM library module, loaded onto client devices. Written in C++ and compiled with [Emscripten](https://emscripten.org/). Makes use of the generated C++ header files from the `schema` directory.
- `client-webapp` - The web-application loaded onto client devices. Provides the platform to instantiate the `client-wasm` module on client devices.
- `websocket-server` - Simple development web-server used to test and illustrate the use of Computer-of-Things. Written in Python. Makes use of generated python files from the `schema` directory.
- `schema` - Flatbuffers schema and build scripts, defining the work-package API used between clients and the server.