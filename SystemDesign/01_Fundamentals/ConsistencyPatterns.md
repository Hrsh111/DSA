# Consistency Patterns

## What is it?
How and when updates become visible to all nodes/readers in a distributed system.

### 1. Strong Consistency
- Read always returns the latest write
- Implemented via: synchronous replication, consensus protocols (Raft, Paxos)
- Example: Google Spanner, ZooKeeper

### 2. Eventual Consistency
- Reads may return stale data, but will eventually catch up
- Implemented via: async replication, conflict resolution
- Example: DynamoDB, Cassandra, DNS

### 3. Causal Consistency
- Operations that are causally related are seen in order; concurrent ops can be in any order
- Example: Social media comments (reply always after original post)

### 4. Read-Your-Writes Consistency
- A user always sees their own writes immediately
- Others may see stale data
- Example: After posting a tweet, YOU see it right away

## Key Points
- Stronger consistency = higher latency, lower availability
- Weaker consistency = lower latency, higher availability
- Most apps use **eventual consistency** with **read-your-writes** guarantee
- Quorum reads/writes: R + W > N guarantees strong consistency

## When to Use
- **Strong**: Financial transactions, inventory counts
- **Eventual**: Social feeds, analytics, caching
- **Read-your-writes**: User-facing apps where user expects to see their own changes

## Trade-offs
| Pattern | Latency | Availability | Correctness |
|---------|---------|-------------|------------|
| Strong | High | Low | Perfect |
| Eventual | Low | High | Stale possible |
| Causal | Medium | Medium | Ordered |

## Interview Tips
- For most systems, say "eventual consistency is fine here, but we need read-your-writes for the posting user"
- Know quorum formula: R + W > N

## Best Articles
- [System Design Primer - Consistency](https://github.com/donnemartin/system-design-primer#consistency-patterns)
- [Designing Data-Intensive Applications Ch.5](https://dataintensive.net/)
- [Jepsen: Consistency Models](https://jepsen.io/consistency)
