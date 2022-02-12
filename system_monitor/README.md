# System Monitor
This package contains a system that can monitor the status of multiple nodes and report issues on specific ROS topics. The client library source files are isolated from the main package and are located in `system_monitor_client_lib`. The sample client nodes link and call the compiled library to establish communication with the central monitor server.

The package contains one central monitor server node that report the statuses of all client nodes in three ROS topics :
- `/sysmon/fatal`
- `/sysmon/error`
- `/sysmon/warning`

The sample client nodes artificially send fatal/warning/error message at various frequencies.

The ROS topics use a custom ROS message `system_monitor/SystemStatus` (the msg structure can be found in the *msg* directory), which provides timestamp and the string message that identifies the client and the message it sends.

## Environment
This package is built and compiled under Ubuntu 18.04 and ROS Melodic.

## Instructions to run test scripts
1. `mkdir -p catkin_ws/src && cd catkin_ws/src`
2. Git clone the repo
3. `cd ..` and `catkin_make`
4. `source devel/setup.bash` and `roslaunch system_monitor system_monitor_test.launch`
    - this will launch the `central_monitor_server_node` and the three sample client nodes `client1_node`, `client2_node`, `client3_node`.
5. In other terminals, source and monitor the three ROS topics. In the following, some sample ROS messages from the topics are shown.
- In `rostopic echo /sysmon/fatal`, one should see
```
header: 
  seq: 2274
  stamp: 
    secs: 1644705935
    nsecs: 836592068
  frame_id: ''
message: "Client 1: lost heartbeat."
```

- In `rostopic echo /sysmon/warning`, one should see
```
header: 
  seq: 2489
  stamp: 
    secs: 1644705924
    nsecs: 846636293
  frame_id: ''
message: "Client 3: Low temperature detected."
```
- In `rostopic echo /sysmon/error`, one should see
```
header: 
  seq: 2491
  stamp: 
    secs: 1644705925
    nsecs: 346619342
  frame_id: ''
message: "Client 3: No camera detected."

```