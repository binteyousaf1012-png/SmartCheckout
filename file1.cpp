#include<iostream>
#include<string>
#include<stdexcept>
using namespace std;
 class Product{
     private:
     int id;
     string name;
     double price;
     int stockQuantity;
     public:
      Product(int i, string n, double p,int sq ):id(i),name(n),price(p),stockQuantity(sq){
         if(p<0||sq<0){
             throw invalid_argument("Invalid product price and quantity!");
        }
      }
        void setPrice(double p){
         if (p<0){
             throw invalid_argument("Invalid Price!");
        }
             price = p;
      }
         void setName(string n){
             name = n;
      }
         void setStockQuantity(int sq){
         if (sq<0){
             throw invalid_argument("Invalid Quantity!");
        }
             stockQuantity= sq;
      }
         int getID(){
             return id;
      } 
         string getName(){
             return name;
      }
         double getPrice(){
             return price;
      }
         int getStockQuantity(){
             return stockQuantity;
      }
      void displayDetails(){
         cout<<"Product ID="<<getID()<<endl;
         cout<<"Product Name="<<getName()<<endl;
         cout<<"StockQuantity="<<getStockQuantity()<<endl;
         cout<<"Price="<<getPrice()<<endl;
      }
      bool purchaseproduct (int quantity){
        if(quantity<=0){
         return false;
        }
        if (quantity>stockQuantity){
            return false;
        }
         stockQuantity-= quantity;
         return true;
      }
};
int main(){
     Product p1(101,"Milk",250.0,50);
     Product p2(102,"Bread",250.0,30);
     if (p1.purchaseproduct(-5)){
         cout<<"Purchase successful!"<<endl;
     }
     else{ 
     cout<<"Purchase failed!"<<endl;
    }
     p1.displayDetails();
     p2.displayDetails();
     return 0;
}