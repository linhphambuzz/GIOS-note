
- When a user process needs to perform an operation that requires a device, the process will make a system call specifying the appropriate operation. With this, the process is requesting the operation from the OS/ from the kernel 
- The operating system will then run the in-kernel stack associated with the specific device, and may perform some preprocessing to prepare the data received by the user process for the device. For example, the kernel may form a TCP/IP packet from an unformatted buffer.
- Then the operating system will invoke the appropriate device driver for the device.
- The device driver will then perform the configuration of the request to the device. For example, a device driver to a network interface card will write a record that configures the device to perform a transmission of the packet sent from the operating system.
- ---------------------
- The device drivers issue commands and send data using the appropriate PIO or DMA operations. The drivers are responsible for ensuring that any commands and data needed by the device are not overwritten or undelivered.
- Finally, once the device is configured, the device will perform the actual request. For example, a NIC will actually transmit the packet onto the network.
-> Any results/events originating on the device will traverse this chain in reverse: from the device to the driver to the kernel and finally into the user process.