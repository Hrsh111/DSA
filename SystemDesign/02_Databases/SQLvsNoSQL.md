# SQL vs NoSQL

## What is it?
Two fundamentally different approaches to storing and querying data.

**SQL (Relational)**: Structured data in tables with rows and columns. Uses SQL language. Enforces schema.
**NoSQL (Non-Relational)**: Flexible schemas. Four types: Document, Key-Value, Column-Family, Graph.

## Types of NoSQL
| Type | Example | Best For |
|------|---------|----------|
| Document | MongoDB, CouchDB | JSON-like data, flexible schema |
| Key-Value | Redis, DynamoDB | Caching, sessions, simple lookups |
| Column-Family | Cassandra, HBase | Time-series, write-heavy workloads |
| Graph | Neo4j, ArangoDB | Relationships, social networks |

## Key Points
- SQL: ACID transactions, JOINs, strong schema, vertical scaling
- NoSQL: BASE (Basically Available, Soft state, Eventually consistent), no JOINs, horizontal scaling
- SQL is better when you need: complex queries, transactions, data integrity
- NoSQL is better when you need: flexible schema, high write throughput, horizontal scaling
- Most large systems use **both** (polyglot persistence)

## When to Use
- **SQL**: Banking, e-commerce orders, anything needing transactions and JOINs
- **NoSQL Document**: User profiles, product catalogs, CMS
- **NoSQL Key-Value**: Caching, session storage, leaderboards
- **NoSQL Column**: IoT data, event logging, time-series
- **NoSQL Graph**: Social networks, recommendation engines

## Trade-offs
| SQL | NoSQL |
|-----|-------|
| Strong consistency | Eventual consistency (usually) |
| Fixed schema | Flexible schema |
| Vertical scaling | Horizontal scaling |
| Complex queries (JOINs) | Simple queries (no JOINs) |
| Mature, well-understood | Newer, varies by type |

## Interview Tips
- Don't just pick one — explain WHY based on the requirements
- "We'll use PostgreSQL for user accounts (need transactions) and Redis for caching (need speed)"
- Mention polyglot persistence for large systems

## Best Articles
- [SQL vs NoSQL - ByteByteGo](https://blog.bytebytego.com/p/ep39-sql-vs-nosql)
- [MongoDB vs PostgreSQL](https://www.mongodb.com/compare/mongodb-postgresql)
- [System Design Primer - SQL vs NoSQL](https://github.com/donnemartin/system-design-primer#sql-or-nosql)
