<?php
$servername = "localhost"; // Change if using a different database host
$username = "root"; // Default XAMPP MySQL user
$password = ""; // Leave empty if no password is set
$dbname = "mail_app"; // Your database name

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}
?>
