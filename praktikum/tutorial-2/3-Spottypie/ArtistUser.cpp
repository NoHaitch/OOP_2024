#include "ArtistUser.h"
#include <iostream>

using namespace std;

int ArtistUser::num_of_artist = 0;

//ctor, parameter: nama pengguna
ArtistUser::ArtistUser(char *name) : User(name){
    this->num_of_music_uploaded = 0;
    this->uploaded_music_list = new char *[1000];
    num_of_artist++;
}

// cctor
ArtistUser::ArtistUser(const ArtistUser &other) : User(other.getName()){
    this->num_of_favourite_music = other.getNumOfFavouriteMusic();
    this->music_list = new char *[1000];
    for (int i = 0; i < this->num_of_favourite_music; i++){
        this->music_list[i] = new char[strlen(other.music_list[i])];
        strcpy(this->music_list[i], other.music_list[i]);
    }
    this->num_of_music_uploaded = other.num_of_music_uploaded;
    this->uploaded_music_list = new char *[1000];
    for (int i = 0; i < this->num_of_music_uploaded; i++){
        this->uploaded_music_list[i] = new char[strlen(other.uploaded_music_list[i])];
        strcpy(this->uploaded_music_list[i], other.uploaded_music_list[i]);
    }
    num_of_artist++;
}

// dtor
// selain implementasi, print juga "Artist user <nama user> deleted"
// Contoh:
// Artist user A deleted
ArtistUser::~ArtistUser(){
    cout << "Artist user " << name << " deleted" << endl;
    for (int i = 0; i < num_of_music_uploaded; i++){
        delete[] uploaded_music_list[i];
    }
    delete[] uploaded_music_list;
}

// Asumsi: musik unik, parameter: judul musik
void ArtistUser::uploadMusic(char *title){
    uploaded_music_list[num_of_music_uploaded] = new char[strlen(title)];
    strcpy(uploaded_music_list[num_of_music_uploaded], title);
    num_of_music_uploaded++;
}

void ArtistUser::deleteUploadedMusic(char *title){
    if (num_of_music_uploaded > 0){
        if (num_of_music_uploaded == 1){
            if (strcmp(uploaded_music_list[0], title) == 0){
                num_of_music_uploaded--;
            }
        } else{
            for (int i = 0; i < num_of_music_uploaded; i++){
                if (strcmp(uploaded_music_list[i], title) == 0){
                    num_of_music_uploaded--;
                    int p = i;
                    while (p < num_of_music_uploaded){
                        strcpy(uploaded_music_list[p], uploaded_music_list[p + 1]);
                        p++;
                    }
                    break;
                }
            }
        }
    }
}

// format print:
// <No>. <Judul musik><endl>
// contoh:
// 1. Starship - Nicki Minaj
// 2. To Be Human - Sia, Labrinth
//
// jika tidak ada musik, print: "No music uploaded<endl>"
void ArtistUser::viewUploadedMusicList() const{
    if (this->num_of_music_uploaded > 0){
        for (int i = 0; i < this->num_of_music_uploaded; i++){
            cout << i + 1 << ". " << this->uploaded_music_list[i] << endl;
        }
    } else{
        cout << "No music uploaded" << endl;
    }
}

int ArtistUser::getNumOfMusicUploaded() const{
    return this->num_of_music_uploaded;
}

int ArtistUser::getNumOfArtist(){
    return ArtistUser::num_of_artist;
}