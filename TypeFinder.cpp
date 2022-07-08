#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

//takes two string vectors, pushes both their members into one new vector, and returns that new vector
vector <string> combineVectors(vector<string> vector1, vector<string> vector2){
    vector<string> combined_vector = {};

    for (int i = 0; i < int(vector1.size()); i++){
        combined_vector.push_back(vector1[i]);
    }

    for (int i = 0; i < int(vector2.size()); i++){
        combined_vector.push_back(vector2[i]);
    }

    return combined_vector;


}

//takes two vectors. Returns a vector with items in the 1ST that aren't in the second.
vector <string> getUniques(vector<string> vector1, vector<string> vector2){
    bool found_match = false; //for each of vector1's items, keep track of if we've found it in vector2
    
    int size_of_vector1 = int(vector1.size());
    int size_of_vector2 = int(vector2.size());

    vector <string> uniques = {};

    for (int i = 0; i < size_of_vector1; i++){
        
        for(int j = 0; j < size_of_vector2; j++){

            if (vector1[i] == vector2[j]){
                found_match = true;
                break;
            }

        }

        if (found_match == false){ //check if after going through the other array, there was still no match
            uniques.push_back(vector1[i]);
        } else {
            found_match = false;
        }  

    }

    return uniques;   
}

vector <string> findRepeats(vector<string> vector_arg){
    /*for (int i = 0; i < int(vector_arg.size()); i++){
        //we shouldn't need to start from the beginning for each item-since it's all in the same vector, if one was a match with an earlier item, a match would have been identified between the two when that other item was checked
        for (int j = i; j < int(vector_arg.size()); j++){
            
            if (i == j && j !){
                repeats.push_back(vector_arg.size)
            }
        }

    }*/
    vector<string> youshouldcodethis = {};
    return youshouldcodethis;

}

class PkmnType {
    public:
    vector <string> strengths;
    vector <string> ineffectives;
    vector <string> for_naught;

    vector <string> weaknesses;
    vector <string> resistances;
    vector <string> immunities;


    PkmnType(vector <string> strengths, vector <string> ineffectives, vector<string> for_naught, vector <string> weaknesses, vector <string> resistances, vector <string> immunities){
        this-> strengths = strengths;
        this-> ineffectives = ineffectives;
        this-> for_naught = for_naught;

        this-> weaknesses = weaknesses;
        this-> resistances = resistances;
        this-> immunities = immunities;
    }

    //returns the type matchups for a combination of two types
    vector<vector <string>> getCombo(PkmnType other_type){
        vector<string> combined_weaknesses = combineVectors(this->weaknesses, other_type.weaknesses);
        vector<string> combined_resistances = combineVectors(this->resistances, other_type.resistances);
        vector<string> combined_immunities = combineVectors(this->immunities, other_type.immunities);
        vector<string> combined_naughts = combineVectors(this->for_naught, other_type.for_naught);

        vector<string> new_weaknesses = getUniques(combined_weaknesses, combined_resistances);
        new_weaknesses = getUniques(new_weaknesses, combined_immunities);

        vector<string> new_strengths = combineVectors(this->strengths, other_type.strengths);
        vector<string> new_resistances = getUniques(combined_resistances, combined_weaknesses);
        new_resistances = getUniques(new_resistances, combined_immunities);
        vector<string> new_ineffectives = combineVectors(ineffectives, other_type.ineffectives);
        vector<string> new_immunities = combined_immunities;
        vector<string> new_naughts = combineVectors(this->for_naught, other_type.for_naught);
        
        vector<vector <string>> new_matchups = {new_strengths, new_ineffectives, new_naughts, new_weaknesses, new_resistances, new_immunities};
        return new_matchups;
    }

};


