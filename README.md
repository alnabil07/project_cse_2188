# Supermarket Billing System

This is a simple command-line based Supermarket Billing System written in C++. The program allows users to perform various tasks such as browsing products, adding products to a shopping cart, removing products from the cart, and checking out. Additionally, there is an administration feature that allows an admin user to add, edit, and delete products.

## Prerequisites

To run this program, you need to have a C++ compiler installed on your system.

## How to Use

1. Clone the repository or download the source code.
2. Compile the code using a C++ compiler.
3. Run the compiled executable.

## Features

The Supermarket Billing System offers the following features:

1. **Browsing Products:** The user can view the list of available products in the supermarket.

2. **Adding Products to Cart:** The user can add products to their shopping cart by specifying the product ID.

3. **Removing Products from Cart:** The user can remove products from the cart by specifying the product ID.

4. **Viewing Cart:** The user can view the contents of their shopping cart, including product details like ID, name, price, and quantity.

5. **Checkout:** The user can proceed to checkout their cart, which will display the total price of the items and empty the cart.

6. **Administration:** An admin user can log in using a username and password to access additional functionalities:

   - **Add Product:** The admin can add new products to the supermarket inventory, specifying the product ID, name, price, and quantity.
   - **Edit Product:** The admin can edit existing product details, including name, price, and quantity.
   - **Delete Product:** The admin can remove a product from the supermarket inventory.

## Data Persistence

The program uses a file named "products.txt" to store the supermarket's inventory. When the program starts, it reads the product data from the file into memory. When products are added, edited, or deleted, the changes are saved back to the file.

## Usage

Upon running the program, you will be presented with a menu displaying the available options:

1. Administration
2. Browse Products
3. Add to Cart
4. Remove from Cart
5. View Cart
6. Checkout
7. Exit

Depending on the option you choose, the program will prompt you for further input to perform the desired action.

## Admin Login

To access the administration features (add, edit, delete products), you need to provide the correct admin username and password. The default credentials are:

- Username: Admin
- Password: admin

You can modify the `username` and `password` variables in the `main` function to change the login credentials.

## Developer Information

- Name: Al Nimra Kabir
- Email: alnimra121@gmail.com
- GitHub Profile: [alnabil07](https://github.com/alnabil07)

For any questions, issues, or suggestions, please feel free to contact the developer via the provided email or GitHub profile. Happy shopping!
