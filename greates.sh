#!/bin/bash

# Read two numbers from the user
echo -n "Enter first number: "
read num1
echo -n "Enter second number: "
read num2

# Compare the numbers and print the greatest one
if [ $num1 -gt $num2 ]; then
    echo "$num1 is the greatest."
elif [ $num1 -lt $num2 ]; then
    echo "$num2 is the greatest."
else
    echo "Both numbers are equal."
fi
