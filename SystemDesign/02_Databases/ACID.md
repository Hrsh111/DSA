# ACID Properties

## What is it?
Four guarantees that database transactions provide to ensure data reliability.

- **A**tomicity: All operations in a transaction succeed or all fail. No partial updates.
- **C**onsistency: Transaction brings DB from one valid state to another. All constraints satisfied.
- **I**solation: Concurrent transactions don't interfere with each other.
- **D**urability: Once committed, data survives crashes (written to disk/WAL).

## Key Points
- ACID is the foundation of relational databases (PostgreSQL, MySQL)
- NoSQL databases often sacrifice some ACID properties for performance (BASE model)
- **BASE**: Basically Available, Soft state, Eventually consistent
- Isolation levels (from weakest to strongest):
  1. Read Uncommitted (dirty reads possible)
  2. Read Committed (no dirty reads)
  3. Repeatable Read (no phantom reads in some DBs)
  4. Serializable (strongest, slowest)

## Isolation Levels Explained
| Level | Dirty Read | Non-Repeatable Read | Phantom Read |
|-------|-----------|-------------------|-------------|
| Read Uncommitted | Yes | Yes | Yes |
| Read Committed | No | Yes | Yes |
| Repeatable Read | No | No | Maybe |
| Serializable | No | No | No |

## When to Use
- **Full ACID**: Banking, payments, inventory management
- **Relaxed (BASE)**: Social media, analytics, logging

## Trade-offs
| ACID | BASE |
|------|------|
| Strong consistency | Eventual consistency |
| Lower throughput | Higher throughput |
| Higher latency | Lower latency |
| Simple reasoning | Complex conflict handling |

## Interview Tips
- Know all four properties and be able to explain each with an example
- Bank transfer example: "Debit $100 from A and credit $100 to B — atomicity ensures both happen or neither"
- Know isolation levels — "We'd use Read Committed for most queries, Serializable for payment processing"

## Best Articles
- [ACID Explained - PostgreSQL Wiki](https://wiki.postgresql.org/wiki/ACID)
- [Database Internals Book](https://www.databass.dev/)
- [ByteByteGo: ACID vs BASE](https://blog.bytebytego.com/p/acid-vs-base)
