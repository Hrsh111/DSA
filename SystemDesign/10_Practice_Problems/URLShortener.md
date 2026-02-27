# Design URL Shortener (TinyURL)

**Difficulty**: Easy | **Time Target**: 20-25 min

## 1. Requirements

### Functional Requirements
- Given a long URL, generate a short unique URL
- Given a short URL, redirect to the original long URL
- Optional: custom short URLs, expiration, analytics

### Non-Functional Requirements
- Low latency redirects (<100ms)
- High availability (URL shortener should never be down)
- Short URLs should not be predictable (security)

### Back-of-the-Envelope Estimation
- 100M URLs created/day → ~1200 write QPS
- Read:Write ratio = 100:1 → 120K read QPS
- Storage: 100M × 500 bytes = 50 GB/day → ~18 TB/year
- Short URL length: 7 chars (base62) = 62^7 = 3.5 trillion unique URLs

## 2. High-Level Design

### API
```
POST /api/shorten  { longUrl: "https://..." } → { shortUrl: "https://tiny.url/abc1234" }
GET  /:shortCode   → 301 Redirect to long URL
```

### Encoding Strategy
- **Base62 encoding**: [a-zA-Z0-9] = 62 chars, 7 chars = 3.5T unique URLs
- Option 1: Hash long URL (MD5/SHA) → take first 7 chars (collision possible)
- Option 2: Auto-increment ID → Base62 encode (predictable but simple)
- Option 3: Pre-generate random IDs (best — no collision, not predictable)

### Data Model
```
urls table:
  id          BIGINT PRIMARY KEY
  short_code  VARCHAR(7) UNIQUE INDEX
  long_url    TEXT NOT NULL
  user_id     BIGINT (optional)
  created_at  TIMESTAMP
  expires_at  TIMESTAMP (optional)
```

### Architecture
```
Client → Load Balancer → App Servers → Cache (Redis) → Database (MySQL/PostgreSQL)
```

## 3. Deep Dive
- **Cache**: Redis cache for hot URLs (most URLs follow 80/20 rule). Cache-aside pattern.
- **Read path**: Check Redis → if miss, query DB → cache result → 301 redirect
- **Write path**: Generate short code → write to DB → return short URL
- **ID Generation**: Use a distributed ID generator (Snowflake) or pre-generate IDs in batches
- **301 vs 302**: 301 (permanent redirect, browser caches) vs 302 (temporary, always hits server — better for analytics)

## 4. Scaling & Trade-offs
- Database: start with single PostgreSQL, shard by short_code hash when needed
- Cache: Redis cluster, cache popular URLs (LRU eviction)
- Rate limiting: prevent abuse (max 100 URLs/min per user)
- Analytics: async write to Kafka → analytics pipeline

## 5. Key Takeaways
- Core problem: unique short code generation at scale
- Cache is critical — most reads are for popular URLs
- 7-char base62 gives 3.5T URLs — enough for decades
