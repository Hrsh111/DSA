# Design Autocomplete/Typeahead System

**Difficulty**: Medium | **Time Target**: 30-35 min

## 1. Requirements
Functional: As user types, suggest top completions. Rank by popularity/relevance. Update suggestions based on new queries. Non-Functional: <100ms latency, handle 100K QPS.

## 2. Design Overview
Trie data structure for prefix matching. Each trie node stores top-K suggestions (pre-computed). Store trie in memory across multiple servers (shard by first 2 chars). Update: offline pipeline aggregates search queries → rebuild trie periodically. Cache: Redis for hot prefixes. Data gathering: Kafka → aggregation service → trie builder.

## Best Articles
- [Design Autocomplete - ByteByteGo](https://blog.bytebytego.com/p/design-autocomplete)
