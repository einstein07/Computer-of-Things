# Simple example taken from https://websockets.readthedocs.io/en/stable/index.html

import asyncio
import websockets

async def echo(websocket):
    async for message in websocket:
        print("Received the following message from client: {}".format(message))
        await websocket.send(message)

async def main():
    async with websockets.serve(echo, "localhost", 8765):
        await asyncio.Future() # run forever

asyncio.run(main())
