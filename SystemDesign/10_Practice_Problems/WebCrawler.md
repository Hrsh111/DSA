# Design Web Crawler

**Difficulty**: Hard | **Time Target**: 40-45 min

## 1. Requirements
Functional: Crawl billions of web pages, extract content, follow links. Non-Functional: Polite (respect robots.txt), avoid duplicate pages, handle traps.

## 2. Design Overview
BFS traversal of the web graph. URL Frontier (priority queue of URLs to crawl). Fetcher workers (distributed). Content parser extracts links → add to frontier. Deduplication: URL bloom filter + content fingerprint (SimHash). Politeness: per-domain rate limiting, respect robots.txt. DNS cache to avoid repeated lookups.

## Best Articles
- [Design Web Crawler - ByteByteGo](https://blog.bytebytego.com/p/design-a-web-crawler)
