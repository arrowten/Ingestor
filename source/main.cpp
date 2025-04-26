#include "pipeline_manager.hpp"
#include <chrono>
#include <thread>

// Main function to run the data pipeline
int main() {
    PipelineManager pipeline;
    pipeline.start(); // Start ETL process
    // Let the pipeline run for 5 seconds
    std::this_thread::sleep_for(std::chrono::seconds(5));
    pipeline.stop(); // Gracefully stop the pipeline

    return 0;
}