# Pub/Sub Model

## What is it?
A messaging pattern where **publishers** send messages to a **topic** (not directly to receivers), and **subscribers** receive messages from topics they're interested in. Decouples senders from receivers.

```
Publisher → [Topic: "orders"] → Subscriber A (email service)
                              → Subscriber B (analytics)
                              → Subscriber C (inventory)
```

## Key Points
- **Decoupling**: Publisher doesn't know/care about subscribers
- **Fan-out**: One message goes to ALL subscribers of that topic
- **Point-to-Point** (queue) vs **Pub/Sub**: Queue = one consumer gets message; Pub/Sub = all subscribers get it
- At-least-once delivery: Messages may be delivered multiple times → consumers must be **idempotent**
- Message ordering is NOT guaranteed in most systems (Kafka guarantees within a partition)

## Implementations
| Service | Type | Best For |
|---------|------|----------|
| Apache Kafka | Distributed log | High throughput, event streaming |
| RabbitMQ | Message broker | Complex routing, low latency |
| AWS SNS | Cloud pub/sub | Simple fan-out, serverless |
| Google Pub/Sub | Cloud pub/sub | GCP ecosystem |
| Redis Pub/Sub | In-memory | Simple real-time notifications |

## When to Use
- Event-driven architectures (order placed → notify multiple services)
- Microservice communication (async)
- Real-time notifications
- Log aggregation

## Trade-offs
| Pros | Cons |
|------|------|
| Loose coupling | Added complexity |
| Easy to add subscribers | Message ordering challenges |
| Handles traffic spikes (buffering) | Debugging is harder |
| Fault tolerance | Eventual consistency |

## Interview Tips
- "We'd use Kafka as a message bus between services for async communication"
- Mention idempotency: "Consumers need to handle duplicate messages"
- Fan-out example: "When a user places an order, we publish to 'orders' topic — email, inventory, and analytics services all consume it independently"

## Best Articles
- [Pub/Sub Pattern - Microsoft](https://learn.microsoft.com/en-us/azure/architecture/patterns/publisher-subscriber)
- [Kafka vs RabbitMQ](https://blog.bytebytego.com/p/kafka-vs-rabbitmq)
