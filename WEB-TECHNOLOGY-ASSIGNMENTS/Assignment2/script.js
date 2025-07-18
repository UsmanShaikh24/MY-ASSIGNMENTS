document.getElementById("registrationForm").addEventListener("submit", function(event) {
    event.preventDefault();
    let isValid = true;

    // Clear previous errors
    document.querySelectorAll(".error").forEach(el => el.textContent = "");

    // Validate Full Name
    const fullName = document.getElementById("fullName").value.trim();
    if (fullName === "") {
        document.getElementById("fullNameError").textContent = "Full Name is required";
        isValid = false;
    }

    // Validate Email
    const email = document.getElementById("email").value.trim();
    const emailPattern = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
    if (!emailPattern.test(email)) {
        document.getElementById("emailError").textContent = "Invalid email format";
        isValid = false;
    }

    // Validate Password
    const password = document.getElementById("password").value.trim();
    const passwordPattern = /^(?=.*[A-Za-z])(?=.*\d)[A-Za-z\d]{6,}$/; // Minimum 6 chars, at least 1 letter and 1 number
    if (!passwordPattern.test(password)) {
        document.getElementById("passwordError").textContent = "Password must be at least 6 characters, contain a letter and a number";
        isValid = false;
    }

    // Validate Confirm Password
    const confirmPassword = document.getElementById("confirmPassword").value.trim();
    if (confirmPassword !== password) {
        document.getElementById("confirmPasswordError").textContent = "Passwords do not match";
        isValid = false;
    }

    // Validate Date of Birth
    if (!document.getElementById("dob").value) {
        document.getElementById("dobError").textContent = "Date of Birth is required";
        isValid = false;
    }

    // Validate Gender
    if (!document.querySelector('input[name="gender"]:checked')) {
        document.getElementById("genderError").textContent = "Gender is required";
        isValid = false;
    }

    // Validate Membership Type
    if (!document.getElementById("membership").value) {
        document.getElementById("membershipError").textContent = "Membership Type is required";
        isValid = false;
    }

    // Validate Address
    if (document.getElementById("address").value.trim() === "") {
        document.getElementById("addressError").textContent = "Address is required";
        isValid = false;
    }

    // Validate Phone Number
    const phone = document.getElementById("phone").value.trim();
    const phonePattern = /^\d{10}$/;
    if (!phonePattern.test(phone)) {
        document.getElementById("phoneError").textContent = "Invalid phone number (must be 10 digits)";
        isValid = false;
    }

    // Validate Terms & Conditions
    if (!document.getElementById("terms").checked) {
        document.getElementById("termsError").textContent = "You must agree to the terms";
        isValid = false;
    }

    if (isValid) {
        alert("Registration Successful!");
        document.getElementById("registrationForm").reset();
    }
});
