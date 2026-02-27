# Database Sharding

## What is it?
Splitting a large database into smaller pieces (**shards**) across multiple servers. Each shard holds a subset of the data.

## Sharding Strategies

### 1. Range-Based Sharding
- Shard by value ranges (e.g., users A-M on shard 1, N-Z on shard 2)
- Simple but can cause **hotspots** (uneven distribution)

### 2. Hash-Based Sharding
- Hash the shard key → assign to shard (hash(key) % N)
- Even distribution but range queries become expensive
- Use **consistent hashing** to handle adding/removing shards

### 3. Directory-Based Sharding
- Lookup table maps each key to its shard
- Most flexible but lookup table is a single point of failure

## Key Points
- **Shard key** selection is critical — bad key = hotspots
- Good shard key: high cardinality, even distribution, used in most queries
- Cross-shard queries (JOINs across shards) are very expensive
- Re-sharding is painful — plan ahead
- Sharding adds complexity: distributed transactions, cross-shard queries, rebalancing

## When to Use
- Database too large for a single server
- Write throughput exceeds single server capacity
- Need to distribute data geographically

## Trade-offs
| Pros | Cons |
|------|------|
| Horizontal scalability | Complex queries (cross-shard JOINs) |
| Better write performance | Re-sharding is hard |
| Data locality | Distributed transactions complexity |
| Fault isolation per shard | Operational overhead |

## Interview Tips
- Always discuss shard key selection and justify it
- Mention consistent hashing for hash-based sharding
- Acknowledge the downsides: "Sharding adds complexity, so we'd only do it when a single database can't handle the load"

## Best Articles
- [Database Sharding Explained](https://www.digitalocean.com/community/tutorials/understanding-database-sharding)
- [ByteByteGo: Database Sharding](https://blog.bytebytego.com/p/database-sharding)
- [Vitess: How YouTube Shards MySQL](https://vitess.io/)
