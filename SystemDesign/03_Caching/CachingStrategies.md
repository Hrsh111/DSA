# Caching Strategies

## What is it?
Patterns for reading/writing data between your application, cache, and database.

## Strategies

### 1. Cache-Aside (Lazy Loading) ⭐ Most Common
```
Read: App checks cache → miss → read DB → write to cache → return
Write: App writes to DB → invalidate/delete cache entry
```
- App manages the cache directly
- Cache only has data that's been requested (no wasted space)
- Cache miss = extra latency (3 trips)

### 2. Read-Through
```
Read: App reads cache → cache reads DB on miss → returns to app
Write: Same as cache-aside (app writes to DB)
```
- Cache manages DB reads (transparent to app)
- Simpler app code, cache library handles misses

### 3. Write-Through
```
Write: App writes to cache → cache writes to DB → ack to app
Read: Always from cache (always fresh)
```
- Data in cache is always up-to-date
- Higher write latency (2 writes per operation)
- Good for read-heavy workloads where consistency matters

### 4. Write-Behind (Write-Back)
```
Write: App writes to cache → ack immediately → cache async writes to DB
Read: Always from cache
```
- Fastest writes (async DB write)
- Risk of data loss if cache crashes before DB write
- Good for write-heavy workloads

### 5. Refresh-Ahead
```
Cache proactively refreshes entries BEFORE they expire
```
- Reduces cache miss latency for hot keys
- Wastes resources if predictions are wrong

## Key Points
- **Cache-aside** is the default choice for most systems
- **Write-through** when you need strong consistency between cache and DB
- **Write-behind** for write-heavy workloads (accept some data loss risk)
- TTL (Time to Live) is critical — set expiration on all cache entries
- Cache stampede: many requests hit DB simultaneously when a popular key expires

## Interview Tips
- Default to cache-aside: "Read from cache, fall back to DB, populate cache on miss"
- Mention TTL: "We'd set a 5-minute TTL to balance freshness and performance"
- For write-heavy: "Write-behind with an async queue to batch DB writes"

## Best Articles
- [Caching Strategies - AWS](https://docs.aws.amazon.com/whitepapers/latest/database-caching-strategies-using-redis/caching-patterns.html)
- [ByteByteGo: Caching Patterns](https://blog.bytebytego.com/p/top-caching-strategies)
- [System Design Primer - Cache](https://github.com/donnemartin/system-design-primer#cache)
