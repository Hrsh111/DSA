# Design Rate Limiter

**Difficulty**: Easy | **Time Target**: 20-25 min

## 1. Requirements
### Functional: Limit requests per client per time window. Return 429 when exceeded. Support different limits per API endpoint.
### Non-Functional: Low latency (<1ms overhead), distributed (works across multiple servers), fault tolerant
### Estimation: 10M users, 1000 req/min limit → check 10B rate limit queries/day

## 2. High-Level Design
```
Client → API Gateway (rate limit check) → Backend Services
                ↕
         Redis (rate limit counters)
```

## 3. Algorithm Choice
- **Token Bucket** (recommended): Bucket with N tokens, refill at fixed rate. Allows controlled bursts.
- **Sliding Window Counter**: Weighted average of current + previous window. Good accuracy, low memory.

## 4. Key Decisions
- Where: API Gateway (centralized) vs each service (decentralized)
- Storage: Redis (INCR + EXPIRE, atomic with Lua script)
- Rules: rate limit by IP, user ID, API key, or endpoint
- Headers: X-RateLimit-Limit, X-RateLimit-Remaining, X-RateLimit-Reset, Retry-After

## Best Articles
- [System Design: Rate Limiter - ByteByteGo](https://blog.bytebytego.com/p/rate-limiting-fundamentals)
