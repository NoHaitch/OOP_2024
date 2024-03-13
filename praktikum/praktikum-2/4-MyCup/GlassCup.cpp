#include <iostream>
#include "GlassCup.hpp"
#include "Cup.hpp"
#include "Glass.hpp"
using namespace std;

bool GlassCup::is_usable() {
    return Glass::is_usable();
}

void GlassCup::fill(int volume, enum WaterType type) {
    if (this->is_usable()) {
        Cup::fill(volume, type);
    }
}

void GlassCup::drink(int volume) {
    if (this->is_usable()) {
        Cup::drink(volume);
    }
}

void GlassCup::drop(int height) {
    if (Cup::get_water_volume() == 0) {
        Glass::apply_force(height);
    } else {
        Glass::apply_force(height * get_water_volume());
    }
}