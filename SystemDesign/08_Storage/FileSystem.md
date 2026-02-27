# File System Design

## What is it?
Distributed file systems store files across multiple machines, providing a single namespace. Used for large-scale data processing.

## Key Systems
| System | Use Case |
|--------|---------|
| HDFS | Big data processing (Hadoop ecosystem) |
| GFS (Google File System) | Google's internal storage |
| NFS | Network-attached file sharing |
| EFS (AWS) | Managed NFS for cloud |

## HDFS Architecture
```
Client → NameNode (metadata: which blocks on which DataNodes)
       → DataNode 1 (block A, block B)
       → DataNode 2 (block A copy, block C)
       → DataNode 3 (block B copy, block C copy)
```
- Files split into large blocks (128MB default)
- Each block replicated 3x across DataNodes
- NameNode stores metadata (single point of failure → HA with standby)

## Key Points
- Optimized for large files, sequential reads (not small random access)
- Write-once, read-many pattern
- Block replication provides fault tolerance
- NameNode is the bottleneck — keep metadata in memory

## Interview Tips
- For data processing: "HDFS for storing large datasets, processed by MapReduce/Spark"
- For user files: "S3 for user uploads (not a file system, but simpler and more scalable)"
- Know the difference: file storage (hierarchy) vs object storage (flat key-value)

## Best Articles
- [HDFS Architecture Guide](https://hadoop.apache.org/docs/current/hadoop-project-dist/hadoop-hdfs/HdfsDesign.html)
- [GFS Paper](https://static.googleusercontent.com/media/research.google.com/en//archive/gfs-sosp2003.pdf)
