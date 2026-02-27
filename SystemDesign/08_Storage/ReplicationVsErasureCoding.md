# Replication vs Erasure Coding

## What is it?
Two strategies for data durability — ensuring data survives hardware failures.

### Replication
- Store N complete copies of data on different machines
- Simple: 3x replication = 3 copies = 200% storage overhead
- Fast reads (any copy can serve), fast recovery
- Used by: HDFS, MongoDB, Cassandra

### Erasure Coding
- Split data into k data chunks + m parity chunks (Reed-Solomon coding)
- Can recover from any m chunk failures
- Example: 6+3 = 6 data + 3 parity, tolerates 3 failures with only 50% overhead
- Slower recovery (need to recompute), more CPU-intensive
- Used by: AWS S3, Azure Blob, HDFS (cold data)

## Comparison
| Feature | Replication (3x) | Erasure Coding (6+3) |
|---------|-----------------|---------------------|
| Storage Overhead | 200% | 50% |
| Read Speed | Fast (any copy) | Slower (may need reconstruction) |
| Write Speed | Fast | Slower (compute parity) |
| Recovery Speed | Fast (copy from replica) | Slower (recompute) |
| Fault Tolerance | 2 failures (with 3 copies) | 3 failures (with 6+3) |

## When to Use
- **Replication**: Hot data, frequently accessed, write-heavy, latency-sensitive
- **Erasure Coding**: Cold data, archival, large datasets where storage cost matters

## Interview Tips
- "Hot data with 3x replication for fast access, cold/archival data with erasure coding to save storage costs"
- You rarely need to go deep on erasure coding for SDE-I, but knowing it exists shows breadth

## Best Articles
- [Erasure Coding Explained](https://blog.min.io/erasure-coding/)
- [HDFS Erasure Coding](https://hadoop.apache.org/docs/current/hadoop-project-dist/hadoop-hdfs/HDFSErasureCoding.html)
