<?php
session_start();
include 'config.php';

if (!isset($_SESSION['user_id'])) {
    header("Location: login.php");
    exit();
}

$user_id = $_SESSION['user_id'];
$result = $conn->query("SELECT emails.id, users.email AS sender_email, subject, sent_at FROM emails 
                        JOIN users ON emails.sender_id = users.id
                        WHERE receiver_id='$user_id' AND is_deleted=0 ORDER BY sent_at DESC");
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Inbox - Mail App</title>
    <link rel="stylesheet" href="css/style.css">
</head>
<body>
    <div class="container">
        <h2>Inbox</h2>
        <a href="compose.php">Compose Mail</a> | <a href="logout.php">Logout</a>
        <ul>
            <?php while ($row = $result->fetch_assoc()) { ?>
                <li><a href="read.php?id=<?= $row['id'] ?>"><?= $row['subject'] ?> from <?= $row['sender_email'] ?></a></li>
            <?php } ?>
        </ul>
    </div>
</body>
</html>