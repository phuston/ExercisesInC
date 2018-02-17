## Homework 4

### C Exercises

Modify the link below so it points to the `ex03` directory in your
student repository.

[Here is a link to the ex03 directory in my repository](https://github.com/phuston/ExercisesInC/tree/master/exercises/ex03)

### Think OS Chapter 4 reading questions

**Files and file systems**

1) What abstractions do file systems provide?  Give an example of something that is logically 
true about files systems but not true of their implementations.

    - File systems provide the abstraction that each file is just as stream of bytes, when in reality files are stored in blocks built on top of underlying storage devices. Something that is logically true about file systems, but isn't true about the implementation is what happens when writing to a file. Data is written first to the buffer, which is stored in memory, and only later is it actually persisted in the blocks.  

2) What information do you imagine is stored in an `OpenFileTableEntry`?

    - I'd imagine that it contains information about the open file that the OS needs - things like file name, inode, etc.

3) What are some of the ways operating systems deal with the relatively slow performance of persistent storage?

    - Block transfers - the OS tries to read large blocks each time the disk is accessed
    - Prefetching - the OS starts loading additional blocks that aren't explicitly requested if there's a high chance it'll be requested soon anyway
    - Buffering - the OS stores written data in memory temporarily and only writes it to the disk later. This way, if the data needs to be modified, it can be modified quickly in memory instead of having to access persistent storage, which is much slower.
    - Caching - if a process has used a block, it's probably going to use it again soon. The OS can keep a copy of this block in memory and handle future requests much faster.

4) Suppose your program writes a file and prints a message indicating that it is done writing.  
Then a power cut crashes your computer.  After you restore power and reboot the computer, you find that the 
file you wrote is not there.  What happened?
    - The OS probably wrote the data to an in-between in-memory buffer, waiting to actually write the data to storage. This memory is volatile, so the data was lost when the computer crashed.

5) Can you think of one advantage of a File Allocation Table over a UNIX inode?  Or an advantage of a inode over a FAT?
    - One advantage of FAT over the UNIX inode is its simplicity. Embedded in the concept of the UNIX inode is the idea of indirection, which is inherently more complex. Additionally, FAT only requires that you allocate just as much memory as you actually need for a file, and not much more.
    - Because the inode indirectly represents the disk, it seems like searching for a point in a file would be much faster - seeking within a file seems like it would also be a lot faster.

6) What is overhead?  What is fragmentation?
    - Overhead refers to the data structures needed to describe the system that allocates the space - it should be low, because you want as much space for the actual data as possible. Fragmentation occurs when some blocks in the file system are left unused (or only partially used), leading to inefficient use of disk space.


7) Why is the "everything is a file" principle a good idea?  Why might it be a bad idea?
    - The file abstraction means that programmers only have to learn and use one API, and can swap out different 'files' that represent different data sources. I could imagine this abstraction could in theory become limiting if there becomes a compelling way to represent streams of data differently. 

If you would like to learn more about file systems, a good next step is to learn about journaling file systems.  
Start with [this Wikipedia article](https://en.wikipedia.org/wiki/Journaling_file_system), then 
[Anatomy of Linux Journaling File Systems](http://www.ibm.com/developerworks/library/l-journaling-filesystems/index.html).  
Also consider reading [this USENIX paper](https://www.usenix.org/legacy/event/usenix05/tech/general/full_papers/prabhakaran/prabhakaran.pdf).



