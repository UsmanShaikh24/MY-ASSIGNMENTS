var app = angular.module("libraryApp", []);

app.controller("LibraryController", function ($scope, $http) {
    $scope.books = [];

    // Fetch Books from Backend
    $scope.getBooks = function () {
        $http.get("http://localhost/Projects/Assignment5/api.php?action=getBooks")
            .then(function (response) {
                $scope.books = response.data;
            }, function (error) {
                console.error("Error fetching books:", error);
            });
    };

    // Add Book to Backend
    $scope.addBook = function () {
        var bookData = {
            title: $scope.title,
            author: $scope.author,
            category: $scope.category
        };

        console.log("Sending Book Data:", bookData); // Debug log

        $http.post("http://localhost/Projects/Assignment5/api.php?action=addBook", bookData, {
            headers: { "Content-Type": "application/json" }
        })
        .then(function (response) {
            console.log("Response:", response.data); // Debug log
            alert(response.data.message);

            // Clear input fields after adding a book
            $scope.title = "";
            $scope.author = "";
            $scope.category = "";

            $scope.getBooks(); // Refresh books list
        }, function (error) {
            console.error("Error adding book:", error);
        });
    };

    // Delete Book from Backend
    $scope.deleteBook = function (bookId) {
        $http.post("http://localhost/Projects/Assignment5/api.php?action=deleteBook", { id: bookId }, {
            headers: { "Content-Type": "application/json" }
        })
        .then(function (response) {
            console.log("Delete Response:", response.data);
            alert(response.data.message);
            $scope.getBooks(); // Refresh books list
        }, function (error) {
            console.error("Error deleting book:", error);
        });
    };
});
