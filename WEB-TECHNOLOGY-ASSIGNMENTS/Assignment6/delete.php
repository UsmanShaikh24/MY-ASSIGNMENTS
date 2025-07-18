<?php
session_start();
include 'config.php';

if (!isset($_SESSION['user_id'])) {
    header("Location: login.php");
    exit();
}

if (isset($_GET['id'])) {
    $email_id = $_GET['id'];
    $conn->query("UPDATE emails SET is_deleted=1 WHERE id='$email_id'");
}

header("Location: inbox.php");
exit();
?>