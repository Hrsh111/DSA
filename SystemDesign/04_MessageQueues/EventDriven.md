# Event-Driven Architecture

## What is it?
A software design pattern where the flow of the program is determined by events — state changes that are published, detected, and consumed by different services.

```
[Order Service] --"OrderPlaced"--> [Message Bus] --> [Email Service]
                                                 --> [Inventory Service]
                                                 --> [Analytics Service]
```

## Key Concepts
- **Event**: Something that happened (past tense). "OrderPlaced", "UserRegistered"
- **Command**: A request to do something. "PlaceOrder", "SendEmail"
- **Event Sourcing**: Store events as the source of truth, derive state by replaying events
- **CQRS**: Command Query Responsibility Segregation — separate read/write models

## Key Points
- Services are loosely coupled — they don't call each other directly
- Enables async processing — services work at their own pace
- Events are immutable facts — never modified, only appended
- Eventual consistency — not all services update at the same time
- Saga pattern handles distributed transactions across services

## When to Use
- Microservices that need to communicate without tight coupling
- Systems where multiple services react to the same event
- Audit logging (event log = complete history)
- Real-time data pipelines

## Trade-offs
| Pros | Cons |
|------|------|
| Loose coupling | Debugging is harder (distributed traces) |
| Easy to add new consumers | Eventual consistency complexity |
| Natural audit log | Event schema evolution challenges |
| Better fault isolation | More infrastructure (message bus) |

## Interview Tips
- "Instead of synchronous REST calls between services, we'd use events via Kafka for loose coupling"
- Mention event sourcing for systems that need audit trails
- Acknowledge the complexity: "EDA adds operational overhead but pays off at scale"

## Best Articles
- [Event-Driven Architecture - Martin Fowler](https://martinfowler.com/articles/201701-event-driven.html)
- [Event Sourcing Pattern](https://learn.microsoft.com/en-us/azure/architecture/patterns/event-sourcing)
- [ByteByteGo: Event-Driven Architecture](https://blog.bytebytego.com/p/event-driven-architecture)
