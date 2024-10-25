## When should pages be swapped out? 
- Periodically, when the amount of occupied memory reaches a particular threshold, the operating system will run some **page out daemon** to look for pages that can be freed.
- Pages should be swapped when the memory usage in the system exceeds some threshold and the CPU usage is low enough so that this daemon doesn't cause too much interruption of applications.

![[Pasted image 20241020230344.png]]

## Which page should be swapped out? 
1. least recently used 
- Obviously, the pages that won't be used in the future! Unfortunately, we don't know this directly. However, we can use historic information to help us make informed predictions.
- A common algorithm to determine if a page should be swapped out is too look at how recently a page has been used, and use that to inform a prediction about the page's future use. The intuition here is that a page that has been more recently used is more likely to be needed in the immediate future whereas a page that hasn't been accessed in a long time is less likely to be needed.
- This policy is known as the **Least-Recently Used** (LRU) policy. This policy uses the **access bit** that is available on modern hardware to keep track of whether or not the page has been referenced.
2. Other candidates for pages that can be freed from physical memory are pages that don't need to be written out to disk.
- Writing pages out to secondary storage takes time, and we would like to avoid this overhead. To assist in making this decision, OS can keep track of the **dirty bit** maintained by the MMU hardware which keeps track of whether or not a given page has been modified.
### Caution 

In addition, there may be certain pages that are non-swappable. Making sure that these pages are not considered by the currently executing swapping algorithm is important.


______________________________________________________
## Linux 
- In Linux, a number of parameters are available to help configure the swapping nature of the system. This includes the threshold page count that determines when pages start getting swapped out.
- In addition, we can configure how many pages should be replaced during a given period of time. Linux also categorizes the pages into different types, such as claimable and swappable, which helps inform the swapping algorithm as to which pages can be replaced.
- Finally, the default replacement algorithm in Linux is a variation of the LRU policy, which gives a **second chance**. It performs two scans before determining which pages are the ones that should be swapped out.

