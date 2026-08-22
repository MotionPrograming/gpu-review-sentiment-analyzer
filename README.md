# GPU Review Sentiment Analyzer

A C++20-based large-scale GPU review data processing and sentiment analysis project using **Apache Arrow** and **Apache Parquet**.

---

## 📌 Overview

**GPU Review Sentiment Analyzer** is a data processing and sentiment analysis project designed to analyze large-scale customer reviews of GPU products.

The project uses a **custom-generated synthetic dataset containing approximately 3 million GPU review records**, stored in **Apache Parquet** format.

The application is being developed in **C++20** with **Apache Arrow** and **Apache Parquet** to efficiently process columnar data at scale.

The long-term goal is to build a scalable sentiment analysis pipeline capable of classifying GPU reviews into:

* Positive
* Neutral
* Negative

and generating useful insights about customer opinions, GPU performance, thermals, noise, pricing, and value.

> **Current status:** The project is in active development. The current implementation focuses on reliable Parquet access, schema inspection, and preparation for large-scale record-batch processing.

---

## 🎯 Project Objectives

The main objectives of this project are:

1. Process millions of GPU review records efficiently.
2. Use Apache Parquet for columnar data storage.
3. Use Apache Arrow for efficient C++ data processing.
4. Read Parquet data in batches.
5. Extract and process review text.
6. Implement sentiment analysis.
7. Classify reviews into positive, neutral, and negative categories.
8. Analyze sentiment patterns across GPU products and categories.
9. Investigate relationships between sentiment and GPU characteristics.
10. Benchmark the performance and memory usage of the processing pipeline.

---

## 🗂️ Dataset

This project uses a **custom-generated synthetic GPU review dataset**.

The dataset was generated specifically for this project and is not copied from an external review dataset.

### Dataset Information

| Property            | Value                |
| ------------------- | -------------------- |
| Dataset Type        | Synthetic            |
| Domain              | GPU / Graphics Cards |
| Approximate Records | 3,000,000            |
| File Format         | Apache Parquet       |
| Number of Columns   | 21                   |
| Primary Text Field  | `review_text`        |
| Reference Label     | `sentiment`          |

> **Important:** The dataset is synthetically generated for educational, experimentation, and research purposes. It should not be interpreted as real-world customer-review data.

The complete Parquet dataset is intentionally excluded from the Git repository because of its size.

---

## 📊 Dataset Schema

| Column              | Type   | Description                       |
| ------------------- | ------ | --------------------------------- |
| `review_id`         | string | Unique review identifier          |
| `product_id`        | string | GPU product identifier            |
| `product_name`      | string | GPU model/product name            |
| `manufacturer`      | string | GPU manufacturer                  |
| `brand`             | string | GPU brand                         |
| `reviewer_id`       | string | Reviewer identifier               |
| `rating`            | int8   | Review rating                     |
| `review_title`      | string | Review title                      |
| `review_text`       | string | Full review text                  |
| `review_date`       | string | Review date                       |
| `verified_purchase` | bool   | Whether the purchase was verified |
| `helpful_votes`     | int64  | Number of helpful votes           |
| `total_votes`       | int64  | Total number of votes             |
| `price_usd`         | float  | GPU price in USD                  |
| `gpu_category`      | string | GPU category                      |
| `use_case`          | string | Intended use case                 |
| `sentiment`         | string | Reference sentiment label         |
| `performance_score` | float  | Performance score                 |
| `temperature_score` | float  | Temperature score                 |
| `noise_score`       | float  | Noise score                       |
| `value_score`       | double | Value-for-money score             |

---

## 🏗️ System Architecture

### Current Data Processing Pipeline

```text
                 GPU Review Dataset
                         │
                         ▼
                 Apache Parquet
                         │
                         ▼
                  Apache Arrow
                         │
                         ▼
                  C++ Parquet Reader
                         │
                         ▼
                Schema Inspection
                         │
                         ▼
              Record Batch Processing
                         │
                         ▼
                  Review Text
```

### Planned Sentiment Pipeline

```text
                  Review Text
                       │
                       ▼
              Text Preprocessing
                       │
                       ▼
               Feature Extraction
                       │
                       ▼
              Sentiment Analysis
                       │
             ┌─────────┼─────────┐
             ▼         ▼         ▼
          Positive   Neutral   Negative
             │         │         │
             └─────────┼─────────┘
                       ▼
                Review Insights
```

