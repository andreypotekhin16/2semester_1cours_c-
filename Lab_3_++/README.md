# Lab 3: User Authentication & Equipment Maintenance Scheduling with MySQL

This project implements two console-based C++ applications:
1.  A system for registration and authorization of production workers.
2.  An automated system for managing the maintenance schedule of production equipment.

This lab utilizes a **MySQL database** for all data persistence, including user credentials, employee information, equipment details, and maintenance logs. This code is written for windows, libraries need to be changed on other operating systems.

This lab is part of the "Programming Lab Assignments (2nd Semester, 1st Year)" collection.

## Part 1: Production Worker Registration and Authorization System

### Objective
To develop an algorithm for creating, saving, and verifying login credentials for each employee, using a MySQL database for robust data management.

### Detailed Tasks (Adapted for MySQL):

1.  **Console Input:** Create a console application that prompts for login and password input.
2.  **Load Registration Data from DB:** Develop a function to load registration data (e.g., hashed password, employee name) for a given login by querying the **MySQL `users` table**.
3.  **Verify Credentials against DB:** Develop a function to check the correctness of user-entered data (login and password) against the data stored in the **MySQL `users` table**. This involves retrieving the stored hashed password and comparing it with a hash of the entered password.
4.  **Registration to DB:** Develop a registration function that inserts a new account (login, hashed password, employee name) as a new record into the **MySQL `users` table**.
5.  **Password Change in DB (Optional):** Develop a function to update the password (stored as a hash) for a specific user in the **MySQL `users` table**.
6.  **Login Attempt Tracking in DB (Optional):** Develop a function to log all login attempts (date, time, entered login, success/failure) by inserting records into a dedicated **MySQL `login_attempts` table**.

### Order of Implementation (Conceptual Flow using MySQL):

*   **Task 1 (Input & Basic Logic):** The program accepts a login and password. Upon correct input (verified against the MySQL database), it displays a welcome message. If incorrect, it clears the console and re-prompts for input.
*   **Task 2 (Data Loading from DB):** This function queries the `users` table in MySQL based on the provided login. It retrieves the stored `password_hash` and `employee_name` for that user.
*   **Task 3 (Verification with DB):** This function takes the entered login and password. It hashes the entered password (using the same algorithm as during registration) and compares it to the `password_hash` retrieved from the database for that login. If they match, it displays a welcome message using the `employee_name`. Otherwise, it clears the console, shows an error message, and re-prompts for input.
*   **Task 4 (Registration to DB):** This function prompts the user for new account details (login, password, name). It hashes the password and then inserts a new record into the `users` table in the MySQL database.
*   **Task 5 (Password Change in DB - Optional):** This function allows an authenticated user to change their password. It prompts for the new password, hashes it, and updates the `password_hash` field for the corresponding user in the `users` table.
*   **Task 6 (Login Attempt Logging to DB - Optional):** This function records each login attempt by inserting a new row into a `login_attempts` table in MySQL, including details like the attempted login, timestamp, and whether the attempt was successful.

---

## Part 2: Automated Equipment Maintenance Schedule

### Objective
To develop a program for on-site monitoring and automated tracking of the equipment maintenance schedule on a production site, leveraging a MySQL database for data storage and retrieval.

### Detailed Tasks (Adapted for MySQL):

1.  **User Interface:** Create a console application that greets the user and offers a choice: add a record of completed work, or view the work schedule for the last week (all data interactions via MySQL).
2.  **Add Work Record to DB:** Develop a function to add a record of completed maintenance work by inserting data into a **MySQL `maintenance_logs` table**.
3.  **View Schedule from DB:** Develop a function to view the work schedule for the last week by querying the **MySQL `maintenance_logs` table** for relevant date ranges.
4.  **Modify Schedule Template in DB (Optional):** Develop a function to change the base equipment schedule/template, which is stored in a **MySQL `equipment` (or similar) table**.

### Order of Implementation (Conceptual Flow using MySQL):

