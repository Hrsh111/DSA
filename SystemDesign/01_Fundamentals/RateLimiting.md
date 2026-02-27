# Rate Limiting

## What is it?
Controls how many requests a client can make in a given time window. Prevents abuse, DDoS, and ensures fair resource usage.

## Algorithms

### 1. Token Bucket
- Bucket holds N tokens, refilled at a fixed rate
- Each request consumes 1 token; rejected if empty
- Allows burst traffic (up to bucket size)
- Used by: AWS API Gateway, Stripe

### 2. Leaky Bucket
- Requests enter a queue (bucket); processed at a fixed rate
- Queue overflow = rejected
- Smooths out bursts into a steady rate
- Used by: Nginx

### 3. Fixed Window Counter
- Count requests in fixed time windows (e.g., per minute)
- Reset counter at window boundary
- Problem: burst at window boundary (2x spike)

### 4. Sliding Window Log
- Store timestamp of each request
- Count requests in last N seconds
- Accurate but memory-heavy

### 5. Sliding Window Counter
- Hybrid of fixed window + sliding window
- Weighted count from current + previous window
- Best balance of accuracy and efficiency

## Key Points
- Rate limit by: IP, user ID, API key, or endpoint
- Return **HTTP 429 Too Many Requests** when limit exceeded
- Include headers: `X-RateLimit-Limit`, `X-RateLimit-Remaining`, `X-RateLimit-Reset`
- For distributed systems: use Redis for centralized counting
- Race condition: use Redis Lua scripts for atomic increment + check

## When to Use
- Public APIs (prevent abuse)
- Login endpoints (prevent brute force)
- Any resource-intensive endpoint

## Trade-offs
| Algorithm | Burst Handling | Memory | Accuracy |
|-----------|---------------|--------|----------|
| Token Bucket | Allows bursts | Low | Good |
| Leaky Bucket | Smooths bursts | Low | Good |
| Fixed Window | Double burst at edge | Low | Poor |
| Sliding Log | No bursts | High | Perfect |
| Sliding Counter | Controlled bursts | Low | Good |

## Interview Tips
- **Token bucket** is the go-to answer for most rate limiting questions
- For distributed rate limiting, mention Redis + Lua scripts
- Always mention what happens when the limit is hit (429 + retry-after header)

## Best Articles
- [Rate Limiting Algorithms Explained](https://blog.bytebytego.com/p/rate-limiting-fundamentals)
- [Stripe Rate Limiting](https://stripe.com/blog/rate-limiters)
- [System Design: Rate Limiter](https://www.youtube.com/watch?v=FU4WlwfS3G0)
