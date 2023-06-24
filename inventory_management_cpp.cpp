#include <iostream>
#include <vector>

using namespace std;

struct Item 
{
  string name;
  int quantity;
  double price;
};

vector<Item> inventory;

void addItem() 
{
  string name;
  int quantity;
  double price;

  cout << "Enter the item name: ";
  cin >> name;

  cout << "Enter the quantity: ";
  cin >> quantity;

  cout << "Enter the price: ";
  cin >> price;

  inventory.push_back({name, quantity, price});

  cout<<"Successfully inserted item...\n\n";
}

void viewInventory() 
{
    cout << "_________________________________________________\n";
    cout << "| Item name:    | Quantity:     | Price:        |" << endl;
    cout << "|_______________|_______________|_______________|\n";
  for (int i = 0; i < inventory.size(); i++) 
  {
    cout << "|"<<inventory[i].name <<"\t\t|"<<inventory[i].quantity<<"\t\t|"<<inventory[i].price<<"\t\t|"<<endl;
  }
    cout << "|_______________|_______________|_______________|\n\n";
}

void updateItem() 
{
  string name;
  int f = 0;
  cout << "Enter the item name to update: ";
  cin >> name;

  for (int i = 0; i < inventory.size(); i++) 
  {
    if (inventory[i].name == name) 
    {
      cout << "Enter the new quantity: ";
      cin >> inventory[i].quantity;

      cout << "Enter the new price: ";
      cin >> inventory[i].price;
      f = 1;
      cout<<"Successfully updateded item...\n\n";
    }
  }
  if (f==0)
  {
    cout<<"No such item in stock...\n\n";
  }
}

void deleteItem() 
{
  string name;

  cout << "Enter the item name to delete: ";
  cin >> name;

  for (int i = 0; i < inventory.size(); i++) 
  {
    if (inventory[i].name == name) 
    {
      inventory.erase(inventory.begin() + i);
    }
  }
  cout<<"Successfully deleted item...\n\n";
}
void orderItem()
{
  string name;
  int quantity;

  cout << "Enter the item name to order: ";
  cin >> name;
  cout << "Enter the item quantity: ";
  cin >> quantity;
  int f = 0;
  for (int i = 0; i < inventory.size(); i++) 
  {
    if (inventory[i].name == name && inventory[i].quantity >= quantity) 
    {
      inventory[i].quantity = inventory[i].quantity - quantity;
      cout<<"Successfully ordered item...\n\n";
      f = 1;
    }
    else if (inventory[i].name == name && inventory[i].quantity < quantity)
    {
        cout<<"Item is out of stock \n\n";
    }
  }
  if (f==0)
  {
    cout<<"Order Failed...\n\n";
  }

}
int main() 
{
  int choice;

  do 
  {
    cout << "_________________________________________________\n";
    cout << "\t\tINVENTORY MANAGEMENT SYSYEM\n";
    cout << "_________________________________________________\n";
    cout << "1. Add item" << endl;
    cout << "2. View inventory" << endl;
    cout << "3. Update item" << endl;
    cout << "4. Delete item" << endl;
    cout << "5. Order item" << endl;
    cout << "6. Exit" << endl;
    cout << "_________________________________________________\n";

    cin >> choice;

    switch (choice) 
    {
      case 1:
        addItem();
        break;
      case 2:
        viewInventory();
        break;
      case 3:
        updateItem();
        break;
      case 4:
        deleteItem();
        break;
      case 5:
        orderItem();
        break;
      case 6:
        break;
    }
  } while (choice != 6);

  return 0;
}