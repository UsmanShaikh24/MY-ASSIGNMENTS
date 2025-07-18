<?php
include 'db.php';

$id = $_POST['id'];
$name = $_POST['name'];
$email = $_POST['email'];
$age = $_POST['age'];

$sql = "UPDATE users SET name='$name', email='$email', age=$age WHERE id=$id";
if ($conn->query($sql)) {
    echo "User updated successfully!";
} else {
    echo "Error: " . $conn->error;
}
?>
