#!/bin/bash

factorial() {
    read -p "Enter a number: " num
    fact=1
    for ((i=1; i<=num; i++)); do
        fact=$((fact * i))
    done
    echo "Factorial of $num is $fact"
}

greatest_of_three() {
    read -p "Enter three numbers: " a b c
    if ((a > b && a > c)); then
        echo "$a is the greatest"
    elif ((b > c)); then
        echo "$b is the greatest"
    else
        echo "$c is the greatest"
    fi
}

check_prime() {
    read -p "Enter a number: " num
    is_prime=1
    for ((i=2; i<=num/2; i++)); do
        if ((num % i == 0)); then
            is_prime=0
            break
        fi
    done
    if ((is_prime)); then
        echo "$num is a prime number"
    else
        echo "$num is not a prime number"
    fi
}

number_palindrome() {
    read -p "Enter a number: " num
    rev=$(echo $num | rev)
    if [[ $num == $rev ]]; then
        echo "$num is a palindrome"
    else
        echo "$num is not a palindrome"
    fi
}

string_palindrome() {
    read -p "Enter a string: " str
    rev=$(echo $str | rev)
    if [[ $str == $rev ]]; then
        echo "$str is a palindrome"
    else
        echo "$str is not a palindrome"
    fi
}

while true; do
    echo -e "\n1. Factorial\n2. Greatest of Three\n3. Prime Number"
    echo "4. Number Palindrome\n5. String Palindrome\n6. Exit"
    read -p "Enter your choice: " choice
    case $choice in
        1) factorial ;;
        2) greatest_of_three ;;
        3) check_prime ;;
        4) number_palindrome ;;
        5) string_palindrome ;;
        6) exit 0 ;;
        *) echo "Invalid choice!" ;;
    esac
done
