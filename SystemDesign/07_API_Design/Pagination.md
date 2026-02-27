# Pagination - Cursor vs Offset

## Types

### 1. Offset-Based
```
GET /api/posts?offset=20&limit=10
SELECT * FROM posts ORDER BY id LIMIT 10 OFFSET 20;
```
- Simple to implement
- Problem: slow for large offsets (DB scans N+offset rows)
- Problem: inconsistent if data is inserted/deleted between pages

### 2. Cursor-Based (Keyset)
```
GET /api/posts?after=post_abc123&limit=10
SELECT * FROM posts WHERE id > 'post_abc123' ORDER BY id LIMIT 10;
```
- Uses a pointer (cursor) to the last seen item
- Consistent even if data changes
- Fast (uses index, no scanning)
- Can't jump to page N directly

## Comparison
| Feature | Offset | Cursor |
|---------|--------|--------|
| Jump to page N | Yes | No |
| Performance at scale | Degrades | Constant |
| Consistency | Inconsistent | Consistent |
| Implementation | Simple | Moderate |

## Key Points
- **Offset** for small datasets, admin dashboards, when "page N" is needed
- **Cursor** for feeds, timelines, large datasets, real-time data
- Cursor is usually the **encoded ID** of the last item (base64 encoded)
- Always include `hasNextPage` / `nextCursor` in response
- Total count is expensive at scale — avoid if possible

## Interview Tips
- Default to cursor-based: "Cursor pagination for our feed API — constant time, consistent results"
- "Offset for the admin dashboard where page jumping is needed and dataset is small"

## Best Articles
- [Pagination Best Practices](https://blog.bytebytego.com/p/ep55-api-pagination)
- [Slack Engineering: Pagination](https://slack.engineering/evolving-api-pagination-at-slack/)
