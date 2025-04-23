<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <title>🎬 Movie Ticket Booking System in C</title>
  <style>
    body {
      font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
      background-color: #f9f9f9;
      color: #2c3e50;
      padding: 40px;
      line-height: 1.7;
    }

    h1, h2, h3 {
      color: #1a1a1a;
    }

    h1 {
      font-size: 2.2em;
      margin-bottom: 20px;
    }

    h2 {
      margin-top: 40px;
      color: #34495e;
    }

    h3 {
      margin-top: 30px;
      color: #3b3b3b;
    }

    ul {
      padding-left: 20px;
    }

    li {
      margin-bottom: 8px;
    }

    p {
      margin: 10px 0;
    }

    strong {
      color: #2c3e50;
    }

    code {
      background-color: #eee;
      padding: 3px 6px;
      border-radius: 5px;
      font-family: Consolas, monospace;
    }
  </style>
</head>
<body>

  <h1>🎬 Movie Ticket Booking System in C</h1>

  <h2>📌 Introduction</h2>
  <p>
    The <strong>Movie Ticket Booking System</strong> is a simple console-based C application that enables users to 
    sign up, log in, browse available movies, check seat availability, book or cancel tickets, and make payments.
    It aims to replicate the core functionality of an actual movie booking system in a command-line environment.
  </p>

  <h2>🎯 Objective</h2>
  <p>
    To develop an easy-to-use system that helps users book movie tickets, manage available seats, and simulate basic payments—all in a CLI-based environment.
  </p>

  <h2>✅ Features Implemented</h2>

  <h3>🔐 User Sign-Up and Login</h3>
  <ul>
    <li>Account creation with username and password</li>
    <li>Login system with limited login attempts and validation</li>
  </ul>

  <h3>🎞️ Movie Management</h3>
  <ul>
    <li>Preloaded movie database with showtime, rating, and price</li>
    <li>Option to search movies by ID</li>
    <li>Display all movies currently available</li>
  </ul>

  <h3>🎟️ Ticket Booking and Seat Management</h3>
  <ul>
    <li>View available seats for a movie</li>
    <li>Book multiple seats (up to 50)</li>
    <li>Cancel a booked seat if needed</li>
  </ul>

  <h3>💳 Payment Module</h3>
  <ul>
    <li>Supports basic payment types: Credit, Debit, Wallet</li>
    <li>Simulates transaction with validation steps</li>
  </ul>

  <h2>🛠️ Tools and Technologies Used</h2>
  <ul>
    <li><strong>Language:</strong> C</li>
    <li><strong>Compiler:</strong> GCC</li>
    <li><strong>Interface:</strong> Command Line (Terminal)</li>
  </ul>

  <h2>📊 Data Structures Used</h2>
  <ul>
    <li><strong>Linked List:</strong> For dynamic movie management</li>
    <li><strong>Arrays:</strong> For managing seat availability</li>
  </ul>

  <h2>👍 Advantages</h2>
  <ul>
    <li>Simple and intuitive interface</li>
    <li>Efficient memory usage using dynamic structures</li>
    <li>Replicates a real-life booking process effectively</li>
  </ul>

  <h2>⚠️ Limitations</h2>
  <ul>
    <li>No graphical user interface</li>
    <li>No file or database storage — data is lost after exit</li>
    <li>Only works within terminal/command line</li>
  </ul>

  <h2>👨‍💻 Author</h2>
  <p><strong>Jackson Shaji</strong></p>

</body>
</html>
