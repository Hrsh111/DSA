# Cache Eviction Policies

## What is it?
When cache is full, which entry do we remove to make space? The eviction policy decides.

## Policies

### 1. LRU (Least Recently Used) ⭐ Most Common
- Evict the entry that hasn't been accessed for the longest time
- Implemented with: HashMap + Doubly Linked List → O(1) get/put
- Used by: Redis, Memcached, OS page cache

### 2. LFU (Least Frequently Used)
- Evict the entry with the fewest accesses
- Better for skewed workloads (some keys accessed way more)
- More complex to implement (frequency counter + min-heap)

### 3. FIFO (First In, First Out)
- Evict the oldest entry (regardless of access pattern)
- Simple but often poor performance

### 4. Random
- Evict a random entry
- Surprisingly decent performance, simple implementation

### 5. TTL-Based
- Entries expire after a set time
- Not strictly eviction but commonly combined with LRU

## LRU Implementation (Interview Favorite)
```
HashMap<Key, Node> + Doubly Linked List

get(key):
  if key in map: move node to head, return value
  else: return -1

put(key, value):
  if key in map: update value, move to head
  else:
    if full: remove tail node, delete from map
    add new node to head, add to map
```

## Key Points
- **LRU** is the default answer in interviews
- Redis supports: LRU, LFU, random, TTL-based eviction
- LRU + TTL is the most common combination in production
- Cache size: typically 10-20% of DB size covers 80% of requests (Pareto principle)

## When to Use
- **LRU**: General purpose, most web applications
- **LFU**: When some items are significantly more popular
- **FIFO**: Simple queue-like caches
- **TTL**: When data freshness matters more than space

## Trade-offs
| Policy | Hit Rate | Complexity | Best For |
|--------|---------|-----------|---------|
| LRU | Good | O(1) | General purpose |
| LFU | Better (skewed) | O(log N) | Popular items |
| FIFO | Poor | O(1) | Simple cases |
| Random | Decent | O(1) | When simplicity matters |

## Interview Tips
- Be ready to code LRU cache from scratch (LeetCode #146)
- "We'd use LRU with a 15-minute TTL, sized at ~20% of our dataset"
- Know that Redis `maxmemory-policy` configures this

## Best Articles
- [LeetCode #146 - LRU Cache](https://leetcode.com/problems/lru-cache/)
- [Redis Eviction Policies](https://redis.io/docs/reference/eviction/)
- [Cache Replacement Policies](https://en.wikipedia.org/wiki/Cache_replacement_policies)
