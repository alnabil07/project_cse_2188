#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

class Product
{
public:
    int id;
    string name;
    double price;
    int quantity;

    Product(int id, const string &name, double price, int quantity)
        : id(id), name(name), price(price), quantity(quantity) {}

    void displayProduct() const
    {
        cout << setw(5) << id << setw(20) << name << setw(10) << price << setw(8) << quantity << endl;
    }
};

class Supermarket
{
private:
    vector<Product> cart;
    vector<Product> products;
    string filename;
    string username = "Admin", password = "admin";

    void loadProductsFromFile();
    void saveProductsToFile();
    Product *findProductById(int productId);
    void displayProductDetails(const Product &product) const;

public:
    Supermarket(const string &filename) : filename(filename)
    {
        loadProductsFromFile();
    }
    int check(string uname, string pass)
    {
        if (uname == username && pass == password)
        {
            return 1;
        }
    }
    void addProduct();
    void editProduct();
    void deleteProduct();

    void browseProducts();
    void addToCart();
    void removeFromCart();
    void viewCart();
    void checkout();
};

void Supermarket::loadProductsFromFile()
{
    ifstream file(filename);
    if (!file)
    {
        cout << "Error opening file." << endl;
        return;
    }

    int id, quantity;
    double price;
    string name;

    while (file >> id >> name >> price >> quantity)
    {
        products.emplace_back(id, name, price, quantity);
    }

    file.close();
}

void Supermarket::saveProductsToFile()
{
    ofstream file(filename);
    if (!file)
    {
        cout << "Error opening file." << endl;
        return;
    }

    for (const auto &product : products)
    {
        file << product.id << " " << product.name << " " << product.price << " " << product.quantity << "\n";
    }

    file.close();
}

Product *Supermarket::findProductById(int productId)
{
    for (auto &product : products)
    {
        if (product.id == productId)
        {
            return &product;
        }
    }
    return nullptr;
}

void Supermarket::displayProductDetails(const Product &product) const
{
    cout << "Product ID: " << product.id << endl;
    cout << "Name: " << product.name << endl;
    cout << "Price: " << product.price << endl;
    cout << "Available Quantity: " << product.quantity << endl;
}

void Supermarket::addProduct()
{
    int id, quantity;
    double price;
    string name;

    cout << "\nEnter Product ID: ";
    cin >> id;

    if (findProductById(id) != nullptr)
    {
        cout << "Product with ID " << id << " already exists." << endl;
        return;
    }

    cin.ignore();
    cout << "Enter Product Name: ";
    getline(cin, name);

    cout << "Enter Product Price: ";
    cin >> price;

    cout << "Enter Product Quantity: ";
    cin >> quantity;

    products.emplace_back(id, name, price, quantity);
    saveProductsToFile();
    cout << "Product added successfully." << endl;
}

void Supermarket::editProduct()
{
    int id, quantity;
    double price;
    string name;

    cout << "Enter Product ID to edit: ";
    cin >> id;

    Product *productToEdit = findProductById(id);
    if (productToEdit == nullptr)
    {
        cout << "Product with ID " << id << " not found." << endl;
        return;
    }

    cin.ignore();
    getline(cin, name);

    cout << "Enter Updated Product Price: ";
    cin >> price;

    cout << "Enter Updated Product Quantity: ";
    cin >> quantity;

    productToEdit->name = name;
    productToEdit->price = price;
    productToEdit->quantity = quantity;

    saveProductsToFile();
    cout << "Product updated successfully." << endl;
}

void Supermarket::deleteProduct()
{
    int id;

    cout << "Enter Product ID to delete: ";
    cin >> id;

    auto it = products.begin();
    while (it != products.end())
    {
        if (it->id == id)
        {
            it = products.erase(it);
            std::cout << "Product with ID " << id << " deleted successfully." << endl;
            saveProductsToFile();
            return;
        }
        else
        {
            ++it;
        }
    }

    cout << "Product with ID " << id << " not found." << endl;
}

void Supermarket::browseProducts()
{
    cout << "\n\n-------------------------------------------" << endl;
    cout << "ID    Name               Price     Quantity" << endl;
    cout << "-------------------------------------------" << endl;
    for (const auto &product : products)
    {
        product.displayProduct();
    }
    cout << "-------------------------------------------" << endl;
}

