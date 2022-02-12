# System Monitor Client Library
This C++ library can be used by client node to communicate with the central monitor server node. It allows the client to send a warning/error/fatal message to the central monitor server.

## How to use
This library provides a simple interface to use methods to send a message to the central monitor server node. The interface class structure can be found in the header file `system_monitor_client_lib.h`.
1. In client's main script, instantiate a `SystemMonitorClientInterface` object by providing the ROS node handle and the client ID. For example,
```
SystemMonitorClientInterface client1(nh, 1);
```
2. To send a fatal message, use, e.g.,
```
client1.reportFatalStatus("Loss heartbeat");
```
- or to send a error message, use, e.g., 
```
client1.reportErrorStatus("No camera found");
```
- or to send a error message, use, e.g., 
```
client1.reportWarningStatus("High temperature detected");
```