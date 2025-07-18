<?php
session_start();
include 'config.php';

if (!isset($_SESSION['user_id'])) {
    header("Location: login.php");
    exit();
}

if (isset($_GET['id'])) {
    $email_id = $_GET['id'];
    $result = $conn->query("SELECT emails.*, users.email AS sender_email FROM emails 
                            JOIN users ON emails.sender_id = users.id WHERE emails.id='$email_id'");

    if ($result->num_rows > 0) {
        $email = $result->fetch_assoc();
    } else {
        echo "Email not found!";
        exit();
    }
} else {
    header("Location: inbox.php");
    exit();
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Read Mail</title>
    <link rel="stylesheet" href="css/style.css">
</head>
<body>
    <div class="container">
        <h2><?= $email['subject'] ?></h2>
        <p><strong>From:</strong> <?= $email['sender_email'] ?></p>
        <p><?= $email['message'] ?></p>
        <a href="inbox.php">Back to Inbox</a> | 
        <a href="delete.php?id=<?= $email['id'] ?>">Delete</a>
    </div>
</body>
</html>