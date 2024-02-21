#include "Item.hpp"

int Item::totalItems = 0;
int Item::totalRevenue = 0;

Item::Item() : serialNum(this->totalItems + 1){
    this->stock = 0;
    this->price = 0;
    this->sold = 0;
    this->totalItems++;
}

Item::Item(int stock, int price) : serialNum(this->totalItems + 1){
    this->stock = stock;
    this->price = price;
    this->sold = 0;
    this->totalItems++;
}

Item::Item(const Item& other) : serialNum(this->totalItems + 1){
    this->stock = other.stock;   
    this->price = other.price;   
    this->sold = other.sold;   
    this->totalItems++;   
}

Item::~Item(){
    this->totalRevenue -= this->price * this->sold;
    this->totalItems--;
}

int Item::getSerialNum() const{
    return this->serialNum;
}

int Item::getSold() const{
    return this->sold;
}

int Item::getPrice() const{
    return this->price;
}

void Item::addStock(int addedStock){
    this->stock += addedStock;
}

void Item::sell(int soldStock){
    while(this->stock > 0){
        this->stock --;
        this->totalRevenue += this->price;
    }
}

void Item::setPrice(int newPrice){
    this->price = newPrice;
}