# CAP Theorem

## What is it?
In a distributed system, you can only guarantee **2 out of 3** properties:

- **C**onsistency: Every read receives the most recent write
- **A**vailability: Every request receives a response (even if stale)
- **P**artition Tolerance: System works despite network failures between nodes

Since network partitions are **inevitable**, the real choice is: **CP vs AP**.

## Key Points
- **CP (Consistency + Partition Tolerance)**: System may refuse requests during partitions to stay consistent. Examples: MongoDB, HBase, Redis
- **AP (Availability + Partition Tolerance)**: System always responds but may return stale data. Examples: Cassandra, DynamoDB, CouchDB
- **CA (Consistency + Availability)**: Only possible in single-node systems (no partition). Examples: Traditional RDBMS (PostgreSQL, MySQL on single node)
- In practice, it's a **spectrum**, not a binary choice
- PACELC extends CAP: "if Partition, choose A or C; Else, choose Latency or Consistency"

## Visual
```
        Consistency
           /\
          /  \
     CP  /    \  CA (only single node)
        /      \
       /________\
  Partition     Availability
  Tolerance
       AP
```

## When to Use
- **CP**: Banking, inventory systems — correctness > availability
- **AP**: Social media feeds, analytics — availability > perfect consistency

## Trade-offs
| CP Systems | AP Systems |
|-----------|-----------|
| Always correct data | Always available |
| May reject requests during partition | May serve stale data |
| Higher latency | Lower latency |
| Banks, payments | Social feeds, caching |

## Interview Tips
- Don't say "we need all three" — partitions always happen
- Frame it as: "For this system, do we prefer consistency or availability?"
- Mention **eventual consistency** as a middle ground for AP systems

## Best Articles
- [System Design Primer - CAP](https://github.com/donnemartin/system-design-primer#cap-theorem)
- [CAP Theorem Explained (Visual)](https://www.ibm.com/topics/cap-theorem)
- [You Can't Sacrifice Partition Tolerance](https://codahale.com/you-cant-sacrifice-partition-tolerance/)
