
## Intro 
- OS is a piece of software that abstract and arbitrate the use of computer system 
- Abstract: to simplify what the hardware looks like 
- Arbitration: to control the hardware use
*Example:*
- distributing memory between multiple processes: arbitration. OS system manages memory and determine how multiple processes will share 
- supporting different types of speakers: abstractions, plug one set in, if not compatible then another.
- interchangeable access of hard disk or SSD: abstractions, the use of storage abstraction that the OS can support  --> they can underneath feel the different types of devices and hide that from the application 
## Role of OS
1. Directs operational resources : control uses of CPU, memory, peripheral devices 
2. enforce working policicies: resource access, limit access 
3. Mitigate difficulties of complex tasks: simplify the view of the underlying hardware that's observed by the applications that are runnnig on that paticular platform. Applications interact via **system call** with the OS and it will take care of managing those task for them

## OS definition 

An OS is a layer of systems software that:
1. directly has privileged access to the **underlying hardware**
2. hides the hardware complexity
3. manages hardware on behalf of one or more applications according to some predefined policies
4. ensures that applications are isolated and protected from one another

OS components:
1. File system : hiding hardware complexities, exporting a more simpler, more intuitive abstraction (unlike block or disk usage)
2. Device driver : making decision on the usage of the hardware devices
3. Scheduler: distributing access to the processing element, the CPU 

Not  OS components:
1. Cache memory: hardware
2. web browser 
3. file editor 


## OS Systems Examples 
1. Windows
2. Unix-based: MAC OS, Linux (ubuntu,centos)

Embedded: 
1. Android: embedded Linux
2. iOS : apple 
3. Symbian 
