# Database Partitioning

## What is it?
Splitting a large table into smaller, more manageable pieces. Unlike sharding (across servers), partitioning can be within a single database.

## Types

### 1. Horizontal Partitioning (Row-based)
- Split rows across partitions (e.g., orders from 2024 in one partition, 2025 in another)
- Most common type
- Same schema, different data ranges

### 2. Vertical Partitioning (Column-based)
- Split columns (e.g., frequently accessed columns in one table, rarely used in another)
- Like normalization but for performance
- Example: user_profile (name, email) separate from user_preferences (theme, language)

### 3. Functional Partitioning
- Different data types in different databases entirely
- Example: orders in PostgreSQL, search in Elasticsearch, cache in Redis

## Partition Strategies
| Strategy | How | Example |
|----------|-----|---------|
| Range | By value ranges | By date: Jan-Mar, Apr-Jun |
| List | By explicit values | By country: US, UK, IN |
| Hash | By hash of key | hash(user_id) % 4 |
| Composite | Combination | Range by date, then hash by user |

## Key Points
- Partitioning vs Sharding: partitioning = within one server, sharding = across servers
- **Partition pruning**: query optimizer skips irrelevant partitions
- Helps with: large table maintenance, archiving old data, query performance
- PostgreSQL has built-in declarative partitioning since v10

## When to Use
- Tables with millions+ of rows
- Time-series data (partition by month/year)
- Multi-tenant applications (partition by tenant)
- When you need to efficiently archive/delete old data

## Trade-offs
| Pros | Cons |
|------|------|
| Faster queries (partition pruning) | More complex schema management |
| Easier maintenance (drop old partitions) | Cross-partition queries can be slow |
| Better INSERT performance | Need to choose partition key wisely |

## Interview Tips
- Differentiate partitioning (single DB) from sharding (multiple DBs)
- For time-series: "Partition by month so we can drop old partitions easily"
- Mention partition pruning as the key performance benefit

## Best Articles
- [PostgreSQL Partitioning](https://www.postgresql.org/docs/current/ddl-partitioning.html)
- [Database Partitioning Strategies](https://blog.bytebytego.com/p/database-partitioning)
- [Designing Data-Intensive Applications Ch.6](https://dataintensive.net/)
