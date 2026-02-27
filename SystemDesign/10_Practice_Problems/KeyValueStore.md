# Design Key-Value Store

**Difficulty**: Medium | **Time Target**: 30-35 min

## 1. Requirements

### Functional Requirements
- put(key, value) — store a key-value pair
- get(key) — retrieve value by key
- delete(key) — remove a key-value pair
- Support large datasets (can't fit in single machine)

### Non-Functional Requirements
- Low latency reads and writes (<10ms)
- High availability (AP system by default, configurable)
- Scalable to petabytes
- Tunable consistency (strong or eventual)

### Back-of-the-Envelope Estimation
- 10M DAU, 100 operations/user/day → 1B operations/day → ~12K QPS
- Key: 256 bytes, Value: 10 KB → 10 KB per record
- 1B records × 10 KB = 10 TB storage

## 2. High-Level Design

### Architecture (Dynamo-style)
```
Client → Coordinator Node → [Node A, Node B, Node C] (consistent hashing ring)
```

### Data Model
```
Each node stores:
  key → { value, timestamp, tombstone_flag }
  
  SSTable (Sorted String Table) on disk
  MemTable (in-memory balanced tree) for recent writes
```

## 3. Deep Dive
- **Consistent Hashing**: Distribute keys across nodes. Virtual nodes for balance.
- **Replication**: Each key stored on N nodes (N=3 typical). Walk clockwise on ring.
- **Quorum**: R + W > N for strong consistency. R=W=1 for fast but eventual.
- **Write Path**: Write to MemTable → WAL (Write-Ahead Log) → when MemTable full, flush to SSTable
- **Read Path**: Check MemTable → Bloom Filter → SSTables (newest first)
- **Compaction**: Merge SSTables periodically to reduce read amplification
- **Conflict Resolution**: Vector clocks for versioning, last-write-wins or app-level merge
- **Gossip Protocol**: Nodes share membership/health info via periodic gossip

## 4. Scaling & Trade-offs
- AP by default (like DynamoDB), CP if quorum configured strictly
- Bloom filters reduce unnecessary disk reads
- Anti-entropy: Merkle trees to detect inconsistencies between replicas
- Hinted handoff: if target node is down, another node holds the write temporarily

## 5. Key Takeaways
- LSM Tree (Log-Structured Merge Tree) for write-optimized storage
- Consistent hashing + virtual nodes for distribution
- Tunable consistency via quorum (R, W, N)
- This is essentially how DynamoDB/Cassandra work internally