*   **Task 1 (Menu):** The program greets the user and presents options: (1) Add maintenance record, (2) View weekly schedule.
*   **Task 2 (Add Record to DB):**
    *   The user inputs the workshop number and equipment number/ID.
    *   The program first validates if the workshop and equipment ID exist by querying an `equipment` table in MySQL (this table acts as the master list or "template").
    *   If valid, it inserts a new record into a `maintenance_logs` table in MySQL. This record includes a foreign key to the equipment, the service date (current system date), and any relevant notes.
    *   *This database operation replaces any logic of scanning directories for date-named files or copying template files.* The "template" is now the `equipment` table.
*   **Task 3 (View Schedule from DB):**
    *   The program queries the `maintenance_logs` table (possibly joining with the `equipment` table for more details) in MySQL for records where the `service_date` falls within the last 7 days.
    *   It then retrieves and displays this information in a formatted table in the console (e.g., Date, Workshop, Equipment ID, Description, Status/Notes).
    *   *This database query replaces any logic of scanning directories and reading from multiple date-named files.*
*   **Task 4 (Modify Schedule Template in DB - Optional):**
    *   The user might input workshop details, then the number of apparatus and their IDs/descriptions for that workshop.
    *   The program interacts with the `equipment` table in MySQL. It might involve deleting old entries for a workshop and inserting new ones, or updating existing equipment records.
    *   *This database operation replaces the modification of a "file-sample" or template file.*

---

## MySQL Database Integration

This project utilizes a MySQL database for storing all relevant data.

### Example Database Schema:

**For Part 1 (User System):**
*   `users` table:
    *   `id` (INT, Primary Key, Auto Increment)
    *   `login` (VARCHAR(50), Unique, Not Null)
    *   `password_hash` (VARCHAR(255), Not Null)  -- **Store hashed passwords, NOT plain text!**
    *   `employee_name` (VARCHAR(100))
    *   `created_at` (TIMESTAMP, Default CURRENT_TIMESTAMP)
*   `login_attempts` table (Optional):
    *   `id` (INT, Primary Key, Auto Increment)
    *   `attempted_login` (VARCHAR(50))
    *   `attempt_time` (TIMESTAMP, Default CURRENT_TIMESTAMP)
    *   `success` (BOOLEAN)

**For Part 2 (Maintenance Schedule):**
*   `equipment` table (master list of equipment, serves as the "template"):
    *   `id` (INT, Primary Key, Auto Increment)
    *   `workshop_number` (INT, Not Null)
    *   `equipment_identifier` (VARCHAR(50), Not Null) -- e.g., "CNC-001", "Press-B"
    *   `equipment_description` (VARCHAR(255))
    *   UNIQUE constraint on (`workshop_number`, `equipment_identifier`)
*   `maintenance_logs` table:
    *   `log_id` (INT, Primary Key, Auto Increment)
    *   `equipment_id_fk` (INT, Foreign Key referencing `equipment.id`)
    *   `service_date` (DATE, Not Null)
    *   `serviced_by_user_id_fk` (INT, Foreign Key referencing `users.id`, Optional)
    *   `notes` (TEXT)

### Setting up MySQL and C++ Connector:

1.  **Install MySQL Server:** Download and install MySQL Community Server. Remember the root password.
2.  **Install MySQL C++ Connector:** Download the MySQL Connector/C++ suitable for your OS and compiler. This provides header (`.h`, `.hpp`) and library (`.lib`, `.dll`, `.so`, `.dylib`) files.
3.  **Create Database & User (Recommended):**
    *   Using a MySQL client (e.g., MySQL Workbench, `mysql` CLI), connect as root.
    *   `CREATE DATABASE your_lab_db_name;`
    *   Create a dedicated application user:
        ```sql
        CREATE USER 'lab_app_user'@'localhost' IDENTIFIED BY 'your_secure_password';
        GRANT ALL PRIVILEGES ON your_lab_db_name.* TO 'lab_app_user'@'localhost';
        FLUSH PRIVILEGES;
        ```
4.  **Configure your C++ Project (IDE or Makefile):**
    *   **Include Paths:** Add the path to the MySQL Connector/C++ `include` directory.
    *   **Library Paths:** Add the path to the MySQL Connector/C++ `lib` (or `lib64`) directory.
    *   **Link Libraries:** Link against the MySQL Connector/C++ library (e.g., `mysqlcppconn.lib` on Windows, `libmysqlcppconn.so` on Linux).

Clone the repository: git clone https://github.com/andreypotekhin16/2semester_1cours_c-.git


