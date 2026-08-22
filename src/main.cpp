#include <bits/stdc++.h>

#include <arrow/api.h>
#include <arrow/io/api.h>
#include <parquet/arrow/reader.h>
#include <parquet/exception.h>

using namespace std;

int main()
{
    // Colab বা স্থানীয় সঠিক পাথ ব্যবহার করো
    const string file_path = "data/gpu_reviews_3m.parquet";

    cout << "========================================\n";
    cout << "       C++ PARQUET READER TEST\n";
    cout << "========================================\n";
    cout << "File: " << file_path << "\n\n";

    // 1. Open file
    auto input_result = arrow::io::ReadableFile::Open(file_path);
    if (!input_result.ok())
    {
        cerr << "ERROR: Cannot open file\n";
        cerr << input_result.status() << '\n';
        return 1;
    }
    shared_ptr<arrow::io::ReadableFile> input = *input_result;
    cout << "[OK] File opened\n";

    // 2. Create Parquet reader using FileReaderBuilder (Standard & Modern C++ API)
    parquet::arrow::FileReaderBuilder builder;
    builder.Open(input);

    unique_ptr<parquet::arrow::FileReader> reader;
    auto status = builder.Build(&reader);

    if (!status.ok())
    {
        cerr << "ERROR: Cannot create Parquet reader\n";
        cerr << status << '\n';
        return 1;
    }
    cout << "[OK] Parquet reader created\n";

    // 3. Read schema
    shared_ptr<arrow::Schema> schema;
    status = reader->GetSchema(&schema);

    if (!status.ok())
    {
        cerr << "ERROR: Cannot read schema\n";
        cerr << status << '\n';
        return 1;
    }
    cout << "[OK] Schema loaded\n\n";

    // 4. Print schema
    cout << "========================================\n";
    cout << "                 SCHEMA\n";
    cout << "========================================\n";
    cout << schema->ToString() << '\n';

    // 5. Print columns
    cout << "\n========================================\n";
    cout << "                COLUMNS\n";
    cout << "========================================\n";

    for (int i = 0; i < schema->num_fields(); ++i)
    {
        const auto &field = schema->field(i);
        cout << "[" << i << "] "
             << field->name() << " : "
             << field->type()->ToString() << '\n';
    }

    cout << "\n========================================\n";
    cout << "        PARQUET READ SUCCESS\n";
    cout << "========================================\n";

    return 0;
}