
#ifndef GAMELIBRARY_H
#define GAMELIBRARY_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class GameLibrary{
    private:
    unordered_map<string, vector<string>> gamesGenre;
    unordered_map<string, vector<string>> genreGames;

public: 
    GameLibrary(){
        add("Far Far West", {"Shooter", "Action" });
        add("Minecraft" , {"Adventure", "sandbox"});
        add("Portal 2" , {"Puzzle", "Adventure"});
        add("Hollow Knight", {})

    }
private: 
    void add(const string& game, const vector<string>& genres) {
        gamesGenre[game] = genres;
    
        for(const string& g : genres){
            genreGames[g].push_back(game);
        }
    }
public:
    void searchGame(const string& game) const{
        auto it = gamesGenre.find(game);
        if(it == gamesGenre.end()) {
            cout << "Game not found.\n" ;
            return;
        }
            
        for (const string& genre : it->second) {
                cout << " - " << genre << "\n";
        }
        
    }
    void printGamesByGenre(const string& genre) const {
        auto it = genreGames.find(genre);
        if (it == genreGames.end()) {
            cout << "No games found for genre.\n";
            return;
        }

        const vector<string>& bucket = it->second;
        for (const string& game : bucket) {
            cout << " - " << game << "\n";
        }
    }
        
    void pullGame(const string& game) const {
        auto it = gamesGenre.find(game);
        if (it == gamesGenre.end()) {
            cout << "Game not found.\n";
            return;
        }
        cout << "game: " << game << "\n";
        
        const vector<string>& genres = it->second;
        for (const string& g : genres) {
            cout << " - " << g << "\n";
        }
    }
    void Pullgug(const string& genre) const{
        auto it = genreGames.find(genre);
        if (it == genreGames.end()) {
            cout << "No games under genre: " << genre << "\n";
            return ;
        }
        
        
        cout << " Games in genre: " << genre << "\n" ;
        const vector<string>& gameList = it->second;
        
        for (const string& gameName : gameList){
            cout <<"Game: " << gameName << "\n";
            auto gameIt = gamesGenre.find(gameName);
            if (gameIt != gamesGenre.end()) {
                cout << "Genres;\n";
                for (const string & g: gameIt -> second) {
                    cout << " -  " << g << "\n";
                }
            }
            cout <<"\n";
        }
        
    }    

        
};

#endif
