# Design API Rate Limiter (Distributed)

**Difficulty**: Easy | **Time Target**: 20-25 min

## Same as Rate Limiter but focuses on distributed aspects:
- Multiple API servers share rate limit state via Redis
- Race condition: use Redis Lua scripts for atomic increment + check
- Sliding window counter for accuracy across window boundaries
- Sync vs async: check locally with periodic sync to Redis (reduces latency)
- Failure mode: if Redis is down, allow requests (fail-open) or deny (fail-close)?

## Best Articles
- [Stripe Rate Limiting](https://stripe.com/blog/rate-limiters)
- [Cloudflare Rate Limiting](https://blog.cloudflare.com/counting-things-a-lot-of-different-things/)
