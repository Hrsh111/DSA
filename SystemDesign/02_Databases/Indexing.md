# Database Indexing

## What is it?
A data structure that improves the speed of data retrieval on a database table at the cost of additional writes and storage.

Think of it like a book's index — instead of reading every page, jump to the right page.

## Types of Indexes

### 1. B-Tree Index (Most Common)
- Balanced tree structure, O(log N) lookup
- Works for: equality, range queries, sorting
- Default index type in PostgreSQL, MySQL

### 2. Hash Index
- O(1) lookup for exact matches
- Does NOT work for range queries
- Good for: equality-only lookups (e.g., session IDs)

### 3. Composite Index
- Index on multiple columns: `CREATE INDEX idx ON users(city, age)`
- Follows **leftmost prefix rule**: (city, age) works for city alone, but NOT age alone

### 4. Full-Text Index
- For text search (LIKE '%keyword%' is slow)
- Uses inverted index internally
- PostgreSQL: `tsvector`, MySQL: `FULLTEXT`

### 5. Covering Index
- Index contains all columns needed by query → no table lookup needed
- Extremely fast but uses more storage

## Key Points
- Indexes speed up reads but slow down writes (must update index on every insert/update)
- Too many indexes = slow writes, wasted storage
- Query planner decides whether to use an index (`EXPLAIN ANALYZE`)
- **Cardinality matters**: index on gender (M/F) is useless, index on email is great
- Primary key is automatically indexed

## When to Use
- Columns in WHERE, JOIN, ORDER BY, GROUP BY
- Foreign keys
- Columns with high cardinality (many unique values)

## When NOT to Use
- Small tables (full scan is faster)
- Columns rarely used in queries
- Columns with low cardinality
- Write-heavy tables where read speed isn't critical

## Trade-offs
| Pros | Cons |
|------|------|
| Faster reads (O(log N) vs O(N)) | Slower writes (update index) |
| Efficient sorting | Extra storage |
| Better JOIN performance | Over-indexing hurts overall perf |

## Interview Tips
- "We'd add an index on frequently queried columns like user_id and email"
- Mention composite indexes for multi-column queries
- Know when indexes hurt: "For a write-heavy logging table, we'd minimize indexes"

## Best Articles
- [Use The Index, Luke](https://use-the-index-luke.com/)
- [PostgreSQL Index Types](https://www.postgresql.org/docs/current/indexes-types.html)
- [Database Indexing Explained](https://blog.bytebytego.com/p/ep35-database-indexing)
