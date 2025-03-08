#!/bin/bash

test_values=(
    # char
    "a" "Z" "0" "9" "!" " " "\n" "ab" "" "1" "A"

    # int
    "0" "42" "-42" "2147483647" "-2147483648" "2147483648" "-2147483649" "123abc" "abc123"

    # float
    "1.17549435e-38F" "3.4028235e+38F" "123.456f" "0.0f" "-0.0f"
    "1e10f" "-1.23e-10F" "1.f" ".1f" "1.17549435e-38F" "3.4028235e+38F"
    "123.456f" "0.0f" "1e10f" "1.23e-10f" "1.23e-10D" "abc" "1.2.3f" "1.2.3"

    # double
    "1.17549435e-38" "3.4028235e+38" "123.456" "0.0" "-0.0"
    "1e10" "-1.23e-10" "1." ".1" "1.17549435e-38" "3.4028235e+38"
    "123.456" "0.0" "1e10" "1.23e-10" "1.23e-10D" "abc" "1.2.3"

    # double, out of range for float
    "3.4028235e+39" "-3.4028235e+39" 
    
    # double max and double min
    "1.7976931348623158e+308" "-1.7976931348623158e+308"

    # out of range of double max, double min resp.
    "1.7976931348623158e+309" "-1.7976931348623158e+309"
    
    # out of range of float (underflow)
    "1.17549435e-39" "-1.17549435e-39"
)

for value in "${test_values[@]}"; do
    echo
    echo "Testing with value: $value"
    ./scalarConverter "$value"
done