#include "pipeline_manager.hpp"
#include "logger.hpp"

PipelineManager::PipelineManager() : running_(false) {}

PipelineManager::~PipelineManager() {
    stop();
}

// Starts extractor, transformer, loader threads
void PipelineManager::start() {
    running_ = true;

    // Extractor thread: fetch data and push to queue
    extractor_thread_ = std::thread([this]() {
        while(running_) {
            std::string data = extractor_.extract();
            Logger::info("Extracted: " + data);
            queue_.push(data);
            std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Simulate delay
        }
    });

    // Transformer thread: read extracted data, transform it, push back
    transformer_thread_ = std::thread([this]() {
        while(running_) {
            std::string item = queue_.pop();
            std::string transformed = transformer_.transform(item);
            Logger::info("Transformed: " + transformed);
            queue_.push(transformed);
        }
    });

    // Loader thread: read transformed data and output/store it
    loader_thread_ = std::thread([this]() {
        while(running_) {
            std::string transformed_data = queue_.pop();
            loader_.load(transformed_data);
        }
    });
}

// Stops all running threads safely
void PipelineManager::stop() {
    running_ = false;
    
    if(extractor_thread_.joinable()) {
        extractor_thread_.join();
    }
    
    if(transformer_thread_.joinable()) {
        transformer_thread_.join();
    }

    if(loader_thread_.joinable()) {
        loader_thread_.join();
    }
}
