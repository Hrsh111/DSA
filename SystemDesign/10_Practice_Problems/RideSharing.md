# Design Uber / Ride Sharing

**Difficulty**: Hard | **Time Target**: 40-45 min

## 1. Requirements
Functional: Rider requests ride, match with nearby driver, real-time tracking, ETA, fare calculation. Non-Functional: Match within 10 seconds, real-time location updates.

## 2. Design Overview
Geospatial index (QuadTree or Geohash) to find nearby drivers. Location Service: drivers send GPS every 5 seconds → update in Redis/QuadTree. Matching Service: find nearest available drivers → send request → first accept wins. ETA: graph-based shortest path (Dijkstra) with real-time traffic. Pricing: surge pricing based on demand/supply ratio.

## Best Articles
- [Design Uber - Educative](https://www.educative.io/courses/grokking-modern-system-design-interview-for-engineers-managers/system-design-uber)
