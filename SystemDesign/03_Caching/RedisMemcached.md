# Redis and Memcached

## What is it?
In-memory data stores used as caches. Both store key-value pairs in RAM for ultra-fast access.

## Comparison
| Feature | Redis | Memcached |
|---------|-------|-----------|
| Data Structures | Strings, Lists, Sets, Hashes, Sorted Sets, Streams | Strings only |
| Persistence | Yes (RDB snapshots, AOF) | No (pure cache) |
| Replication | Yes (leader-follower) | No |
| Clustering | Yes (Redis Cluster) | Client-side sharding |
| Pub/Sub | Yes | No |
| Lua Scripting | Yes | No |
| Multi-threaded | Single-threaded (mostly) | Multi-threaded |
| Memory Efficiency | Less (overhead for data structures) | More (simple slab allocation) |

## Key Points
- **Redis** is the default choice in 2024 — more features, persistence, data structures
- **Memcached** only when you need simple string caching with multi-threaded performance
- Redis typical latency: <1ms for most operations
- Redis use cases beyond caching: rate limiting, leaderboards, pub/sub, session storage, queues
- Redis persistence: RDB (point-in-time snapshots) + AOF (append-only log)

## Common Redis Patterns
```
# Caching
SET user:123 "{name: 'Harsh', ...}" EX 300    # 5 min TTL

# Rate Limiting
INCR rate:user:123
EXPIRE rate:user:123 60

# Leaderboard
ZADD leaderboard 1500 "player1"
ZREVRANGE leaderboard 0 9    # Top 10

# Distributed Lock
SET lock:resource "owner" NX EX 30
```

## When to Use
- **Redis**: Almost always — caching, sessions, rate limiting, real-time features
- **Memcached**: Simple caching layer when multi-threaded performance is critical

## Interview Tips
- Default to Redis for any caching discussion
- Mention specific data structures: "We'd use Redis Sorted Sets for the leaderboard"
- For distributed rate limiting: "Redis INCR with Lua script for atomicity"

## Best Articles
- [Redis Official Documentation](https://redis.io/docs/)
- [Redis vs Memcached](https://aws.amazon.com/elasticache/redis-vs-memcached/)
- [Redis Patterns](https://redis.io/docs/manual/patterns/)
