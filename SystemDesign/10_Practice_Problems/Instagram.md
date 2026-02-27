# Design Instagram / Photo Sharing

**Difficulty**: Medium | **Time Target**: 30-35 min

## 1. Requirements
### Functional: Upload photos, view feed (timeline), follow users, like/comment
### Non-Functional: Feed generation <200ms, image upload <5s, high availability
### Estimation: 500M DAU, 2M uploads/day, 500M feed reads/day

## 2. High-Level Design
```
Client → CDN (images) + API Gateway → [Upload, Feed, User, Notification] Services → DB + Cache + S3
```

## 3. Key Components
- **Upload**: Client → pre-signed URL → upload directly to S3 → notify upload service → create post record
- **Feed Generation**: Fan-out on write for normal users (push to followers' feed cache). Fan-out on read for celebrities (pull on request).
- **Storage**: Metadata in MySQL/PostgreSQL, images in S3+CDN, feed in Redis sorted set
- **Database**: posts, users, followers, likes tables. Shard by user_id.

## 4. Deep Dive
- Feed: Redis sorted set per user (post_id, timestamp). Pre-computed on write.
- Celebrity problem: Don't fan-out for users with >1M followers. Merge on read.
- Image sizes: Store multiple resolutions. Generate thumbnails async (task queue).

## Best Articles
- [Designing Instagram - Educative](https://www.educative.io/courses/grokking-modern-system-design-interview-for-engineers-managers/system-design-instagram)
- [Instagram Engineering Blog](https://instagram-engineering.com/)
