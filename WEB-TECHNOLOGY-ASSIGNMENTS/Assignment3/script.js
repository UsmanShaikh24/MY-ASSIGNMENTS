$(document).ready(function() {
    $("#registrationForm").submit(function(event) {
        event.preventDefault(); // Prevent form submission

        $(".error").text(""); // Clear previous error messages
        let isValid = true;

        // Name validation
        let name = $("#name").val().trim();
        if (name === "") {
            $("#nameError").text("Full Name is required.");
            isValid = false;
        }

        // Email validation
        let email = $("#email").val().trim();
        let emailPattern = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
        if (!emailPattern.test(email)) {
            $("#emailError").text("Enter a valid email.");
            isValid = false;
        }

        // Password validation
        let password = $("#password").val();
        if (password.length < 6) {
            $("#passwordError").text("Password must be at least 6 characters.");
            isValid = false;
        }

        // Confirm Password validation
        let confirmPassword = $("#confirmPassword").val();
        if (confirmPassword !== password) {
            $("#confirmPasswordError").text("Passwords do not match.");
            isValid = false;
        }

        // Submit if valid
        if (isValid) {
            alert("Registration Successful!");
            $("#registrationForm")[0].reset(); // Reset the form
        }
    });
});
