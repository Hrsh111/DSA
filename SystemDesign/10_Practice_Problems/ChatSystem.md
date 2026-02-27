# Design Chat System (WhatsApp)

**Difficulty**: Medium | **Time Target**: 30-35 min

## 1. Requirements

### Functional Requirements
- 1:1 messaging and group chat
- Online/offline status
- Message delivery status (sent, delivered, read)
- Message history/persistence
- Push notifications for offline users

### Non-Functional Requirements
- Real-time delivery (<100ms for online users)
- Message ordering guaranteed
- At-least-once delivery (no lost messages)
- Support millions of concurrent connections

### Back-of-the-Envelope Estimation
- 500M DAU, each sends 40 messages/day
- 20B messages/day → ~230K messages/sec
- Message size: ~200 bytes → 4 TB/day storage
- Concurrent connections: ~50M WebSocket connections

## 2. High-Level Design

### API
```
WebSocket: ws://chat.app/ws?token=jwt
  → send: { type: "message", to: "user_456", text: "hello" }
  ← receive: { type: "message", from: "user_123", text: "hello", timestamp: ... }

REST:
  GET /api/conversations          → list conversations
  GET /api/messages?conv_id=123   → message history (cursor pagination)
```

### Data Model
```
messages:
  id            UUID
  conversation_id  UUID
  sender_id     BIGINT
  content       TEXT (encrypted)
  type          ENUM(text, image, video)
  created_at    TIMESTAMP
  status        ENUM(sent, delivered, read)

conversations:
  id            UUID
  type          ENUM(direct, group)
  participants  BIGINT[] (or join table)
```

### Architecture
```
Client ←WebSocket→ Chat Server → Message Queue (Kafka) → Chat Server → Recipient
                                                        → Push Notification Service
                                → Message Store (Cassandra)
```

## 3. Deep Dive
- **WebSocket servers**: Maintain persistent connections. Stateful — need session management
- **Message flow**: Sender → Chat Server → Kafka (topic per user) → Recipient's Chat Server → Recipient
- **Offline users**: Messages stored in Kafka/DB. On reconnect, fetch undelivered messages
- **Group chat**: Fan-out on write (small groups) or fan-out on read (large groups)
- **Presence**: User heartbeats every 30s. No heartbeat for 60s = offline. Store in Redis.
- **Message ordering**: Use timestamp + sequence number per conversation
- **End-to-end encryption**: Signal Protocol (client encrypts, server can't read)

## 4. Scaling & Trade-offs
- WebSocket servers: stateful, need sticky sessions or service discovery
- Cassandra for messages: write-optimized, partition by conversation_id
- Redis for: online status, unread counts, recent conversations
- Push notifications: APNs (iOS), FCM (Android) for offline users

## 5. Key Takeaways
- WebSocket for real-time bidirectional communication
- Kafka as message relay for decoupling and reliability
- Cassandra for message storage (write-heavy, time-series-like)
- Separate online/offline message delivery paths