---

## 🛠️ Technology Stack

### Programming Language

* C++20

### Data Processing

* Apache Arrow 25.0.1
* Apache Parquet 25.0.1

### Build System

* CMake

### Development Environment

* Linux
* GCC / G++
* Git
* GitHub

---

## 📁 Project Structure

```text
gpu-review-sentiment-analyzer/
│
├── data/
│   └── README.md
│
├── src/
│   └── main.cpp
│
├── CMakeLists.txt
├── README.md
└── .gitignore
```

The generated dataset is stored locally at:

```text
data/gpu_reviews_3m.parquet
```

The Parquet file is excluded from Git using `.gitignore`.

---

## ⚙️ Current Implementation

The current implementation focuses on the **initial Parquet data-access layer**.

### Implemented

* C++20 project setup
* CMake project configuration
* Apache Arrow integration
* Apache Parquet integration
* Parquet file opening
* Parquet reader creation
* Schema loading
* Column inspection
* Data type inspection

### Current Milestone

```text
Parquet File
     │
     ▼
File Open
     │
     ▼
Parquet Reader
     │
     ▼
Schema Loading
     │
     ▼
Column / Type Inspection
```

### Planned

* Read Parquet record batches
* Extract `review_text`
* Batch-based processing
* Text preprocessing
* Sentiment analysis
* Positive / Neutral / Negative classification
* Sentiment statistics
* GPU/product-level sentiment analysis
* Category-level analysis
* Negative-review issue analysis
* Performance benchmarking
* Memory optimization
* Parallel processing
* Final analytics/reporting

---

## 🚀 Build and Run

### 1. Clone the Repository

```bash
git clone git@github.com:MotionPrograming/gpu-review-sentiment-analyzer.git
cd gpu-review-sentiment-analyzer
```

### 2. Configure CMake

```bash
cmake -S . -B build
```

### 3. Build

```bash
cmake --build build -j$(nproc)
```

### 4. Run

Make sure the generated dataset exists at:

```text
data/gpu_reviews_3m.parquet
```

Then run:

```bash
./build/parquet_reader
```

---

## 📈 Example Current Output

The current implementation successfully opens the Parquet file and loads the dataset schema.

Example:

```text
[OK] File opened
[OK] Parquet reader created
[OK] Schema loaded

========================================
                 SCHEMA
========================================

review_id: string
product_id: string
product_name: string
manufacturer: string
brand: string
reviewer_id: string
rating: int8
review_title: string
review_text: string
review_date: string
verified_purchase: bool
helpful_votes: int64
total_votes: int64
price_usd: float
gpu_category: string
use_case: string
sentiment: string
performance_score: float
temperature_score: float
noise_score: float
value_score: double
```

> The current milestone verifies Parquet access and schema inspection. Full record-batch processing and sentiment analysis are still under development.

---

## 🔬 Sentiment Analysis

Sentiment analysis is the central long-term objective of the project.

The primary textual input will be the:

```text
review_text
```

field.

The planned processing pipeline is:

```text
Review Text
     │
     ▼
Text Preprocessing
     │
     ▼
Feature Extraction
     │
     ▼
Sentiment Analysis
     │
     ├── Positive
     ├── Neutral
     └── Negative
```

The existing:

```text
sentiment
```

column provides a reference label for development and evaluation of the sentiment-analysis pipeline.

Because the dataset is synthetic, evaluation methodology will need to account for how the labels and review text were generated to avoid misleading results or data leakage.

---

## 📊 Planned Analytics

Once sentiment analysis and batch processing are implemented, the project will support analysis such as:

* Which GPU products receive the most positive reviews?
* Which GPUs receive the most negative feedback?
* How do users perceive GPU performance?
* How do users perceive GPU temperature?
* How does price affect perceived value?
* Which GPU categories receive better sentiment?
* Which use cases generate the most positive feedback?
* What issues are commonly mentioned in negative reviews?
* How does sentiment relate to review ratings?
* How does sentiment vary between GPU manufacturers and brands?

---

## ⚡ Performance Goals

Processing approximately **3 million records** makes performance an important part of the project.

The project will investigate:

