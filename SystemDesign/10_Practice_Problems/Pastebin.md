# Design Pastebin

**Difficulty**: Easy | **Time Target**: 20-25 min

## 1. Requirements
### Functional: Create paste (text) → get unique URL. Read paste by URL. Optional: expiration, syntax highlighting.
### Non-Functional: Low read latency, high availability, handle large pastes (up to 10MB)
### Estimation: 5M pastes/day, 50M reads/day. Avg paste 10KB → 50GB/day → 18TB/year

## 2. High-Level Design
```
POST /api/paste { content, expiry } → { url: "paste.bin/abc123" }
GET  /api/paste/:id → { content, createdAt, expiresAt }
```
- Generate unique ID (base62 encoded auto-increment or random)
- Store metadata in DB (PostgreSQL), content in Object Storage (S3)
- Cache popular pastes in Redis

## 3. Key Decisions
- S3 for content (cheap, durable) vs DB blob (simpler but expensive at scale)
- Cleanup expired pastes: cron job or lazy deletion on read
- Rate limiting to prevent spam

## Best Articles
- [Educative: Design Pastebin](https://www.educative.io/courses/grokking-modern-system-design-interview-for-engineers-managers/system-design-pastebin)
