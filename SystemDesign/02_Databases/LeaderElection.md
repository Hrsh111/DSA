# Leader Election

## What is it?
A process where distributed nodes agree on one node to be the "leader" that coordinates work. If the leader dies, a new one is elected.

## Algorithms

### 1. Bully Algorithm
- Highest-priority (usually highest ID) node wins
- On failure detection, lower nodes trigger election
- Simple but not fault-tolerant to network partitions

### 2. Raft Consensus
- Nodes are in one of three states: Leader, Follower, Candidate
- Term-based voting — candidate requests votes, majority wins
- Used by: etcd, CockroachDB, TiKV
- Understandable alternative to Paxos

### 3. Paxos
- Classic consensus algorithm, mathematically proven correct
- Complex to implement and understand
- Used by: Google Chubby, some internal Google systems

### 4. ZooKeeper (Zab Protocol)
- Purpose-built coordination service
- Ephemeral nodes + watches for leader election
- Used by: Kafka (older versions), HBase, Hadoop

## Key Points
- Leader election is needed when one node must coordinate (DB writes, task assignment)
- Split brain: two nodes think they're leader → data corruption
- **Fencing tokens**: monotonically increasing token to prevent split brain
- Heartbeats detect leader failure (timeout = leader is dead)
- Trade-off: short timeout = fast recovery but false positives; long timeout = slow recovery

## When to Use
- Database primary selection
- Distributed task scheduling (only one scheduler runs)
- Kafka partition leadership
- Any system where exactly one node should perform an action

## Trade-offs
| Approach | Complexity | Consistency | Speed |
|----------|-----------|------------|-------|
| Bully | Low | Weak | Fast |
| Raft | Medium | Strong | Medium |
| Paxos | High | Strong | Medium |
| ZooKeeper | Medium (uses library) | Strong | Fast |

## Interview Tips
- For most designs: "We'd use a coordination service like ZooKeeper or etcd for leader election"
- Mention the split-brain problem and fencing tokens
- Know Raft at a high level — it's the most interview-friendly consensus algorithm

## Best Articles
- [Raft Consensus Visualization](https://raft.github.io/)
- [Raft Paper (Understandable Consensus)](https://raft.github.io/raft.pdf)
- [Designing Data-Intensive Applications Ch.9](https://dataintensive.net/)
