#include "User.h"
#include <iostream>
#include <cstring>

using namespace std;

int User::n_user = 0;

// ctor, parameter: nama pengguna
User::User(char* name){
    this->name = new char[strlen(name)];
    strcpy(this->name, name);
    this->num_of_favourite_music = 0;
    this->music_list = new char *[100];
    n_user++;
}

// cctor
User::User(const User& other){
    this->name = new char[strlen(other.getName())];
    strcpy(this->name, other.name);
    this->num_of_favourite_music = other.num_of_favourite_music;
    this->music_list = new char *[100];
    for (int i = 0; i < this->num_of_favourite_music; i++){
        this->music_list[i] = new char[strlen(other.music_list[i])];
        strcpy(this->music_list[i], other.music_list[i]);
    }
    n_user++;
}

// dtor
// selain implementasi, print juga "User <nama user> deleted<endl>"
// Contoh:
// User A deleted
//
User::~User(){
    cout << "User " << this->name << " deleted" << endl;
    delete[] this->name;
    
    for (int i = 0; i < this->num_of_favourite_music; i++){
        delete[] this->music_list[i];
    }

    delete[] this->music_list;
}

// Asumsi: musik unik, parameter: judul musik
void User::addFavouriteMusic(char* title){
    music_list[num_of_favourite_music] = new char[strlen(title)];
    strcpy(music_list[num_of_favourite_music], title);
    num_of_favourite_music++;
}

void User::deleteFavouriteMusic(char* title){
    if (num_of_favourite_music > 0){
        if (num_of_favourite_music == 1){
            if (strcmp(music_list[0], title) == 0){
                num_of_favourite_music--;
            }

        } else{
            for (int i = 0; i < num_of_favourite_music; i++){
                if (strcmp(music_list[i], title) == 0){
                    num_of_favourite_music--;
                    int p = i;
                    while (p < num_of_favourite_music){
                        strcpy(music_list[p], music_list[p + 1]);
                        p++;
                    }
                    break;
                }
            }
        }
    }
}

void User::setName(char* name){
    strcpy(this->name, name);
}

char* User::getName() const{
    return name;
}
int User::getNumOfFavouriteMusic() const{
    return num_of_favourite_music;
}

// format print:
// <No>. <Judul musik><endl>
// contoh:
// 1. Starship - Nicki Minaj
// 2. To Be Human - Sia, Labrinth
//
// jika tidak ada musik, print: "No music in your favourite list<endl>"
void User::viewMusicList() const{
    if (this->num_of_favourite_music > 0){
        for (int i = 0; i < this->num_of_favourite_music; i++){
            cout << i + 1 << ". " << this->music_list[i] << endl;
        }
        
    } else {
        cout << "No music in your favourite list" << endl;
    }
}

int User::getNumOfUser(){
    return n_user;
}