# DNS - Domain Name System

## What is it?
Translates human-readable domain names (google.com) to IP addresses (142.250.80.46). The "phone book of the internet."

## How DNS Resolution Works
```
Browser → Local Cache → OS Cache → Router Cache → ISP DNS Resolver
  → Root DNS (.com) → TLD DNS (google.com) → Authoritative DNS → IP Address
```

## Record Types
| Type | Purpose | Example |
|------|---------|---------|
| A | Domain → IPv4 | google.com → 142.250.80.46 |
| AAAA | Domain → IPv6 | google.com → 2607:f8b0::200e |
| CNAME | Alias → another domain | www.google.com → google.com |
| MX | Mail server | google.com → mail.google.com |
| NS | Nameserver | google.com → ns1.google.com |
| TXT | Text records | SPF, DKIM, verification |

## Key Points
- DNS is hierarchical and distributed (no single point of failure)
- **TTL (Time-to-Live)**: How long to cache a DNS response (300s - 86400s typical)
- DNS can be used for load balancing (round-robin A records, or weighted routing)
- DNS propagation delay: changes take time to propagate (hours due to caching)
- **DNS-based failover**: Route53 health checks + failover routing

## When to Use in System Design
- Domain routing and service discovery
- Global load balancing (Route53 latency-based routing)
- Failover between regions

## Interview Tips
- "DNS with Route53 for latency-based routing to direct users to the nearest region"
- Know TTL trade-offs: short = faster failover, more DNS lookups; long = better caching, slower updates

## Best Articles
- [How DNS Works (Comic)](https://howdns.works/)
- [AWS Route53 Documentation](https://docs.aws.amazon.com/Route53/)
