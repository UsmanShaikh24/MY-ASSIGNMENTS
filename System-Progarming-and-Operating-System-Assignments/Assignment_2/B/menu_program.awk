#!/bin/bash

# Function to calculate factorial
factorial() {
    echo "Enter a number:"
    read num
    fact=1
    for ((i=1; i<=num; i++)); do
        fact=$((fact * i))
    done
    echo "Factorial of $num is $fact."
}

# Function to find the greatest of three numbers
greatest_of_three() {
    echo "Enter three numbers:"
    read a b c
    awk -v a="$a" -v b="$b" -v c="$c" '
    BEGIN {
        if (a >= b && a >= c) print a " is the greatest."
        else if (b >= a && b >= c) print b " is the greatest."
        else print c " is the greatest."
    }'
}

# Function to check if a number is prime
is_prime() {
    echo "Enter a number:"
    read num
    awk -v num="$num" '
    BEGIN {
        if (num < 2) { print num " is not a prime number."; exit }
        for (i = 2; i * i <= num; i++) {
            if (num % i == 0) { print num " is not a prime number."; exit }
        }
        print num " is a prime number."
    }'
}

# Function to check if a number is a palindrome
is_number_palindrome() {
    echo "Enter a number:"
    read num
    reversed=$(echo "$num" | rev)
    if [[ "$num" == "$reversed" ]]; then
        echo "$num is a palindrome."
    else
        echo "$num is not a palindrome."
    fi
}

# Function to check if a string is a palindrome
is_string_palindrome() {
    echo "Enter a string:"
    read str
    reversed=$(echo "$str" | rev)
    if [[ "$str" == "$reversed" ]]; then
        echo "$str is a palindrome."
    else
        echo "$str is not a palindrome."
    fi
}

# Menu
while true; do
    echo -e "\nMenu-Driven Program"
    echo "a) Find Factorial of a Number"
    echo "b) Find Greatest of Three Numbers"
    echo "c) Check if a Number is Prime"
    echo "d) Check if a Number is Palindrome"
    echo "e) Check if a String is Palindrome"
    echo "f) Exit"
    echo "Enter your choice:"
    read choice

    case $choice in
        a) factorial ;;
        b) greatest_of_three ;;
        c) is_prime ;;
        d) is_number_palindrome ;;
        e) is_string_palindrome ;;
        f) exit ;;
        *) echo "Invalid choice. Please try again." ;;
    esac
done
