- Operating systems support devices via **device drivers**.
![[Pasted image 20241104114610.png]]
- Device drivers are device-specific software components. The operating systems needs to include a device driver for every type of device that is included in the system
- Device drivers are responsible for all aspects of device _access_, _management_ and _control_. This includes logic that determines how requests are passed from higher level components to the device and how those components respond to errors or notifications from the device. Generally, device drivers govern any device-specific configuration/operation details.
- The manufacturer of a device is responsible for making drivers available for all the operating systems where their device will be used. For example, you may often have to download printer drivers from HP when you buy a new HP printer.
- Operating systems standardize their interfaces to device drivers. Typically this is done by providing some device driver framework, so that device manufacturers can develop their drivers within that framework. This helps to decouple the operating system from a fixed set of specific devices, which makes the operating system independent of the devices it supports while also allowing it to support many different devices.

![[Pasted image 20241104115111.png]]