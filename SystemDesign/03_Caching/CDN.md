# Content Delivery Network (CDN)

## What is it?
A network of geographically distributed servers that cache and serve content (images, videos, CSS, JS) from locations close to the user, reducing latency.

## How it Works
```
User (India) → CDN Edge Server (Mumbai) → [Cache Hit? Return] → [Miss? Fetch from Origin Server (US)]
```

## Types
- **Push CDN**: You upload content to CDN proactively. Good for static, infrequently changing content.
- **Pull CDN**: CDN fetches from origin on first request, then caches. Good for dynamic, high-traffic sites.

## Key Points
- Reduces latency by serving from nearby edge servers
- Reduces load on origin server
- Supports: static files (images, JS, CSS), video streaming, API responses
- Cache invalidation: TTL-based, or manual purge
- Popular CDNs: CloudFlare, AWS CloudFront, Akamai, Fastly
- CDN can also provide DDoS protection and SSL termination

## When to Use
- Any user-facing app with static assets
- Video/image heavy applications
- Global user base (different geographies)
- High traffic sites needing to offload origin

## Trade-offs
| Pros | Cons |
|------|------|
| Low latency for users | Cost (bandwidth charges) |
| Reduced origin load | Cache invalidation complexity |
| DDoS protection | Stale content possible |
| Global reach | Not great for dynamic, personalized content |

## Interview Tips
- "We'd put all static assets behind a CDN like CloudFront to reduce latency"
- For video: "CDN is essential — we'd use adaptive bitrate streaming via CDN"
- Mention cache invalidation strategy: TTL + versioned URLs (e.g., `style.v2.css`)

## Best Articles
- [What is a CDN? - Cloudflare](https://www.cloudflare.com/learning/cdn/what-is-a-cdn/)
- [System Design Primer - CDN](https://github.com/donnemartin/system-design-primer#content-delivery-network)
- [AWS CloudFront Guide](https://docs.aws.amazon.com/AmazonCloudFront/latest/DeveloperGuide/Introduction.html)
