#!/bin/bash
num=$1
sum=0
while ((num > 0)); do
    sum=$((sum + num % 10))
    num=$((num / 10))
done
echo "Sum of digits: $sum"
