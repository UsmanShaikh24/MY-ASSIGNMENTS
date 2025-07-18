<?php
session_start();
include 'config.php';

if (!isset($_SESSION['user_id'])) {
    header("Location: login.php");
    exit();
}

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $receiver_email = $_POST['receiver_email'];
    $subject = $_POST['subject'];
    $message = $_POST['message'];
    $sender_id = $_SESSION['user_id'];

    // Get receiver ID
    $receiver_result = $conn->query("SELECT id FROM users WHERE email='$receiver_email'");
    if ($receiver_result->num_rows > 0) {
        $receiver_row = $receiver_result->fetch_assoc();
        $receiver_id = $receiver_row['id'];

        // Insert email into database
        $conn->query("INSERT INTO emails (sender_id, receiver_id, subject, message, sent_at) 
                      VALUES ('$sender_id', '$receiver_id', '$subject', '$message', NOW())");
        echo "Email Sent Successfully!";
    } else {
        echo "Recipient not found!";
    }
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Compose Mail</title>
    <link rel="stylesheet" href="css/style.css">
</head>
<body>
    <div class="container">
        <h2>Compose Mail</h2>
        <form method="post">
            <label>To (Email):</label>
            <input type="email" name="receiver_email" required>
            <label>Subject:</label>
            <input type="text" name="subject" required>
            <label>Message:</label>
            <textarea name="message" required></textarea>
            <button type="submit">Send</button>
        </form>
        <a href="inbox.php">Back to Inbox</a>
    </div>
</body>
</html>