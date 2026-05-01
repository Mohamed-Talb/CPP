#!/bin/bash

EXEC="./RPN"

if [ ! -f "$EXEC" ]; then
    echo "Error: $EXEC not found"
    exit 1
fi

if [ ! -x "$EXEC" ]; then
    echo "Error: $EXEC is not executable"
    echo "Run: chmod +x RPN"
    exit 1
fi

run_test()
{
    input="$1"
    expected="$2"

    output=$($EXEC "$input" 2>&1)

    if [ "$output" = "$expected" ]; then
        echo "✅ PASS: \"$input\" => $output"
    else
        echo "❌ FAIL: \"$input\""
        echo "   Expected: $expected"
        echo "   Got:      $output"
    fi
}

echo "===== VALID TESTS ====="

run_test "1 2 +" "3"
run_test "2 3 *" "6"
run_test "8 4 /" "2"
run_test "9 3 -" "6"
run_test "1 2 3 * +" "7"
run_test "5 1 2 + 4 * + 3 -" "14"
run_test "3 4 + 2 *" "14"
run_test "9 5 2 + *" "63"
run_test "7 2 - 3 *" "15"
run_test "4 2 / 3 +" "5"
run_test "6 2 / 3 + 4 *" "24"
run_test "9 8 * 7 +" "79"
run_test "0 0 +" "0"
run_test "9 9 *" "81"
run_test "9 9 * 9 +" "90"
run_test "1 2 + 3 4 + *" "21"
run_test "8 9 * 9 - 9 - 9 - 4 - 1 +" "42"
run_test "7 7 * 7 -" "42"
run_test "1 2 * 2 / 2 * 2 4 - +" "0"

echo
echo "===== INVALID TESTS ====="

run_test "2 * 2" "Error"
run_test "1 2 + *" "Error"
run_test "* 1 2" "Error"
run_test "1 +" "Error"
run_test "+" "Error"
run_test "1 2" "Error"
run_test "1 2 3 +" "Error"
run_test "(1 + 1)" "Error"
run_test "10 2 +" "Error"
run_test "4 0 /" "Error"
run_test "a b +" "Error"
run_test "1 2 &" "Error"
run_test "" "Error"
run_test "1 2 + +" "Error"
run_test "1 2 3 * + +" "Error"
run_test "1 2 / /" "Error"

echo
echo "Done."