Since the server can support multiple programs, versions, and procedures, it is not enough just to pass procedure arguments from client to server.

## Header
RPCs must also contain information about the service procedure id, version number and request id in the header of the request. This header will be included in the response from the server as well.

In addition to these metadata fields, we clearly need to put the actual data (arguments or results) onto the wire. These datatypes are encoded into a byte stream which depends on the data type.
## Client-Server 

There may be a 1-1 mapping between how the data is represented in memory and how it is represented on the wire, but this may not always be the case. What is important is that the data is encoded in a standard format that can be deserialized by both the client and server.

Finally, the packet of data needs to be preceded by the transport header (TCP/UDP) in order to actually be sent along the wire in accordance with these transmission protocols.

## [](https://www.omscs-notes.com/operating-systems/remote-procedure-calls/#xdr-encoding)