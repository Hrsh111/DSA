# Blob / Object Storage

## What is it?
Storage for unstructured data (images, videos, documents, backups) as objects with metadata, accessed via HTTP APIs. Unlike file systems, no directory hierarchy — flat namespace with keys.

## Key Points
- **Object = data + metadata + unique key**
- Access via HTTP: `PUT /bucket/key`, `GET /bucket/key`
- Virtually unlimited storage, pay per GB
- Highly durable (99.999999999% — 11 nines on S3)
- No file system operations (can't append, modify in place — must rewrite entire object)
- CDN integration for serving content globally

## Examples
| Service | Provider |
|---------|----------|
| S3 | AWS |
| GCS | Google Cloud |
| Azure Blob | Microsoft |
| MinIO | Self-hosted (S3-compatible) |

## When to Use
- User-uploaded images/videos
- Static website assets
- Backups, logs, data lake storage
- Any large file storage (>1MB)

## When NOT to Use
- Frequently modified data (use database)
- Low-latency random access (use Redis/DB)
- Structured data requiring queries (use database)

## Interview Tips
- "User images stored in S3 with CloudFront CDN in front for low-latency serving"
- "Pre-signed URLs for secure direct upload from client to S3 (bypass our servers)"
- Mention lifecycle policies: "Move to Glacier after 90 days for cost savings"

## Best Articles
- [AWS S3 Documentation](https://docs.aws.amazon.com/s3/)
- [Object Storage vs Block vs File](https://www.ibm.com/topics/object-storage)
