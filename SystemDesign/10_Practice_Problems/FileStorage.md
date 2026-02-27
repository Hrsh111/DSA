# Design File Storage Service (Google Drive)

**Difficulty**: Medium | **Time Target**: 30-35 min

## 1. Requirements
Functional: Upload/download files, sync across devices, share files, version history. Non-Functional: No data loss, sync within seconds, handle large files (up to 10GB).

## 2. Design Overview
Chunking: split files into 4MB chunks, only upload changed chunks (delta sync). Metadata DB: file tree, versions, sharing permissions. Object Storage (S3) for file chunks. Sync: client maintains local file watcher → detects changes → uploads changed chunks → notifies other clients via WebSocket. Conflict resolution: last-write-wins or create conflict copy.

## Best Articles
- [Design Google Drive - ByteByteGo](https://blog.bytebytego.com/p/design-google-drive)
