#pragma once
#include "thread_safe_queue.hpp"
#include "extractor.hpp"
#include "transformer.hpp"
#include "loader.hpp"
#include <thread>
#include <atomic>

// Pipeline Manager: orchestrates Extract -> Transform -> Load using threads
class PipelineManager {
    private:
    Thread_Safe_Queue<std::string> queue_; // Shared queue
    Extractor extractor_;
    Transformer transformer_;
    Loader loader_;
    std::thread extractor_thread_;
    std::thread transformer_thread_;
    std::thread loader_thread_;
    std::atomic<bool> running_; // Flag to control pipeline execution

    public:
    PipelineManager();
    ~PipelineManager();
    // Start running the pipeline
    void start();
    // Stop the pipeline and join threads
    void stop();
};