* Columnar data access
* Apache Parquet
* Apache Arrow
* C++ batch processing
* Efficient memory usage
* Record-batch processing
* Column projection
* Predicate filtering where applicable
* Parallel processing
* Processing throughput

### Planned Benchmarks

Performance measurements will include:

| Metric               | Description                                      |
| -------------------- | ------------------------------------------------ |
| Processing Time      | Total time required to process the dataset       |
| Throughput           | Records processed per second                     |
| Read Throughput      | Data read per second                             |
| Peak Memory          | Maximum memory consumption                       |
| Batch Size           | Effect of different record-batch sizes           |
| Parallel Performance | Comparison of sequential and parallel processing |

Benchmark results will be added as the implementation matures.

---

## 🧪 Development Roadmap

### Milestone 1 — Parquet Access ✅

* [x] C++20 project setup
* [x] CMake configuration
* [x] Apache Arrow integration
* [x] Apache Parquet integration
* [x] Open Parquet file
* [x] Create Parquet reader
* [x] Load schema
* [x] Inspect columns and data types

### Milestone 2 — Data Processing 🔄

* [ ] Read record batches
* [ ] Select required columns
* [ ] Extract `review_text`
* [ ] Process data in batches
* [ ] Improve memory efficiency

### Milestone 3 — Sentiment Analysis ⏳

* [ ] Text preprocessing
* [ ] Feature extraction
* [ ] Sentiment classifier
* [ ] Positive / Neutral / Negative classification
* [ ] Evaluation metrics

### Milestone 4 — GPU Review Analytics ⏳

* [ ] Product-level sentiment
* [ ] Manufacturer-level sentiment
* [ ] GPU category analysis
* [ ] Performance sentiment
* [ ] Temperature sentiment
* [ ] Noise sentiment
* [ ] Value sentiment
* [ ] Negative-review issue analysis

### Milestone 5 — Performance Engineering ⏳

* [ ] Benchmark dataset reading
* [ ] Benchmark batch processing
* [ ] Measure memory usage
* [ ] Compare batch sizes
* [ ] Investigate parallel processing
* [ ] Optimize processing pipeline

### Milestone 6 — Reporting ⏳

* [ ] Aggregate statistics
* [ ] Generate analytical reports
* [ ] Produce visualizations
* [ ] Document benchmark results
* [ ] Finalize end-to-end pipeline

---

## 🔐 Data and Repository Policy

The complete generated dataset is not committed to GitHub.

The following files and directories are intentionally ignored:

```text
*.parquet
data/*.parquet
*.deb
build/
cmake-build-*/
.vscode/
```

This keeps the repository lightweight while allowing the source code and project configuration to remain version controlled.

---

## 📚 Educational and Research Purpose

This project is developed as an educational and experimental **large-scale data processing and sentiment analysis system**.

It demonstrates practical concepts involving:

* C++20
* Data engineering
* Columnar data processing
* Apache Arrow
* Apache Parquet
* Natural Language Processing
* Sentiment analysis
* Batch processing
* Memory-efficient data processing
* Performance benchmarking

The synthetic dataset is intended for experimentation and does not represent real customer opinions.

---

## 🚧 Project Status

**Status: Work in Progress**

### Current Milestone

> **Successfully opening and inspecting the schema of a synthetic ~3 million-record GPU review dataset using C++20, Apache Arrow, and Apache Parquet.**

### Next Major Milestone

> **Implement record-batch reading and review-text extraction, followed by the sentiment-analysis pipeline.**

The project is being developed incrementally, with a focus on correctness, scalable data processing, and measurable performance.

---

## 👨‍💻 Author

**Md Abdullah Rajeb**

GitHub: [MotionPrograming](https://github.com/MotionPrograming)

---

## ⭐ Project Goals at a Glance

```text
3M+ GPU Reviews
       │
       ▼
Apache Parquet
       │
       ▼
Apache Arrow
       │
       ▼
C++20 Processing
       │
       ▼
Batch Processing
       │
       ▼
Review Text
       │
       ▼
Sentiment Analysis
       │
       ▼
GPU Review Analytics
       │
       ▼
Performance Benchmarking
```

---

## 📌 Disclaimer

This project and its synthetic dataset are intended for **educational, research, and software-engineering experimentation purposes**.

The generated reviews and sentiment labels are synthetic and should not be considered authentic customer feedback.
