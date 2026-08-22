#include <bits/stdc++.h>

#include <arrow/api.h>
#include <arrow/io/api.h>
#include <parquet/arrow/reader.h>

using namespace std;

int main()
{
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

    // 2. Create Parquet reader
    auto reader_result = parquet::arrow::OpenFile(
        input,
        arrow::default_memory_pool());

    if (!reader_result.ok())
    {
        cerr << "ERROR: Cannot create Parquet reader\n";
        cerr << reader_result.status() << '\n';
        return 1;
    }

    unique_ptr<parquet::arrow::FileReader> reader =
        std::move(reader_result).ValueOrDie();

    cout << "[OK] Parquet reader created\n";

    // 3. Read schema
    shared_ptr<arrow::Schema> schema;

    auto status = reader->GetSchema(&schema);

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
             << field->name()
             << " : "
             << field->type()->ToString()
             << '\n';
    }

    cout << "\n========================================\n";
    cout << "        PARQUET READ SUCCESS\n";
    cout << "========================================\n";

    return 0;
}