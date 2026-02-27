# Consistent Hashing

## What is it?
A hashing technique where adding/removing a server only requires remapping **K/N keys** (K = total keys, N = servers), instead of remapping nearly all keys like traditional modular hashing.

## How it Works
1. Arrange hash space as a **ring** (0 to 2^32 - 1)
2. Hash each server to a position on the ring
3. Hash each key to a position on the ring
4. Each key is assigned to the **first server clockwise** from its position
5. When a server is added/removed, only keys between the new/removed server and its predecessor are affected

## Visual
```
        Server A
          |
    K1 ---+--- K2
   /              \
  S_D              S_B
   \              /
    K4 ---+--- K3
          |
        Server C
```

## Key Points
- **Virtual nodes**: Each physical server gets multiple positions on the ring to ensure even distribution
- Without virtual nodes, distribution can be very uneven
- Used by: Cassandra, DynamoDB, Memcached, Akamai CDN
- Time complexity: O(log N) with sorted ring + binary search

## Problem with Simple Hashing
```
server = hash(key) % N
```
If N changes (add/remove server), almost ALL keys get remapped → **cache storm**.

## When to Use
- Distributed caching (Memcached, Redis cluster)
- Database sharding
- CDN request routing
- Any distributed system where nodes join/leave frequently

## Trade-offs
| Pros | Cons |
|------|------|
| Minimal key remapping on node changes | More complex than modular hashing |
| Scales well | Virtual nodes add memory overhead |
| Handles node failures gracefully | Hotspot possible without virtual nodes |

## Interview Tips
- Draw the ring diagram — visual explanation is key
- Mention **virtual nodes** to handle uneven distribution
- Compare with modular hashing: "With mod, adding 1 server remaps almost everything"

## Best Articles
- [Consistent Hashing Explained](https://www.toptal.com/big-data/consistent-hashing)
- [System Design Primer - Consistent Hashing](https://github.com/donnemartin/system-design-primer)
- [Dynamo Paper (Amazon)](https://www.allthingsdistributed.com/files/amazon-dynamo-sosp2007.pdf)