void Supermarket::addToCart()
{
    int id;

    cout << "Enter Product ID to add to cart: ";
    cin >> id;

    Product *productToAdd = findProductById(id);
    if (productToAdd == nullptr)
    {
        cout << "Product with ID " << id << " not found." << endl;
        return;
    }

    cart.push_back(*productToAdd);
    cout << "Product added to cart." << endl;
}

void Supermarket::removeFromCart()
{
    int id;

    cout << "Enter Product ID to remove from cart: ";
    cin >> id;

    for (auto it = cart.begin(); it != cart.end(); ++it)
    {
        if (it->id == id)
        {
            cart.erase(it);
            cout << "Product with ID " << id << " removed from cart." << endl;
            return;
        }
    }

    cout << "Product with ID " << id << " not found in the cart." << endl;
}

void Supermarket::viewCart()
{
    if (cart.empty())
    {
        cout << "Your cart is empty." << endl;
        return;
    }

    cout << "-------------------------------------------" << endl;
    cout << "ID    Name               Price     Quantity" << endl;
    cout << "-------------------------------------------" << endl;
    for (const auto &product : cart)
    {
        product.displayProduct();
    }
    cout << "-------------------------------------------" << endl;
}

void Supermarket::checkout()
{
    if (cart.empty())
    {
        cout << "Your cart is empty. Nothing to checkout." << endl;
        return;
    }

    cout << "------------------- Cart ------------------" << endl;
    viewCart();

    double total = 0.0;
    for (const auto &product : cart)
    {
        total += product.price;
    }

    cout << "-------------------------------------------" << endl;
    cout << "Total Price: " << total << std::endl;

    cart.clear();
    cout << "Checkout completed. Thank you for shopping!" << endl;
}

int main()
{
    string filename = "products.txt";
    Supermarket supermarket(filename);
    string username = "Admin", password = "admin";
    string uname, pass;

    int option;
M:
    while (1)
    {
        cout << "\n\n-------------------------------------------" << endl;
        cout << "           Supermarket Billing System      " << endl;
        cout << "-------------------------------------------" << endl;
        cout << "1. Administration" << endl;
        cout << "2. Browse Products" << endl;
        cout << "3. Add to Cart" << endl;
        cout << "4. Remove from Cart" << endl;
        cout << "5. View Cart" << endl;
        cout << "6. Checkout" << endl;
        cout << "7. Exit" << endl;
        cout << "-------------------------------------------\n"
             << endl;
        cout << "Enter your choice: ";
        cin >> option;
        switch (option)
        {
        case 1:

            while (1)
            {
                cout << "\n\n-------------------------------------------" << endl;
                cout << "           Supermarket Billing System      " << endl;
                cout << "-------------------------------------------" << endl;
                cout << "Enter user name: ";
                cin >> uname;
                cout << "Enter password: ";
                cin >> pass;
                if (supermarket.check(uname, pass))
                {
                logedin:
                    cout << "\n\n"
                         << endl;
                    cout << "1. Add Product (Admin)" << endl;
                    cout << "2. Edit Product (Admin)" << endl;
                    cout << "3. Delete Product (Admin)" << endl;
                    cout << "4. Go to Main Menu" << endl;

                    cout << "Enter your choice: ";
                    cin >> option;

                    switch (option)
                    {
                    case 1:
                        supermarket.addProduct();
                        break;
                    case 2:
                        supermarket.editProduct();
                        break;
                    case 3:
                        supermarket.deleteProduct();
                        break;
                    case 4:
                        goto M;
                        break;
                    default:
                        break;
                    }
                    goto logedin;
                }
                else
                {
                    cout << "Please enter valid user name and password." << endl;
                }
            }

            break;
        case 2:
            supermarket.browseProducts();
            break;
        case 3:
            supermarket.addToCart();
            break;
        case 4:
            supermarket.removeFromCart();
            break;
        case 5:
            supermarket.viewCart();
            break;
        case 6:
            supermarket.checkout();
            break;
        case 7:
            cout << "GoodBye! Have a good Day!" << endl;
            exit(0);
        default:
            cout << "Invalid option. Please try again." << endl;
        }
        // system("cls") :')
    }

    return 0;
}