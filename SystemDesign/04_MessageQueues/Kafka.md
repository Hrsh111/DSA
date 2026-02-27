# Kafka Basics

## What is it?
A distributed event streaming platform. Acts as a durable, high-throughput, fault-tolerant message log.

## Architecture
```
Producer → [Kafka Cluster] → Consumer
             |
     Topic: "orders"
     ├── Partition 0: [msg1, msg2, msg5]
     ├── Partition 1: [msg3, msg4, msg6]
     └── Partition 2: [msg7, msg8]
```

## Key Concepts
- **Topic**: Category/feed name (like a table)
- **Partition**: Ordered, immutable log within a topic. Parallelism unit.
- **Offset**: Position of a message in a partition
- **Producer**: Writes messages to topics
- **Consumer**: Reads messages from topics
- **Consumer Group**: Multiple consumers reading from a topic, each partition assigned to exactly one consumer in the group
- **Broker**: A Kafka server. Multiple brokers = cluster
- **Replication Factor**: How many copies of each partition

## Key Points
- Messages are **persistent** (written to disk) — not deleted after consumption
- Consumers track their own **offset** (where they left off)
- Ordering guaranteed only **within a partition**
- Throughput: millions of messages/second
- Retention: configurable (7 days default, can be infinite)
- Partition key determines which partition a message goes to

## When to Use
- Event sourcing, activity tracking (LinkedIn, Netflix)
- Log aggregation, metrics collection
- Stream processing (with Kafka Streams or Flink)
- Microservice async communication

## Trade-offs
| Pros | Cons |
|------|------|
| Extremely high throughput | Complex to operate |
| Durable (persistent log) | Ordering only within partition |
| Replay capability | Higher latency than RabbitMQ |
| Horizontal scaling | Requires ZooKeeper/KRaft |

## Interview Tips
- "Kafka for high-throughput event streaming, RabbitMQ for complex routing with low latency"
- Partition key: "We'd partition by user_id so all events for a user are ordered"
- Consumer groups: "Scale consumers by adding more to the group — each gets a partition"

## Best Articles
- [Kafka in a Nutshell](https://sookocheff.com/post/kafka/kafka-in-a-nutshell/)
- [Confluent Kafka 101](https://developer.confluent.io/what-is-apache-kafka/)
- [ByteByteGo: Kafka Architecture](https://blog.bytebytego.com/p/why-is-kafka-fast)
