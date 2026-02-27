# Scalability - Vertical vs Horizontal

## What is it?
Scalability is the ability of a system to handle growing amounts of work by adding resources.

- **Vertical Scaling (Scale Up)**: Add more power (CPU, RAM, SSD) to an existing machine
- **Horizontal Scaling (Scale Out)**: Add more machines to the pool

## Key Points
- Vertical scaling has a hardware ceiling — you can't infinitely upgrade one machine
- Horizontal scaling requires a **load balancer** to distribute traffic
- Stateless services scale horizontally easily; stateful services (databases) are harder
- Most real systems use a **hybrid** — scale up to a limit, then scale out
- Database reads scale with **replicas**, writes scale with **sharding**

## Comparison

| Aspect | Vertical | Horizontal |
|--------|----------|------------|
| Cost | Expensive (high-end hardware) | Cheaper (commodity machines) |
| Complexity | Simple | Complex (distributed systems) |
| Downtime | Usually needs downtime | Zero downtime |
| Fault Tolerance | Single point of failure | Built-in redundancy |
| Limit | Hardware ceiling | Virtually unlimited |

## When to Use
- **Vertical**: Small/medium apps, databases hard to shard, quick growth fix
- **Horizontal**: Large-scale apps, web servers, microservices, high availability needs

## Trade-offs
| Pros | Cons |
|------|------|
| Vertical: Simple, no code changes | Vertical: Hardware limit, SPOF |
| Horizontal: Unlimited, fault tolerant | Horizontal: Complex, consistency issues |

## Interview Tips
- Always mention **both** and when to pick each
- For databases: reads scale with replicas, writes with sharding
- "We'd start vertical for simplicity, then go horizontal as we hit limits"

## Best Articles
- [System Design Primer - Scalability](https://github.com/donnemartin/system-design-primer#scalability)
- [Harvard CS75 Scalability Lecture](https://www.youtube.com/watch?v=-W9F__D3oY4)
- [Scalability for Dummies](https://www.lecloud.net/tagged/scalability)
