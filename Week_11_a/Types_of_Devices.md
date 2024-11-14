## block devices 
like disks - operate at the granularity of blocks of data that are delivered to and from the device via the CPU interconnect. A key property of block devices is that individual blocks can be accessed. If you have ten blocks of data on a disk, you can directly request the ninth one.
## Characters 
like keyboards - work with a serial sequence of characters and support a get/put character interface.
## Network devices

are somewhere in between. They deliver more than a character at a time, but their granularity is not a fixed block size. They are more like a stream of data chunks of potentially different sizes.

____________
The interface a devices exposes to the operating system is standardized based on the type of device
- Internally, the operating system maintains some representation for each of the devices available on the platform. This is typically done using a file abstraction where each file represents a device. This allows the operating system to interact with devices via the same interface is already maintains for interacting with files. That being said, these operations will be handled in some device specific manner.


On UNIX-like systems, all devices appear as files under the `/dev` directory. They are treated by the filesystems **tmpfs** and **devfs**.


Note:
Run `ls -la /dev`

