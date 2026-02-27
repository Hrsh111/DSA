# Design Distributed Cache

**Difficulty**: Hard | **Time Target**: 40-45 min

## 1. Requirements
Functional: get(key), put(key, value), delete(key) across a cluster of cache nodes. Non-Functional: <1ms latency, high availability, handle node failures.

## 2. Design Overview
Consistent hashing to distribute keys. Replication: each key on N nodes for fault tolerance. Client-side library handles: hash key → find node → send request. Eviction: LRU per node. Failure: if node dies, consistent hashing remaps only affected keys. Health checks + gossip protocol for membership. Essentially: design Redis Cluster.

## Best Articles
- [Design Distributed Cache](https://blog.bytebytego.com/p/design-a-distributed-cache)
