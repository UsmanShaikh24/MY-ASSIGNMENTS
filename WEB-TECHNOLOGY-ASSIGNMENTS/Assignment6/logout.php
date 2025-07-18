<?php
session_start();
session_destroy(); // Destroy all sessions
header("Location: login.php"); // Redirect to login page
exit();
?>
