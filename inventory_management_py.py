import mysql.connector
from prettytable import PrettyTable

conn = mysql.connector.connect(
    host="localhost",
    user="Inv",
    password="1111",
    database="inventory"
)

cursor = conn.cursor()

def create_table(conn):
    cursor.execute("DROP TABLE IF EXISTS inventory")
    cursor.execute("CREATE TABLE inventory (item_id INT AUTO_INCREMENT PRIMARY KEY, item_name VARCHAR(255), price FLOAT, quantity INT)")
    conn.commit()

def addItem(item_name, quantity, price):
    cursor.execute("INSERT INTO inventory (item_name, quantity, price) VALUES (%s, %s, %s)", (item_name, quantity, price))
    conn.commit()
    print("Item is added successfully...\n\n")

def updateItem(item_id, new_quantity):
    query = "UPDATE inventory SET quantity = %s WHERE item_id = %s"
    values = (new_quantity, item_id)
    cursor.execute(query, values)
    conn.commit()
    print("Item is updated successfully...\n\n")

def deleteItem(item_id):
    query = "DELETE FROM inventory WHERE item_id = %s"
    values = (item_id,)
    cursor.execute(query, values)
    conn.commit()
    print("Item is deleted successfully...\n\n")

def viewItem(item_id):
    query = "SELECT * FROM inventory WHERE item_id = %s"
    values = (item_id,)
    cursor.execute(query, values)
    return cursor.fetchone()

def viewInventory():
    query = "SELECT * FROM inventory"
    cursor.execute(query)
    return cursor.fetchall()

create_table(conn)

while True:
    print("_________________________________________________________")
    print("\n\t\t Inventory Management Menu \t\t")
    print("_________________________________________________________\n")
    print("1. Add item")
    print("2. Update item")
    print("3. Delete item")
    print("4. View item")
    print("5. View inventory")
    print("6. Exit")
    print("_________________________________________________________\n")

    choice = input("Enter your choice: ")

    if choice == "1":
        item_name = input("Enter item name: ")
        quantity = int(input("Enter quantity: "))
        price = float(input("Enter price: "))
        addItem(item_name, quantity, price)

    elif choice == "2":
        item_id = int(input("Enter item ID: "))
        new_quantity = int(input("Enter new quantity: "))
        updateItem(item_id, new_quantity)

    elif choice == "3":
        item_id = int(input("Enter item ID: "))
        deleteItem(item_id)

    elif choice == "4":
        item_id = int(input("Enter item ID: "))
        item = viewItem(item_id)
        if item:
            print("Item Details:")
            print("ID:", item[0])
            print("Name:", item[1])
            print("Quantity:", item[2])
            print("Price:", item[3])
        else:
            print("Item not found...")

    elif choice == "5":
        items = viewInventory()
        if items:
            table = PrettyTable()
            table.field_names = ["ID", "Name", "Quantity", "Price"]
            for item in items:
                table.add_row(item)
            print(table)
        else:
            print("No items found...")

    elif choice == "6":
        break

    else:
        print("Invalid choice!\n Enter your choice as [1/2/3/4/5/6]")

cursor.close()
conn.close()
