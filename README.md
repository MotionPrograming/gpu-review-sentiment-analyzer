````markdown
# GPU Review Sentiment Analyzer

A C++-based sentiment analysis project for processing and analyzing large-scale GPU product reviews using Apache Arrow and Apache Parquet.

---

## 📌 Overview

**GPU Review Sentiment Analyzer** is a data processing and sentiment analysis project focused on understanding customer opinions about GPU products.

The project uses a custom-generated dataset containing approximately **3 million GPU review records** stored in **Apache Parquet** format.

The application is being developed in **C++17** with **Apache Arrow** and **Apache Parquet** to efficiently process large-scale columnar data.

The final goal is to build a scalable sentiment analysis pipeline that can classify GPU reviews into:

- Positive
- Neutral
- Negative

and provide useful insights into customer opinions about GPU products.

---

## 🎯 Project Objectives

The main objectives of this project are:

1. Process millions of GPU review records efficiently.
2. Use Apache Parquet for columnar data storage.
3. Use Apache Arrow for efficient C++ data processing.
4. Extract and process review text.
5. Perform sentiment analysis on GPU reviews.
6. Classify reviews into positive, neutral, and negative sentiment.
7. Analyze sentiment patterns across GPU products and categories.
8. Measure the performance of the C++ data processing pipeline.

---

## 🗂️ Dataset

This project uses a **custom-generated synthetic GPU review dataset**.

The dataset was generated specifically for this project and is not copied from an external review dataset.

### Dataset Information

| Property | Value |
|---|---|
| Dataset Type | Synthetic |
| Domain | GPU / Graphics Cards |
| Approximate Records | 3,000,000 |
| File Format | Apache Parquet |
| Number of Columns | 21 |
| Primary Text Field | `review_text` |
| Sentiment Field | `sentiment` |

> **Note:** The dataset is synthetically generated for educational and research purposes.

The full Parquet dataset is intentionally excluded from the Git repository because of its size.

---

## 📊 Dataset Schema

| Column | Type | Description |
|---|---|---|
| `review_id` | string | Unique review identifier |
| `product_id` | string | GPU product identifier |
| `product_name` | string | GPU model/product name |
| `manufacturer` | string | GPU manufacturer |
| `brand` | string | GPU brand |
| `reviewer_id` | string | Reviewer identifier |
| `rating` | int8 | Review rating |
| `review_title` | string | Review title |
| `review_text` | string | Full review text |
| `review_date` | string | Review date |
| `verified_purchase` | bool | Whether the purchase was verified |
| `helpful_votes` | int64 | Number of helpful votes |
| `total_votes` | int64 | Total number of votes |
| `price_usd` | float | GPU price in USD |
| `gpu_category` | string | GPU category |
| `use_case` | string | Intended use case |
| `sentiment` | string | Sentiment label |
| `performance_score` | float | Performance score |
| `temperature_score` | float | Temperature score |
| `noise_score` | float | Noise score |
| `value_score` | double | Value-for-money score |

---

## 🏗️ System Architecture

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
                  C++ Data Reader
                         │
                         ▼
                  Review Text
                         │
                         ▼
                 Text Preprocessing
                         │
                         ▼
                 Sentiment Analysis
                         │
              ┌──────────┼──────────┐
              ▼          ▼          ▼
           Positive    Neutral    Negative
              │          │          │
              └──────────┼──────────┘
                         ▼
                  Review Insights
````

---

## 🛠️ Technology Stack

### Programming Language

* C++17

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

The generated Parquet dataset is stored locally under:

```text
data/gpu_reviews_3m.parquet
```

and is excluded from Git using `.gitignore`.

---

## ⚙️ Current Implementation

The current C++ implementation successfully performs the initial Parquet data-access stage.

### Implemented

* [x] C++17 project setup
* [x] CMake project configuration
* [x] Apache Arrow integration
* [x] Apache Parquet integration
* [x] Parquet file opening
* [x] Parquet reader creation
* [x] Schema loading
* [x] Column inspection
* [x] Data type inspection

### Planned

* [ ] Read Parquet record batches
* [ ] Extract review text
* [ ] Text preprocessing
* [ ] Sentiment analysis
* [ ] Positive / Neutral / Negative classification
* [ ] Sentiment statistics
* [ ] GPU/product-level sentiment analysis
* [ ] Performance benchmarking
* [ ] Large-scale processing optimization
* [ ] Final analytics/reporting

---

## 🚀 Build and Run

### 1. Clone the repository

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

The current implementation successfully loads the dataset schema:

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

---

## 🔬 Sentiment Analysis

The central objective of the project is **sentiment analysis**.

The system will use the `review_text` field as the primary textual input and analyze the expressed opinion of the reviewer.

The target classification is:

```text
Review Text
     │
     ▼
Text Processing
     │
     ▼
Sentiment Analysis
     │
     ├── Positive
     ├── Neutral
     └── Negative
```

The existing `sentiment` column in the generated dataset can also be used as a reference/label during development and evaluation.

---

## 💡 Example Use Cases

The completed system can be used to analyze questions such as:

* Which GPU products receive the most positive reviews?
* Which GPUs have the most negative customer feedback?
* How do users feel about GPU performance?
* How do users feel about GPU temperature?
* How does price/value affect customer sentiment?
* Which GPU categories receive better customer feedback?
* What are the common issues mentioned in negative reviews?

---

## ⚡ Performance Goal

Because the dataset contains approximately **3 million records**, performance is an important part of this project.

The project aims to investigate efficient large-scale data processing using:

* Columnar storage
* Apache Parquet
* Apache Arrow
* C++
* Batch-based processing
* Efficient memory usage
* Parallel processing where appropriate

Performance benchmarking will be added as development progresses.

---

## 🔐 Data and Repository Policy

The complete generated dataset is not committed to GitHub.

The following files are intentionally ignored:

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

## 📚 Educational Purpose

This project is developed as a **sentiment analysis and large-scale data processing project**.

It demonstrates practical use of:

* C++
* Data engineering
* Columnar data formats
* Apache Arrow
* Apache Parquet
* Natural Language Processing
* Sentiment analysis
* Performance-oriented programming

---

## 🚧 Project Status

**Status: Work in Progress**

Current milestone:

> **Successfully reading and inspecting a ~3 million-record GPU review dataset using C++17, Apache Arrow 25.0.1, and Apache Parquet 25.0.1.**

The next major milestone is implementing the actual **review-text extraction and sentiment analysis pipeline**.

---

## 👨‍💻 Author

**Md Abdullah Rajeeb**

GitHub:

[https://github.com/MotionPrograming](https://github.com/MotionPrograming)

````
