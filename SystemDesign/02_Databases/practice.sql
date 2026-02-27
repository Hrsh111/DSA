-- ═══════════════════════════════════════════════════════════
-- Database System Design Practice - SQL Queries
-- Run these in SQLite or PostgreSQL to practice
-- ═══════════════════════════════════════════════════════════

-- ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
-- 1. SCHEMA DESIGN
-- ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

-- Users table
CREATE TABLE users (
    id SERIAL PRIMARY KEY,
    username VARCHAR(50) UNIQUE NOT NULL,
    email VARCHAR(100) UNIQUE NOT NULL,
    password_hash VARCHAR(255) NOT NULL,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- Posts table (one-to-many with users)
CREATE TABLE posts (
    id SERIAL PRIMARY KEY,
    user_id INTEGER NOT NULL REFERENCES users(id),
    title VARCHAR(200) NOT NULL,
    content TEXT,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- Tags table (many-to-many with posts)
CREATE TABLE tags (
    id SERIAL PRIMARY KEY,
    name VARCHAR(50) UNIQUE NOT NULL
);

CREATE TABLE post_tags (
    post_id INTEGER REFERENCES posts(id),
    tag_id INTEGER REFERENCES tags(id),
    PRIMARY KEY (post_id, tag_id)
);

-- Followers table (self-referencing many-to-many)
CREATE TABLE followers (
    follower_id INTEGER REFERENCES users(id),
    following_id INTEGER REFERENCES users(id),
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    PRIMARY KEY (follower_id, following_id)
);

-- ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
-- 2. INDEXING PRACTICE
-- ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

-- Index for user lookup by email
CREATE INDEX idx_users_email ON users(email);

-- Composite index for posts by user, ordered by date
CREATE INDEX idx_posts_user_date ON posts(user_id, created_at DESC);

-- Index for tag name lookups
CREATE INDEX idx_tags_name ON tags(name);

-- ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
-- 3. QUERY PRACTICE
-- ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

-- Q1: Get all posts by a user with their username
SELECT u.username, p.title, p.created_at
FROM posts p
JOIN users u ON p.user_id = u.id
WHERE u.username = 'harsh'
ORDER BY p.created_at DESC;

-- Q2: Get top 10 users by post count
SELECT u.username, COUNT(p.id) as post_count
FROM users u
LEFT JOIN posts p ON u.id = p.user_id
GROUP BY u.id, u.username
ORDER BY post_count DESC
LIMIT 10;

-- Q3: Get posts with their tags
SELECT p.title, STRING_AGG(t.name, ', ') as tags
FROM posts p
LEFT JOIN post_tags pt ON p.id = pt.post_id
LEFT JOIN tags t ON pt.tag_id = t.id
GROUP BY p.id, p.title;

-- Q4: Get mutual followers (users who follow each other)
SELECT f1.follower_id as user_a, f1.following_id as user_b
FROM followers f1
JOIN followers f2 ON f1.follower_id = f2.following_id
    AND f1.following_id = f2.follower_id
WHERE f1.follower_id < f1.following_id;

-- Q5: Get follower count for each user
SELECT u.username, COUNT(f.follower_id) as follower_count
FROM users u
LEFT JOIN followers f ON u.id = f.following_id
GROUP BY u.id, u.username
ORDER BY follower_count DESC;

-- ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
-- 4. TRANSACTIONS (ACID Practice)
-- ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

-- Transfer money between accounts (Atomicity example)
-- CREATE TABLE accounts (
--     id SERIAL PRIMARY KEY,
--     user_id INTEGER REFERENCES users(id),
--     balance DECIMAL(10, 2) NOT NULL CHECK (balance >= 0)
-- );

-- BEGIN;
-- UPDATE accounts SET balance = balance - 100 WHERE user_id = 1;
-- UPDATE accounts SET balance = balance + 100 WHERE user_id = 2;
-- COMMIT;

-- ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
-- 5. PARTITIONING EXAMPLE
-- ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

-- Range partition by date (PostgreSQL)
-- CREATE TABLE events (
--     id SERIAL,
--     event_type VARCHAR(50),
--     created_at TIMESTAMP NOT NULL
-- ) PARTITION BY RANGE (created_at);
--
-- CREATE TABLE events_2025 PARTITION OF events
--     FOR VALUES FROM ('2025-01-01') TO ('2026-01-01');
-- CREATE TABLE events_2026 PARTITION OF events
--     FOR VALUES FROM ('2026-01-01') TO ('2027-01-01');

-- ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
-- 6. EXPLAIN ANALYZE (Check query performance)
-- ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

-- EXPLAIN ANALYZE SELECT * FROM users WHERE email = 'harsh@example.com';
-- Should show: Index Scan using idx_users_email (not Seq Scan)
