#include <iostream>
#include "PlasticCup.hpp"
#include "Plastic.hpp"
#include "Cup.hpp"
using namespace std;

bool PlasticCup::is_usable() {
    return Plastic::is_usable();
}

void PlasticCup::fill(int volume, enum WaterType type) {
    if (this->is_usable()) {
        Cup::fill(volume, type);
        Plastic::use();
        int urai = Plastic::shred_microplastics(volume, Cup::capacity);
        if (type == HOT_WATER) {
            urai *= 2;
        }
        this->current_microplastics += urai;
        if (this->current_microplastics > this->maximum_microplastics) {
            this->current_microplastics = this->maximum_microplastics;
        }
    }
}

void PlasticCup::drink(int volume) {
    if (this->is_usable()) {
        Cup::drink(volume);
        Plastic::use();
        this->current_microplastics -= volume;
        if (this->current_microplastics < 0) {
            this->current_microplastics = 0;
        }
    }
}

void PlasticCup::drop(int height) {
    int urai = Plastic::shred_microplastics(Cup::get_water_volume() * height, Cup::capacity);
    this->current_microplastics += urai;
    if (this->current_microplastics > this->maximum_microplastics) {
        this->current_microplastics = this->maximum_microplastics;
    }
}