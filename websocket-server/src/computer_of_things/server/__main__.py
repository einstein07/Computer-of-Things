import asyncio
import websockets
from .utils import createMatrixMultiplyRequest
from websockets.connection import Connection

async def connection_handler(websocket_connection: Connection):
    """
    Entry point handler that takes care of connections from clients
    """
    await asyncio.gather(
        client_response_handler(websocket_connection),
        work_package_producer(websocket_connection)
    )

async def client_response_handler(websocket):
        # Iteration terminates when the client disconnects.
        async for message in websocket:
            # each message may be a str or bytes
            process_response(message)

def process_response(message):
    print("Received response from client: {}".format(message))

async def work_package_producer(websocket):
    while True:
        # let's send a new workpackage every 3 seconds
        await asyncio.sleep(3)
        message = get_next_work_package()
        await websocket.send(message)

def get_next_work_package():
    """
    Simple method to simulate the server getting new workpackages
    """
    return createMatrixMultiplyRequest(2, 2)



async def main():
    async with websockets.serve(connection_handler, "localhost", 8765):
        await asyncio.Future() # run forever

asyncio.run(main())
