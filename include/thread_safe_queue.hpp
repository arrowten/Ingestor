#pragma once

#include <queue>
#include <mutex>
#include <condition_variable>

// Thread-safe queue for communication between stages
template<typename T>
class Thread_Safe_Queue {
    private:
    std::queue<T> q_;                   // Internal standard queue
    mutable std::mutex mtx_;            // Mutex for locking
    std::condition_variable cv_;        // Condition variable for blocking pop()

    public:
    // Add an item to the queue
    void push(const T& item) {
        {
            std::lock_guard<std::mutex> lock(mtx_);
            q_.push(item);
        }

        // Wake up one waiting thread
        cv_.notify_one();
    }

    // Remove and return the front item
    T pop() {
        std::unique_lock<std::mutex> lock(mtx_);
        // Wait until queue is non-empty
        cv_.wait(lock, [this]() { return !q_.empty(); });
        T item = q_.front();
        q_.pop();

        return item;
    }

    // Check if the queue is empty
    bool empty() const {
        std::lock_guard<std::mutex> lock(mtx_);

        return q_.empty();
    }
};