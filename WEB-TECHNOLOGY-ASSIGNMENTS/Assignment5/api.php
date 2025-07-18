<?php
header("Access-Control-Allow-Origin: *");
header("Access-Control-Allow-Methods: GET, POST");
header("Access-Control-Allow-Headers: Content-Type");
header("Content-Type: application/json");

include 'db.php';

// Get action from URL
$action = isset($_GET['action']) ? $_GET['action'] : '';

// Fetch Books
if ($_SERVER["REQUEST_METHOD"] === "GET" && $action === "getBooks") {
    $sql = "SELECT * FROM books";
    $result = $conn->query($sql);
    $books = [];

    while ($row = $result->fetch_assoc()) {
        $books[] = $row;
    }
    echo json_encode($books);
    exit;
}

// Add a Book
if ($_SERVER["REQUEST_METHOD"] === "POST" && $action === "addBook") {
    $data = json_decode(file_get_contents("php://input"), true);

    if (!isset($data["title"]) || !isset($data["author"]) || !isset($data["category"])) {
        echo json_encode(["message" => "Missing fields"]);
        exit;
    }

    $title = $conn->real_escape_string($data["title"]);
    $author = $conn->real_escape_string($data["author"]);
    $category = $conn->real_escape_string($data["category"]);

    $sql = "INSERT INTO books (title, author, category) VALUES ('$title', '$author', '$category')";
    
    if ($conn->query($sql) === TRUE) {
        echo json_encode(["message" => "Book added successfully"]);
    } else {
        echo json_encode(["message" => "Error adding book: " . $conn->error]);
    }
    exit;
}

// Delete a Book
if ($_SERVER["REQUEST_METHOD"] === "POST" && $action === "deleteBook") {
    $data = json_decode(file_get_contents("php://input"), true);

    if (!isset($data["id"])) {
        echo json_encode(["message" => "Missing book ID"]);
        exit;
    }

    $id = $conn->real_escape_string($data["id"]);
    $sql = "DELETE FROM books WHERE id = $id";

    if ($conn->query($sql) === TRUE) {
        echo json_encode(["message" => "Book deleted successfully"]);
    } else {
        echo json_encode(["message" => "Error deleting book: " . $conn->error]);
    }
    exit;
}

// Default Response
echo json_encode(["message" => "Invalid request"]);
?>
