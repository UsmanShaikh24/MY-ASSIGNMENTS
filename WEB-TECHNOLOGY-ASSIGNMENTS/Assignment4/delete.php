<?php
include 'db.php';

$id = $_POST['id'];

$sql = "DELETE FROM users WHERE id=$id";
if ($conn->query($sql)) {
    echo "User deleted successfully!";
} else {
    echo "Error: " . $conn->error;
}
?>
