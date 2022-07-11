import asyncio
import websockets
from .utils import createMatrixMultiplyRequest
from websockets.connection import Connection


# Use a global list to keep track of connected clients, and whether they're busy
CONNECTED_CLIENTS = []

async def connection_handler(websocket_connection: Connection):
    """
    Entry point handler that takes care of connections from clients

    """

    CONNECTED_CLIENTS.append(websocket_connection)
    print("request byte array:")
    buff = createMatrixMultiplyRequest(2, 2)
    print(", ".join(hex(b) for b in buff))
    await websocket_connection.send(buff)
    response = await websocket_connection.recv()
    print("Received response from client: ", response)



async def main():
    async with websockets.serve(connection_handler, "localhost", 8765):
        await asyncio.Future() # run forever

asyncio.run(main())
