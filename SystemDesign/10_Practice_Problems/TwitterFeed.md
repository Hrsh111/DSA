# Design Twitter / News Feed

**Difficulty**: Medium | **Time Target**: 30-35 min

## 1. Requirements
### Functional: Post tweets, follow users, view home timeline, search
### Non-Functional: Timeline load <200ms, 300M DAU
### Estimation: 600M tweets/day (7K QPS write), 300B feed reads/day (3.5M QPS read)

## 2. Feed Generation: The Core Problem
### Fan-Out on Write (Push)
- When user tweets → push to all followers' timeline cache
- Fast reads (pre-computed), expensive writes for popular users
- Works for: users with <10K followers

### Fan-Out on Read (Pull)
- On timeline request → fetch tweets from all followed users → merge → sort
- Cheap writes, expensive reads
- Works for: celebrities

### Hybrid (Twitter's actual approach)
- Push for normal users, pull for celebrities
- On read: merge pre-computed feed + fetch celebrity tweets

## 3. Architecture
```
Tweet Service → Fanout Service → Timeline Cache (Redis)
                               → Notification Service
                               → Search Index (Elasticsearch)
```

## Best Articles
- [How Twitter Timeline Works](https://blog.bytebytego.com/p/news-feed-system-design)
- [Twitter System Design - Gaurav Sen](https://www.youtube.com/watch?v=wYk0xPP_P_8)
