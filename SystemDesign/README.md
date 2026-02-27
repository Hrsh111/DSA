# System Design for SDE-I Interviews

A structured collection of system design concepts and practice problems tailored for SDE-I level interviews.

---

## Directory Structure

```
SystemDesign/
├── README.md                  # This file - roadmap & progress tracker
├── REVISION.xlsx              # Revision tracker
│
├── 01_Fundamentals/           # 8 concepts
├── 02_Databases/              # 7 concepts
├── 03_Caching/                # 5 concepts
├── 04_MessageQueues/          # 4 concepts
├── 05_LoadBalancing/          # 4 concepts
├── 06_Microservices/          # 5 concepts
├── 07_API_Design/             # 5 concepts
├── 08_Storage/                # 4 concepts
├── 09_Networking/             # 4 concepts
└── 10_Practice_Problems/      # 20 design problems
```

---

## Progress Tracker

### 01. Fundamentals (8 concepts)
| # | Concept | Difficulty | Status |
|---|---------|------------|--------|
| 1 | [Scalability - Vertical vs Horizontal](01_Fundamentals/Scalability.md) | Easy | ⬜ |
| 2 | [CAP Theorem](01_Fundamentals/CAPTheorem.md) | Medium | ⬜ |
| 3 | [Consistency Patterns](01_Fundamentals/ConsistencyPatterns.md) | Medium | ⬜ |
| 4 | [Availability Patterns](01_Fundamentals/AvailabilityPatterns.md) | Medium | ⬜ |
| 5 | [Latency vs Throughput](01_Fundamentals/LatencyVsThroughput.md) | Easy | ⬜ |
| 6 | [Rate Limiting](01_Fundamentals/RateLimiting.md) | Medium | ⬜ |
| 7 | [Consistent Hashing](01_Fundamentals/ConsistentHashing.md) | Hard | ⬜ |
| 8 | [Back-of-the-Envelope Estimation](01_Fundamentals/BackOfEnvelopeEstimation.md) | Medium | ⬜ |

### 02. Databases (7 concepts)
| # | Concept | Difficulty | Status |
|---|---------|------------|--------|
| 1 | [SQL vs NoSQL](02_Databases/SQLvsNoSQL.md) | Easy | ⬜ |
| 2 | [Database Sharding](02_Databases/Sharding.md) | Hard | ⬜ |
| 3 | [Database Replication](02_Databases/Replication.md) | Medium | ⬜ |
| 4 | [Database Indexing](02_Databases/Indexing.md) | Medium | ⬜ |
| 5 | [ACID Properties](02_Databases/ACID.md) | Easy | ⬜ |
| 6 | [Database Partitioning](02_Databases/Partitioning.md) | Medium | ⬜ |
| 7 | [Leader Election](02_Databases/LeaderElection.md) | Hard | ⬜ |

### 03. Caching (5 concepts)
| # | Concept | Difficulty | Status |
|---|---------|------------|--------|
| 1 | [Caching Strategies (Write-through, Write-back, Write-around)](03_Caching/CachingStrategies.md) | Medium | ⬜ |
| 2 | [Cache Eviction Policies (LRU, LFU, FIFO)](03_Caching/CacheEviction.md) | Medium | ⬜ |
| 3 | [CDN (Content Delivery Network)](03_Caching/CDN.md) | Easy | ⬜ |
| 4 | [Redis & Memcached](03_Caching/RedisMemcached.md) | Medium | ⬜ |
| 5 | [Cache Invalidation](03_Caching/CacheInvalidation.md) | Hard | ⬜ |

### 04. Message Queues (4 concepts)
| # | Concept | Difficulty | Status |
|---|---------|------------|--------|
| 1 | [Pub/Sub Model](04_MessageQueues/PubSub.md) | Medium | ⬜ |
| 2 | [Kafka Basics](04_MessageQueues/Kafka.md) | Medium | ⬜ |
| 3 | [Event-Driven Architecture](04_MessageQueues/EventDriven.md) | Medium | ⬜ |
| 4 | [Task Queues & Workers](04_MessageQueues/TaskQueues.md) | Easy | ⬜ |

### 05. Load Balancing (4 concepts)
| # | Concept | Difficulty | Status |
|---|---------|------------|--------|
| 1 | [Load Balancer Types (L4 vs L7)](05_LoadBalancing/LBTypes.md) | Medium | ⬜ |
| 2 | [Load Balancing Algorithms](05_LoadBalancing/LBAlgorithms.md) | Medium | ⬜ |
| 3 | [Reverse Proxy](05_LoadBalancing/ReverseProxy.md) | Easy | ⬜ |
| 4 | [Health Checks & Failover](05_LoadBalancing/HealthChecks.md) | Medium | ⬜ |

