#!/bin/bash
# Invoke the Flatbuffer compiler..

# compile C++ header files
flatc --cpp -o generated/cpp/ common.fbs request.fbs response.fbs workpackage.fbs

# compile Python files
flatc --python -o generated/python/ common.fbs request.fbs response.fbs workpackage.fbs