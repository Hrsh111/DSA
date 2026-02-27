# Design Search Engine

**Difficulty**: Hard | **Time Target**: 40-45 min

## 1. Requirements
Functional: Index web pages, handle search queries, rank results by relevance. Non-Functional: <500ms query latency, fresh index (hours), handle 10K QPS.

## 2. Design Overview
Inverted Index: word → list of documents containing it. Ranking: TF-IDF + PageRank + freshness + user signals. Architecture: Crawler → Indexer (build inverted index, shard by term) → Query Service (scatter-gather across shards, merge results). Cache frequent queries in Redis.

## Best Articles
- [Design Search Engine - ByteByteGo](https://blog.bytebytego.com/p/design-google-search)