### 06. Microservices (5 concepts)
| # | Concept | Difficulty | Status |
|---|---------|------------|--------|
| 1 | [Monolith vs Microservices](06_Microservices/MonolithVsMicroservices.md) | Easy | ⬜ |
| 2 | [Service Discovery](06_Microservices/ServiceDiscovery.md) | Medium | ⬜ |
| 3 | [API Gateway](06_Microservices/APIGateway.md) | Medium | ⬜ |
| 4 | [Circuit Breaker Pattern](06_Microservices/CircuitBreaker.md) | Medium | ⬜ |
| 5 | [Saga Pattern (Distributed Transactions)](06_Microservices/SagaPattern.md) | Hard | ⬜ |

### 07. API Design (5 concepts)
| # | Concept | Difficulty | Status |
|---|---------|------------|--------|
| 1 | [REST vs GraphQL vs gRPC](07_API_Design/RESTvsGraphQLvsGRPC.md) | Medium | ⬜ |
| 2 | [API Versioning](07_API_Design/APIVersioning.md) | Easy | ⬜ |
| 3 | [Pagination (Cursor vs Offset)](07_API_Design/Pagination.md) | Medium | ⬜ |
| 4 | [Idempotency](07_API_Design/Idempotency.md) | Medium | ⬜ |
| 5 | [WebSockets vs SSE vs Polling](07_API_Design/WebSocketsVsSSE.md) | Medium | ⬜ |

### 08. Storage (4 concepts)
| # | Concept | Difficulty | Status |
|---|---------|------------|--------|
| 1 | [Blob / Object Storage (S3)](08_Storage/ObjectStorage.md) | Easy | ⬜ |
| 2 | [File System Design](08_Storage/FileSystem.md) | Medium | ⬜ |
| 3 | [Data Lakes vs Data Warehouses](08_Storage/DataLakesVsWarehouses.md) | Medium | ⬜ |
| 4 | [Replication vs Erasure Coding](08_Storage/ReplicationVsErasureCoding.md) | Hard | ⬜ |

### 09. Networking (4 concepts)
| # | Concept | Difficulty | Status |
|---|---------|------------|--------|
| 1 | [DNS (Domain Name System)](09_Networking/DNS.md) | Easy | ⬜ |
| 2 | [TCP vs UDP](09_Networking/TCPvsUDP.md) | Easy | ⬜ |
| 3 | [HTTP/HTTPS and TLS](09_Networking/HTTP_TLS.md) | Medium | ⬜ |
| 4 | [Proxies (Forward vs Reverse)](09_Networking/Proxies.md) | Easy | ⬜ |

---

## Practice Problems (SDE-I Level)

### Easy (Design conversations, not full systems)
| # | Problem | Key Concepts | Status |
|---|---------|-------------|--------|
| 1 | [Design a URL Shortener (TinyURL)](10_Practice_Problems/URLShortener.md) | Hashing, DB, Caching | ⬜ |
| 2 | [Design a Pastebin](10_Practice_Problems/Pastebin.md) | Object Storage, Hashing | ⬜ |
| 3 | [Design a Rate Limiter](10_Practice_Problems/RateLimiter.md) | Token Bucket, Sliding Window | ⬜ |
| 4 | [Design an API Rate Limiter](10_Practice_Problems/APIRateLimiter.md) | Redis, Distributed Counting | ⬜ |

