import tkinter as tk
from tkinter import messagebox, simpledialog
import mysql.connector

# Connect to MySQL Database
def create_db_connection():
    try:
        conn = mysql.connector.connect(
            host='localhost',
            user='root',  # replace with your MySQL username
            password='1234567890',  # replace with your MySQL password
            database='edufinder'
        )
        return conn
    except Exception as e:
        messagebox.showerror("Error", "Failed to connect to database")
        print(e)

# Check login credentials
def check_login(username, password, user_type):
    conn = create_db_connection()
    cursor = conn.cursor()
    if user_type == "admin":
        cursor.execute("SELECT * FROM admin WHERE admin_id = %s AND PWD = %s", (username, password))
    else:  # student
        cursor.execute("SELECT * FROM logins WHERE user_id= %s AND paswrd = %s AND user_type = 'student'", (username, password))
    result = cursor.fetchone()
    cursor.close()
    conn.close()
    return result

# Main Application Class
class EduFinderApp:
    def _init_(self, root):
        self.root = root
        self.root.title("EDUFINDER Login")
        self.root.geometry("300x200")

        # Username
        tk.Label(self.root, text="Username:").pack()
        self.username = tk.Entry(self.root)
        self.username.pack()

        # Password
        tk.Label(self.root, text="Password:").pack()
        self.password = tk.Entry(self.root, show="*")
        self.password.pack()

        # Buttons
        tk.Button(self.root, text="Login as Admin", command=self.admin_login).pack()
        tk.Button(self.root, text="Login as Student", command=self.student_login).pack()

    def admin_login(self):
        user = self.username.get()
        pwd = self.password.get()
        if check_login(user, pwd, "admin"):
            self.open_admin_window()
        else:
            messagebox.showerror("Login failed", "Incorrect username or password")

    def student_login(self):
        user = self.username.get()
        pwd = self.password.get()
        if check_login(user, pwd, "student"):
            self.open_student_window()
        else:
            messagebox.showerror("Login failed", "Incorrect username or password")

    def open_admin_window(self):
        admin_window = tk.Toplevel(self.root)
        admin_window.title("Admin Dashboard")
        admin_window.geometry("400x400")
        tk.Label(admin_window, text="Admin Dashboard", font=('Helvetica', 16)).pack(pady=20)

        # Button Frame (To organize the buttons neatly)
        button_frame = tk.Frame(admin_window)
        button_frame.pack(pady=20)

        tk.Button(button_frame, text="Add College", command=add_college_gui).grid(row=0, column=0, padx=10, pady=5)
        tk.Button(button_frame, text="Delete College", command=delete_college_gui).grid(row=0, column=1, padx=10, pady=5)
        tk.Button(button_frame, text="Search College", command=search_college_gui).grid(row=0, column=2, padx=10, pady=5)
        tk.Button(button_frame, text="Update College Record", command=self.update_college_gui).grid(row=1, column=0, columnspan=3, pady=5) 
        tk.Button(button_frame, text="View All Colleges", command=self.view_all_colleges).grid(row=2, column=0, columnspan=3, pady=5)

   

    def open_student_window(self):
        student_window = tk.Toplevel(self.root)
        student_window.title("Student Dashboard")
        student_window.geometry("400x400")
        tk.Label(student_window, text="Student Dashboard", font=('Helvetica', 16)).pack(pady=20)
        tk.Label(student_window, text="Welcome to Your Dashboard", font=('Helvetica', 16)).pack(pady=20)

        tk.Button(student_window, text="Search College by Name", command=self.search_college_by_name_gui).pack(pady=10)
        tk.Button(student_window, text="Search College by Exam", command=self.search_college_by_exam_gui).pack(pady=10)
        tk.Button(student_window, text="View Profile", command=lambda: self.view_student_profile(student_window)).pack(pady=10)

    def search_college_by_name_gui(self):
        college_name = simpledialog.askstring("Input", "Enter college name:")
        if college_name:
            results = search_college(college_name)
            if results:
                result_str = "\n".join([f"Name: {row[0]}, Fee: {row[1]}" for row in results])
                messagebox.showinfo("Search Results", result_str)


    def search_college_by_exam_gui(self):
        exam_name = simpledialog.askstring("Input", "Enter exam name:")
        if exam_name:
            results = search_college_by_exam(exam_name)
            if results:
                result_str = "\n".join([f"College_name: {row[3]}, college_id: {row[2]}, MIN_MARK: {row[1]}" for row in results])
                messagebox.showinfo("Search Results", result_str)
            else:
                messagebox.showinfo("No Results", "No colleges found for the given exam.")


    def view_student_profile(self, parent_window):
        user_id = self.username.get()
        profile = fetch_student_profile(user_id)
        if profile:
            display_str = f"ID: {profile[0]}\nName: {profile[1]}\nAddress: {profile[2]}\nContact: {profile[3]}\nDOB: {profile[4]}"
            messagebox.showinfo("Student Profile", display_str, parent=parent_window)
        else:
            messagebox.showinfo("Student Profile", "No profile available to display.", parent=parent_window)
  

    def update_college_gui(self):
        update_window = tk.Toplevel(self.root)
        update_window.title("Update College Details")
        update_window.geometry("300x300")

        # Entry Widgets to accept new values
        tk.Label(update_window, text="College ID:").pack(pady=(10, 0))
        college_id_entry = tk.Entry(update_window)
        college_id_entry.pack(pady=(0, 10))

        tk.Label(update_window, text="New College Name:").pack()
        college_name_entry = tk.Entry(update_window)
        college_name_entry.pack(pady=10)

        tk.Label(update_window, text="New Fee Details:").pack()
        fee_details_entry = tk.Entry(update_window)
        fee_details_entry.pack(pady=10)

        tk.Label(update_window, text="New Mark Required:").pack()
        mark_required_entry = tk.Entry(update_window)
        mark_required_entry.pack(pady=10)

        # Button to perform update
        tk.Button(update_window, text="Update College", command=lambda: self.perform_update(
            college_id_entry.get(),
            college_name_entry.get(),
            fee_details_entry.get(),
            mark_required_entry.get(),
            update_window)).pack(pady=20)

