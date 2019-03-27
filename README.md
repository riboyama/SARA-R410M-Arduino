# SARA-R410M-Arduino

Arduino library for using with the uBlox nbIOT SARA R410M module.

## Usage

An example can be found in the examples folder.


Method|Description
------|------
**getDefaultBaudRate ()**|Returns the correct baudrate for the serial port that connects to the device.
**setDiag (Stream& stream)**|Sets the optional "Diagnostics and Debug" stream.
**init(Stream& stream, int8_t onoffPin)**|    // Initializes the modem instance. Sets the modem stream and the on-off power pins.
**isAlive()**|Returns true if the modem replies to "AT" commands without timing out.
**connect(const char\* apn, const char\* cdp, const char\* forceOperator = 0, uint8_t band = 8)**|Turns on and initializes the modem, then connects to the network and activates the data connection. Returns true when successful.
**disconnect()**|Disconnects the modem from the network. Returns true when successful.
**isConnected()**|Returns true if the modem is connected to the network and has an activated data connection.
**sendMessage(String str)**|Sends the given String. Returns true when the message is successfully queued for transmission on the modem.
**createSocket(uint16_t localPort = 0)**|Create a UDP socket for the specified local port, returns the socket handle.
**closeSocket(uint8_t socket)**|Close a UDP socket by handle, returns true if successful.
**socketSend(uint8_t socket, const char\* remoteIP, const uint16_t remotePort,  const uint8_t\* buffer, size_t size)**|Send a UDP payload buffer to a specified remote IP and port, through a specific socket.
**socketSend(uint8_t socket, const char\* remoteIP, const uint16_t remotePort, const char\* str)**|Send a UDP string to a specified remote IP and port, through a specific socket.
**socketReceiveHex(char\* buffer, size_t length, SaraN2UDPPacketMetadata\* p = NULL)**|Receive pending socket data as hex data in a passed buffer. Optionally pass a helper object to receive metadata about the origin of the socket data.
**socketReceiveBytes(uint8_t\* buffer, size_t length, SaraN2UDPPacketMetadata\* p = NULL)**|Receive pending socket data as binary data in a passed buffer. Optionally pass a helper object to receive metadata about the origin of the socket data.
**getPendingUDPBytes()**| Return the number of pending bytes, gets updated by calling socketReceiveXXX.
**hasPendingUDPBytes()**| Helper function returning if getPendingUDPBytes() > 0.
**waitForUDPResponse(uint32_t timeoutMS = DEFAULT_UDP_TIMOUT_MS)**|Calls isAlive() until the passed timeout, or until a UDP packet has been received on any socket.
