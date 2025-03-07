#!/bin/bash

make

test_values=(
    "1.17549435e-38F" "3.4028235e+38F" "123.456f" "0.0f" "-0.0f"
    "1e10f" "-1.23e-10F" "1.f" ".1f" "1.17549435e-38" "3.4028235e+38"
    "123.456" "0.0" "-0.0" "1e10" "-1.23e-10" "1." ".1"
    "1.17549435e-38F" "3.4028235e+38F" "123.456f" "0.0f" "1e10f"
    "1.23e-10f" "1.23e-10D" "abc" "1.2.3f" "1.2.3"
)

echo "Testing floats and doubles:"
for value in "${test_values[@]}"; do
    echo "Testing with value: $value"
    ./scalarConverter "$value"
done