def perform_update(self, college_id, college_name, fee_details, mark_required, window):
        # Placeholder: Update logic for your data
        # For now, we just print the values to console to simulate the update
        print(f"Update ID: {college_id}")
        print(f"Update Name: {college_name}")
        print(f"Update Fee Details: {fee_details}")
        print(f"Update Mark Required: {mark_required}")
        
        # Here you would typically update the database or data structure
        # For this example, let's just show a message box
        messagebox.showinfo("Update Successful", "The college record has been updated successfully.")
        window.destroy()  # Close the update window after update

def view_all_colleges(self):
        colleges = fetch_all_colleges()
        if colleges:
            display_str = "\n".join([f"Name: {row[0]}, Fee: {row[1]}, Mark Required: {row[2]}, College ID: {row[3]}" for row in colleges])
            messagebox.showinfo("All Colleges", display_str)
        else:
            messagebox.showinfo("All Colleges", "No colleges available to display.")
  

   # Admin Functions
def add_college(college_name, fee, mark_required, COLLEGE_ID):  # Add any other necessary columns
    conn = create_db_connection()
    if conn:
        cursor = conn.cursor()
        try:
            cursor.execute("""
                INSERT INTO college_record (ADD_COLLEGE, FEE_DETAILS, mark_required, COLLEGE_ID) 
                VALUES (%s, %s, %s, %s)""",  
                (college_name, fee, mark_required, COLLEGE_ID))  
            conn.commit()
            messagebox.showinfo("Success", "College added successfully!")
        except mysql.connector.Error as err:
            messagebox.showerror("Error", f"Failed to add college: {err}")
        finally:
            cursor.close()
            conn.close()

def delete_college(COLLEGE_ID):
    conn = create_db_connection()
    if conn:
        cursor = conn.cursor()
        try:
            if messagebox.askokcancel("Confirm", f"Are you sure you want to delete {COLLEGE_ID}?"):
                cursor.execute("DELETE FROM college_record WHERE COLLEGE_ID = %s", (COLLEGE_ID,))
                conn.commit()
                messagebox.showinfo("Success", "College deleted successfully!")
        except mysql.connector.Error as err:
            messagebox.showerror("Error", f"Failed to delete college: {err}")
        finally:
            cursor.close()
            conn.close()

