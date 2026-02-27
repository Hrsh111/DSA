# Monolith vs Microservices

## What is it?
Two architectural approaches to building applications.

**Monolith**: Single deployable unit containing all functionality.
**Microservices**: Collection of small, independent services each handling one business capability.

## Comparison
| Aspect | Monolith | Microservices |
|--------|----------|---------------|
| Deployment | Single unit | Independent per service |
| Scaling | Scale entire app | Scale individual services |
| Technology | One tech stack | Polyglot (different languages) |
| Data | Shared database | Database per service |
| Complexity | Simple at first | Complex infrastructure |
| Team | One team can manage | Multiple teams needed |
| Debugging | Easy (one process) | Hard (distributed traces) |
| Latency | Function calls | Network calls |

## Key Points
- **Start monolith, migrate to microservices** when complexity demands it
- Microservices aren't always better — they add operational overhead
- Each microservice should own its data (no shared database)
- Communication: sync (REST/gRPC) or async (message queues)
- Need: service discovery, API gateway, distributed tracing, container orchestration

## When to Use
- **Monolith**: Small team (<10), new product, simple domain, moving fast
- **Microservices**: Large org, independent teams, different scaling needs per feature, tech diversity needed

## Interview Tips
- Don't jump to microservices: "We'd start with a monolith for faster iteration, then extract services as we identify clear boundaries"
- Show you know the trade-offs: "Microservices give us independent deployability but add network latency and operational complexity"

## Best Articles
- [Monolith First - Martin Fowler](https://martinfowler.com/bliki/MonolithFirst.html)
- [Microservices - Martin Fowler](https://martinfowler.com/articles/microservices.html)
- [ByteByteGo: Microservices Architecture](https://blog.bytebytego.com/p/microservice-architecture)
