# Design YouTube / Video Streaming

**Difficulty**: Hard | **Time Target**: 40-45 min

## 1. Requirements
Functional: Upload video, transcode to multiple resolutions, stream with adaptive bitrate. Non-Functional: Low startup latency, no buffering, global reach.

## 2. Design Overview
Upload → Transcode (FFmpeg workers: 240p, 360p, 720p, 1080p) → Store chunks in S3 → Serve via CDN. Adaptive bitrate streaming (HLS/DASH): client switches quality based on bandwidth. Thumbnail generation async. Metadata DB (PostgreSQL). Recommendation: separate ML service. Video processed async via task queue.

## Best Articles
- [Design YouTube - ByteByteGo](https://blog.bytebytego.com/p/design-youtube)
