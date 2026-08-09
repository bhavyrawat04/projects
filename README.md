# TCP Client-Server in C++ (Raw Sockets)

A minimal TCP client and server written in C++ using the POSIX socket API (`sys/socket.h`, `netinet/in.h`), built to understand how networking works at the syscall level — no frameworks, no libraries.

## What it does

- **`server.cpp`** creates a TCP socket, binds it to port `2000`, listens for a connection, accepts one client, and prints every message it receives until the client disconnects.
- **`client.cpp`** connects to `127.0.0.1:2000`, reads lines from stdin, and sends each one to the server. Typing `exit` closes the connection.

This is a one-directional echo pipe right now: the client sends, the server prints. The client does not yet read responses back from the server.

## Build

```bash
g++ -o server server.cpp
g++ -o client client.cpp
```

## Run

In one terminal:
```bash
./server
```

In another terminal:
```bash
./client
```

Type messages in the client terminal — they'll show up in the server terminal. Type `exit` to close the client.

## Known limitations

- Server accepts exactly **one** client connection, then exits when that client disconnects.
- No error handling on socket syscalls (`socket`, `bind`, `listen`, `accept`, `connect`).
- Client never reads a response from the server (one-way communication only).
- No `SO_REUSEADDR`, so restarting the server quickly can fail with "address already in use."

## Why I built this

To understand TCP client-server communication from first principles — socket creation, binding, listening, accepting connections, and `send`/`recv` — before relying on higher-level networking libraries or frameworks.