def search_college(college_name):
    conn = create_db_connection()
    if conn:
        cursor = conn.cursor()
        try:
            cursor.execute("SELECT * FROM college_record WHERE add_college = %s", (college_name,))
            result = cursor.fetchall()
            if result:
                return result
            else:
                messagebox.showinfo("Result", "No college found with that name.")
                return None
        finally:
            cursor.close()
            conn.close()

def search_college_by_exam(exam_name):
    conn = create_db_connection()
    if conn:
        cursor = conn.cursor()
        try:
            cursor.execute("SELECT * FROM exam_name WHERE exam_name = %s", (exam_name,))
            results = cursor.fetchall()
            if results:
                return results
            else:
                messagebox.showinfo("Result", "No colleges found for the given exam.")
                return None
        except mysql.connector.Error as err:
            messagebox.showerror("Error", f"Failed to search for colleges by exam: {err}")
        finally:
            cursor.close()
            conn.close()


def fetch_all_colleges():
    conn = create_db_connection()
    if conn:
        cursor = conn.cursor()
        try:
            cursor.execute("SELECT * FROM college_record")
            colleges = cursor.fetchall()
            return colleges
        except mysql.connector.Error as err:
            messagebox.showerror("Error", f"Failed to fetch colleges: {err}")
            return None
        finally:
            cursor.close()
            conn.close()

def fetch_student_profile(self, student_id):
        conn = create_db_connection()
        if conn:
            cursor = conn.cursor()
            try:
                cursor.execute("SELECT student_id, student_name, student_address, student_contact, DOB FROM students")
                profile = cursor.fetchone()
                return profile
            except mysql.connector.Error as err:
                messagebox.showerror("Error", f"Failed to fetch student profile: {err}")
                return None
            finally:
                cursor.close()
                conn.close()





# GUI Functions
def add_college_gui():
    college_name = simpledialog.askstring("Input", "Enter college name:")
    fee = simpledialog.askstring("Input", "Enter fee:")

    mark_required = simpledialog.askstring("Input", "Enter mark required:")
    mark_required = int(mark_required)  # Convert to integer here

    college_id= simpledialog.askstring("Input", "Enter college_id:")
    

    if college_name and fee and mark_required and college_id:
        add_college(college_name, fee, mark_required, college_id) 




def delete_college_gui():
    college_name = simpledialog.askstring("Input", "Enter college name to delete:")
    if college_name:
        delete_college(college_name)

def search_college_gui():
    college_name = simpledialog.askstring("Input", "Enter college name to search:")
    if college_name:
        results = search_college(college_name)
        if results:
            result_str = "\n".join([f"Name: {row[0]}, Fee: {row[1]},COLLEGE_ID:{row[3]}" for row in results])
            messagebox.showinfo("Search Results", result_str)


def search_college_by_name_gui(self):
    college_name = simpledialog.askstring("Input", "Enter college name:")
    if college_name:
        results = search_college(college_name)
        if results:
            result_str = "\n".join([f"Name: {row[0]}, Fee: {row[1]}, MIN_MARK: {row[2]}, college_id: {row[3]}" for row in results])
            messagebox.showinfo("Search Results", result_str)
        else:
            messagebox.showinfo("Search Results", "No results found.")

def search_college_by_exam_gui():
    exam_name = simpledialog.askstring("Input", "Enter exam name:")
    if exam_name:
        results = search_college_by_exam(exam_name)
        if results:
            result_str = "\n".join([f"College: {row[0]}, Fee: {row[1]}" for row in results])
            messagebox.showinfo("Search Results", result_str)

def fetch_student_profile(student_id):
    conn = create_db_connection()
    if conn:
        cursor = conn.cursor()
        try:
            cursor.execute("SELECT * FROM students WHERE student_id = %s", (student_id,))
            profile = cursor.fetchone()
            return profile
        finally:
            cursor.close()
            conn.close()

# Continue with EduFinderApp class to integrate these functions

if _name_ == "_main_":
    root = tk.Tk()
    app = EduFinderApp(root)
    root.mainloop()