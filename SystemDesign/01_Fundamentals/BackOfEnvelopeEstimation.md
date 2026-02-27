# Back-of-the-Envelope Estimation

## What is it?
Quick rough calculations to estimate system capacity — how much storage, bandwidth, and compute a system needs. Every system design interview starts with this.

## Power of 2 Cheat Sheet
```
2^10 = 1 Thousand    = 1 KB
2^20 = 1 Million     = 1 MB
2^30 = 1 Billion     = 1 GB
2^40 = 1 Trillion    = 1 TB
2^50 = 1 Quadrillion = 1 PB
```

## Key Numbers to Know
```
QPS:
- 1 day = 86,400 seconds ≈ 100K seconds (for easy math)
- 1 million requests/day ≈ 12 QPS
- 100 million requests/day ≈ 1,200 QPS

Storage:
- 1 char = 1 byte (ASCII) or 2-4 bytes (Unicode)
- Average tweet = ~300 bytes
- Average image = ~200 KB (compressed)
- Average video (1 min, 720p) = ~50 MB
- Average metadata per record = ~500 bytes

Bandwidth:
- 1 Gbps link = ~125 MB/s
- Saturating 1 Gbps with 200KB images = ~625 images/sec
```

## Framework for Estimation
1. **Start with users**: DAU (Daily Active Users)
2. **Estimate actions**: How many actions per user per day?
3. **Calculate QPS**: actions/day ÷ 86400
4. **Peak QPS**: QPS × 2-5 (peak multiplier)
5. **Storage**: size per record × records/day × retention period
6. **Bandwidth**: QPS × average request/response size

## Example: Design Twitter
```
Assumptions:
- 300M DAU
- Each user tweets 2/day, reads 100 tweets/day
- Tweet size: 300 bytes text + optional 200KB image (20% have images)

Write QPS: 300M × 2 / 86400 ≈ 7,000 QPS
Read QPS:  300M × 100 / 86400 ≈ 350,000 QPS
Peak Read: 350K × 3 ≈ 1M QPS

Storage/day:
- Text: 600M × 300B = 180 GB
- Images: 120M × 200KB = 24 TB
- Total: ~24 TB/day → ~8.7 PB/year

Bandwidth:
- Read: 350K × 300B = 105 MB/s (text only)
- With images: much higher → need CDN
```

## When to Use
- **Every** system design interview, in the first 2-3 minutes
- When deciding between SQL vs NoSQL, single server vs distributed

## Interview Tips
- Round aggressively — 86400 ≈ 100K, precision doesn't matter
- State assumptions clearly: "Let's assume 100M DAU"
- Show the math: QPS, storage, bandwidth
- Use the numbers to justify decisions: "At 1M QPS we need caching + load balancing"

## Best Articles
- [ByteByteGo: Back of Envelope Estimation](https://blog.bytebytego.com/p/back-of-the-envelope-estimation)
- [System Design Primer - Powers of 2](https://github.com/donnemartin/system-design-primer#powers-of-two-table)
- [Jeff Dean's Numbers](https://gist.github.com/jboner/2841832)
