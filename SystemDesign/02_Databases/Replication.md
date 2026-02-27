# Database Replication

## What is it?
Copying data from one database server (leader/primary) to others (followers/replicas) so multiple servers have the same data.

## Replication Types

### 1. Leader-Follower (Master-Slave)
- One leader handles writes, followers handle reads
- Async or sync replication to followers
- Simple, most common pattern
- If leader dies → promote a follower

### 2. Multi-Leader (Master-Master)
- Multiple nodes accept writes
- Need conflict resolution (last-write-wins, merge, custom)
- Used for multi-datacenter setups

### 3. Leaderless (Dynamo-style)
- Any node can accept reads and writes
- Uses quorum: read from R nodes, write to W nodes (R + W > N for consistency)
- Used by: Cassandra, DynamoDB

## Key Points
- **Sync replication**: Follower confirms write before leader acknowledges client. Strong consistency, higher latency
- **Async replication**: Leader acknowledges immediately, replicates later. Fast but may lose data on leader crash
- **Semi-sync**: One follower is sync, rest are async (good balance)
- Replication lag causes stale reads on followers

## When to Use
- **Leader-Follower**: Read-heavy workloads (cache reads across replicas)
- **Multi-Leader**: Multi-region apps, offline-capable apps
- **Leaderless**: High availability needs, write-heavy workloads

## Trade-offs
| Sync Replication | Async Replication |
|-----------------|------------------|
| Strong consistency | Eventual consistency |
| Higher write latency | Lower write latency |
| No data loss | Possible data loss on crash |

## Interview Tips
- Default answer: "Leader-follower with async replication for reads, promote follower on failure"
- For global apps: "Multi-leader across regions to reduce latency"
- Know the quorum formula: R + W > N

## Best Articles
- [Designing Data-Intensive Applications Ch.5](https://dataintensive.net/)
- [System Design Primer - Replication](https://github.com/donnemartin/system-design-primer#replication)
- [PostgreSQL Replication Guide](https://www.postgresql.org/docs/current/high-availability.html)
