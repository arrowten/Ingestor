# 🖼️ Ingestor: Multithreaded Data Pipeline in C++

Welcome to the C++ Data Pipeline Project! 🚀
This project simulates a multi-stage data pipeline using modern C++, featuring thread-safe communication between stages via a custom Thread_Safe_Queue.
It showcases real-world concepts like multithreading, synchronization, producer-consumer patterns, and data transformation.

## 🛠️ Features

1. Thread-safe communication between pipeline stages. The 3 stages:
    - Extraction 🧹 — Read/generate raw data
    - Transformation 🔧 — Modify or clean the data
    - Loading 🏗️ — Save/process the final data
2. Custom ThreadSafeQueue for safe data sharing between threads
3. Condition variables to block and wake up efficiently
4. Scalable design for future extensions

## 📂 Project Structure

- /include
    - pipeline_manager.hpp      // Manages pipeline threads
    - thread_safe_queue.hpp     // Thread-safe queue implementation
- /source
    - pipeline_manager.cpp      // Pipeline execution logic
    - main.cpp                  // Program entry point
- /_pipeline_build (generated by CMake)
- CMakeLists.txt                   // Build configuration
- README.md                        // This file

## 🖥️ How to Build & Run

1. Clone the repository:

```
git clone https://github.com/arrowten/Ingestor.git
cd Ingestor
```

2. Build 

```
sh build.sh
```

3. Run

```
sh run.sh
```

## 📜 Example Output

```
[INFO]: Extracted: data item
[INFO]: Transformed: DATA ITEM
Loaded: DATA ITEM
[INFO]: Extracted: data item
[INFO]: Transformed: DATA ITEM
Loaded: DATA ITEM
...
```

✅ Smooth multithreaded extraction, transformation, and loading of data!

## ⚡ Technologies Used

1. C++17/20 (Modern C++ features)
2. CMake (for building)
3. POSIX Threads (via std::thread, std::mutex)