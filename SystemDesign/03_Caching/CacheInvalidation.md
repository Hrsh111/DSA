# Cache Invalidation

## What is it?
The process of removing or updating stale data from the cache when the underlying data changes. One of the hardest problems in CS.

> "There are only two hard things in Computer Science: cache invalidation and naming things." — Phil Karlton

## Strategies

### 1. TTL (Time-to-Live)
- Set expiration time on each cache entry
- Simple but data can be stale until TTL expires
- Good default: 5-15 minutes for most data

### 2. Event-Driven Invalidation
- When data changes in DB, publish event → cache listener deletes/updates entry
- More complex but cache is always fresh
- Use message queues (Kafka) or DB triggers

### 3. Write-Through Invalidation
- On every write, update cache + DB together
- Cache is always fresh but higher write latency

### 4. Versioned Keys
- Include version in cache key: `user:123:v5`
- On update, increment version → old key naturally expires
- No explicit invalidation needed

## Key Points
- **Cache stampede**: Popular key expires → thousands of requests hit DB simultaneously
  - Solution: Lock (only one request fetches, others wait) or early refresh
- **Stale-while-revalidate**: Return stale data immediately, refresh in background
- **Delete vs update**: Prefer DELETE over UPDATE in cache (simpler, avoids race conditions)
- Double-delete pattern: Delete cache → update DB → wait → delete cache again

## Common Problems
| Problem | Solution |
|---------|---------|
| Cache stampede | Mutex lock, early refresh |
| Stale data | Shorter TTL, event-driven invalidation |
| Inconsistency | Write-through, double-delete |
| Cold cache after restart | Cache warming (pre-load popular keys) |

## Interview Tips
- Mention TTL as the baseline: "Every key has a TTL so stale data eventually expires"
- For consistency-critical data: "Event-driven invalidation via Kafka"
- Know cache stampede and the mutex solution

## Best Articles
- [Cache Invalidation Patterns](https://blog.bytebytego.com/p/cache-invalidation)
- [Facebook Memcache Scaling Paper](https://research.facebook.com/publications/scaling-memcache-at-facebook/)
- [Cache Stampede Prevention](https://en.wikipedia.org/wiki/Cache_stampede)