int main() {    
    PkmnType Dragon({"Dragon"}, {"Steel"}, {"Fairy"}, {"Ice", "Dragon", "Fairy"}, {"Fire", "Water", "Grass", "Electric"}, {});
    PkmnType Water({"Fire", "Rock", "Ground"}, {"Water", "Grass", "Electric"}, {}, {"Electric", "Grass"}, {"Water", "Ice", "Fire"}, {});
    PkmnType Fire ({"Ice", "Bug", "Grass", "Steel"}, {"Fire", "Water", "Rock", "Dragon"}, {}, {"Water", "Ground", "Rock"}, {"Fire", "Grass", "Ice", "Bug", "Steel", "Fairy"}, {});
    PkmnType Ice ({"Grass", "Ground", "Flying", "Dragon"}, {"Fire", "Water", "Ice", "Steel"}, {}, {"Fire", "Fighting", "Rock", "Steel"}, {"Ice"}, {});
    PkmnType Flying({"Grass", "Fighting", "Bug"}, {"Electric", "Rock", "Steel"}, {}, {"Rock", "Ice", "Electric"}, {"Grass", "Fighting", "Bug"}, {"Ground"});
    PkmnType Grass({"Water", "Ground", "Rock"}, {"Fire", "Grass", "Poison", "Flying", "Bug", "Dragon", "Steel"}, {}, {"Fire", "Ice", "Poison", "Flying", "Bug"}, {"Water", "Grass", "Electric", "Ground"}, {});
    PkmnType Steel({"Ice", "Rock", "Fairy"}, {"Fire", "Water", "Electric", "Steel"}, {}, {"Fire", "Fighting", "Ground"}, {"Normal", "Grass", "Ice", "Flying", "Psychic", "Bug", "Rock", "Dragon", "Steel", "Fairy"}, {"Poison"});
    PkmnType Fighting({"Normal", "Ice", "Rock", "Dark", "Steel"}, {"Poison", "Flying", "Psychic", "Bug", "Fairy"}, {"Ghost"}, {"Flying", "Psychic", "Fairy"}, {"Bug", "Rock", "Dark"}, {});
    PkmnType Ghost({"Psychic", "Ghost"}, {"Dark"}, {"Normal"}, {"Ghost", "Dark"}, {"Poison", "Bug"}, {"Normal", "Fighting"});
    PkmnType Normal({}, {"Rock", "Steel"}, {"Ghost"}, {"Fighting"}, {}, {"Ghost"});
    PkmnType Psychic({"Fighting", "Poison"}, {"Psychic", "Steel"}, {"Dark"}, {"Bug", "Ghost", "Dark"}, {"Fighting", "Psychic"}, {});
    PkmnType Poison({"Grass", "Fairy"}, {"Poison", "Ground", "Rock", "Ghost"}, {"Steel"}, {"Ground", "Psychic"}, {"Grass", "Fighting", "Poison", "Bug", "Fairy"}, {});
    PkmnType Electric({"Water", "Flying"}, {"Grass", "Electric", "Dragon"}, {"Ground"}, {"Ground"}, {"Electric", "Flying", "Steel"}, {});
    PkmnType Fairy({"Fighting", "Dragon", "Dark"}, {"Fire", "Posion", "Steel"}, {}, {"Poison", "Steel"}, {"Fighting", "Bug", "Dark"}, {"Dragon"});
    PkmnType Rock ({"Fire", "Ice", "Flying", "Bug"}, {"Fighting", "Ground", "Steel"}, {}, {"Water", "Grass", "Fighting", "Ground", "Steel"}, {"Normal", "Fire", "Poison", "Flying"}, {});
    PkmnType Ground({"Fire", "Electric", "Poison", "Rock", "Steel"}, {"Grass", "Bug"}, {"Flying"}, {"Water", "Grass", "Ice"}, {"Poison", "Rock"}, {"Electric"});
    PkmnType Dark({"Psychic", "Ghost"}, {"Fighting", "Dark", "Fairy"}, {}, {"Fighting", "Bug", "Fairy"}, {"Ghost", "Dark"}, {"Psychic"});
    PkmnType Bug ({"Grass", "Psychic", "Dark"}, {"Fire", "Fighting", "Poison", "Flying", "Ghost", "Steel", "Fairy"}, {}, {"Fire", "Flying", "Rock"}, {"Grass", "Fighting", "Ground"}, {});

    vector <vector<string>> Some_combo = Steel.getCombo(Ice);
    
    vector <string> details = {"Strong Against", "Ineffective Against", "Doesn't Affect", "Weak Against", "Resists", "Immune To"};

    for (int i = 0; i < int(Some_combo.size()); i++){
        cout << details[i] << ":" << "\n";
        
        for (int j = 0; j < int(Some_combo[i].size()); j++){
            cout << Some_combo[i][j] << "\n";
        }

        cout << "\n";
    }

    return 0;
}
