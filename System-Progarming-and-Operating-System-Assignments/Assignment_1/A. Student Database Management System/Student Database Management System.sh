#!/bin/bash

# File to store the database
DB_FILE="student_database.txt"

# Create a database
create_database() {
    > $DB_FILE
    echo "Database created successfully!"
}

# View the database
view_database() {
    if [[ -s $DB_FILE ]]; then
        echo "Student Database:"
        cat $DB_FILE
    else
        echo "Database is empty."
    fi
}

# Insert a record
insert_record() {
    read -p "Enter Student Name: " name
    read -p "Enter Roll Number: " roll
    read -p "Enter Marks: " marks
    echo "$roll:$name:$marks" >> $DB_FILE
    echo "Record inserted successfully!"
}

# Delete a record
delete_record() {
    read -p "Enter Roll Number to delete: " roll
    sed -i "/^$roll:/d" $DB_FILE
    echo "Record deleted successfully!"
}

# Modify a record
modify_record() {
    read -p "Enter Roll Number to modify: " roll
    sed -i "/^$roll:/d" $DB_FILE
    echo "Enter new details:"
    insert_record
}

# Result of a particular student
view_result() {
    read -p "Enter Roll Number: " roll
    grep "^$roll:" $DB_FILE || echo "Record not found."
}

while true; do
    echo -e "\n1. Create Database\n2. View Database\n3. Insert Record"
    echo "4. Delete Record\n5. Modify Record\n6. View Result\n7. Exit"
    read -p "Enter your choice: " choice
    case $choice in
        1) create_database ;;
        2) view_database ;;
        3) insert_record ;;
        4) delete_record ;;
        5) modify_record ;;
        6) view_result ;;
        7) exit 0 ;;
        *) echo "Invalid choice!" ;;
    esac
done
