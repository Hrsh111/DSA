/*
 * Token Bucket Rate Limiter Implementation
 *
 * System Design Relevance: Rate limiting APIs, preventing DDoS,
 * fair usage enforcement. Used by Stripe, AWS API Gateway.
 */
#include <iostream>
#include <chrono>
#include <thread>
#include <unordered_map>
using namespace std;

class TokenBucket {
    int maxTokens;
    int tokens;
    double refillRate; // tokens per second
    chrono::steady_clock::time_point lastRefill;

    void refill() {
        auto now = chrono::steady_clock::now();
        double elapsed = chrono::duration<double>(now - lastRefill).count();
        int newTokens = (int)(elapsed * refillRate);
        if (newTokens > 0) {
            tokens = min(maxTokens, tokens + newTokens);
            lastRefill = now;
        }
    }

public:
    TokenBucket(int maxTokens, double refillRate)
        : maxTokens(maxTokens), tokens(maxTokens), refillRate(refillRate),
          lastRefill(chrono::steady_clock::now()) {}

    bool allowRequest() {
        refill();
        if (tokens > 0) {
            tokens--;
            return true;
        }
        return false; // rate limited (HTTP 429)
    }
};

// Per-user rate limiter
class RateLimiter {
    unordered_map<string, TokenBucket> buckets;
    int maxTokens;
    double refillRate;

public:
    RateLimiter(int maxTokens, double refillRate)
        : maxTokens(maxTokens), refillRate(refillRate) {}

    bool allowRequest(const string& userId) {
        if (buckets.find(userId) == buckets.end()) {
            buckets.emplace(userId, TokenBucket(maxTokens, refillRate));
        }
        return buckets.at(userId).allowRequest();
    }
};

int main() {
    // 5 requests max, refill 1 per second
    RateLimiter limiter(5, 1.0);

    string user = "user:harsh";

    // Send 8 requests rapidly
    for (int i = 1; i <= 8; i++) {
        bool allowed = limiter.allowRequest(user);
        cout << "Request " << i << ": " << (allowed ? "ALLOWED" : "RATE LIMITED (429)") << endl;
    }

    // Wait 3 seconds for tokens to refill
    cout << "\nWaiting 3 seconds...\n" << endl;
    this_thread::sleep_for(chrono::seconds(3));

    for (int i = 9; i <= 12; i++) {
        bool allowed = limiter.allowRequest(user);
        cout << "Request " << i << ": " << (allowed ? "ALLOWED" : "RATE LIMITED (429)") << endl;
    }

    return 0;
}
