# API Versioning

## What is it?
Managing changes to your API without breaking existing clients.

## Strategies
| Method | Example | Pros | Cons |
|--------|---------|------|------|
| URL Path | `/api/v1/users` | Clear, easy to route | URL pollution |
| Query Param | `/api/users?version=1` | Optional, backward compatible | Easy to miss |
| Header | `Accept: application/vnd.api.v1+json` | Clean URLs | Hidden, harder to test |
| Content Negotiation | `Accept: application/json; version=1` | RESTful | Complex |

## Key Points
- **URL path versioning** is the most common and recommended for simplicity
- Only version when there are **breaking changes** (removing fields, changing types)
- Non-breaking changes (adding fields) don't need a new version
- Deprecation policy: support old versions for N months, communicate timeline
- Keep max 2-3 active versions

## Interview Tips
- "URL path versioning (/api/v2/) for clarity. We'd support the last 2 versions with a 6-month deprecation window"
- Mention what constitutes a breaking change

## Best Articles
- [API Versioning Best Practices](https://blog.bytebytego.com/p/api-versioning)
- [Stripe API Versioning](https://stripe.com/blog/api-versioning)