### Medium (Core SDE-I interview questions)
| # | Problem | Key Concepts | Status |
|---|---------|-------------|--------|
| 5 | [Design Instagram / Photo Sharing](10_Practice_Problems/Instagram.md) | CDN, Object Storage, Feed | ⬜ |
| 6 | [Design Twitter / News Feed](10_Practice_Problems/TwitterFeed.md) | Fan-out, Caching, Timeline | ⬜ |
| 7 | [Design a Chat System (WhatsApp)](10_Practice_Problems/ChatSystem.md) | WebSockets, MQ, Presence | ⬜ |
| 8 | [Design a Notification System](10_Practice_Problems/NotificationSystem.md) | Pub/Sub, Priority Queue | ⬜ |
| 9 | [Design an E-commerce System](10_Practice_Problems/ECommerce.md) | Inventory, Payments, Cart | ⬜ |
| 10 | [Design a Parking Lot System](10_Practice_Problems/ParkingLot.md) | OOP, Concurrency | ⬜ |
| 11 | [Design a Key-Value Store](10_Practice_Problems/KeyValueStore.md) | LSM Tree, Consistent Hashing | ⬜ |
| 12 | [Design an Autocomplete System](10_Practice_Problems/Autocomplete.md) | Trie, Caching, Ranking | ⬜ |
| 13 | [Design a File Storage Service (Google Drive)](10_Practice_Problems/FileStorage.md) | Chunking, Sync, Dedup | ⬜ |
| 14 | [Design a Logging System](10_Practice_Problems/LoggingSystem.md) | ELK Stack, Time-series DB | ⬜ |

### Hard (Stretch goals for SDE-I)
| # | Problem | Key Concepts | Status |
|---|---------|-------------|--------|
| 15 | [Design YouTube / Video Streaming](10_Practice_Problems/VideoStreaming.md) | CDN, Encoding, Chunking | ⬜ |
| 16 | [Design Uber / Ride Sharing](10_Practice_Problems/RideSharing.md) | Geospatial, Matching, ETA | ⬜ |
| 17 | [Design a Web Crawler](10_Practice_Problems/WebCrawler.md) | BFS, Dedup, Politeness | ⬜ |
| 18 | [Design a Search Engine](10_Practice_Problems/SearchEngine.md) | Inverted Index, Ranking | ⬜ |
| 19 | [Design a Distributed Cache](10_Practice_Problems/DistributedCache.md) | Consistent Hashing, Replication | ⬜ |
| 20 | [Design a Ticket Booking System (BookMyShow)](10_Practice_Problems/TicketBooking.md) | Concurrency, Locking, Payments | ⬜ |

---

## Framework for Answering System Design Questions

### Step 1: Requirements Clarification (2-3 min)
- Functional requirements (what does the system do?)
- Non-functional requirements (scale, latency, availability)
- Back-of-the-envelope estimation (users, QPS, storage)

### Step 2: High-Level Design (5-8 min)
- Draw the major components (client, server, DB, cache)
- Define APIs
- Data flow diagram

### Step 3: Deep Dive (10-15 min)
- Database schema design
- Scaling strategy (sharding, replication)
- Caching layer
- Handle edge cases and failures

### Step 4: Wrap Up (2-3 min)
- Bottlenecks and trade-offs
- What would you change at 10x / 100x scale?
- Monitoring and alerting

---

## Suggested Study Order for SDE-I

### Week 1-2: Build the Foundation
1. **Fundamentals** — Scalability, CAP Theorem, Latency vs Throughput
2. **Networking** — DNS, HTTP, TCP/UDP
3. **Databases** — SQL vs NoSQL, Indexing, ACID

### Week 3-4: Core Building Blocks
4. **Caching** — Strategies, Eviction, CDN
5. **Load Balancing** — Types, Algorithms
6. **Message Queues** — Pub/Sub, Kafka basics

### Week 5-6: Architecture Patterns
7. **Microservices** — Monolith vs Micro, API Gateway
8. **API Design** — REST, Pagination, WebSockets
9. **Storage** — Object Storage, File Systems

### Week 7-8: Practice Problems
10. Start with Easy (URL Shortener, Pastebin)
11. Move to Medium (Instagram, Chat System, KV Store)
12. Attempt Hard if time permits (YouTube, Uber)

---

## Time Targets

| Difficulty | Target Time | Depth Expected |
|------------|-------------|----------------|
| Easy | 20-25 min | Full design with trade-offs |
| Medium | 30-35 min | High-level + 1-2 deep dives |
| Hard | 40-45 min | High-level + acknowledge complexity |

---

## Quick Reference: What to Use When

| Need | Technology / Pattern |
|------|---------------------|
| Fast reads | Caching (Redis), CDN |
| Fast writes | Message Queue, Write-back cache |
| Search | Inverted Index (Elasticsearch) |
| Real-time | WebSockets, SSE |
| File uploads | Object Storage (S3), Chunking |
| Unique IDs | UUID, Snowflake ID, Hash |
| Location queries | Geospatial Index, QuadTree |
| Ordering / Feed | Fan-out on write vs Fan-out on read |
| Rate limiting | Token Bucket, Sliding Window |
| High availability | Replication, Failover, Load Balancing |

---

Good luck!
