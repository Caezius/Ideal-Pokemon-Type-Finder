#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
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

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
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
string addMultiplier(string type_name, int times){
    times = 2 * times;

    //addMultiplier("Grass", 2) returns "Grass X4"
    return type_name + " X" + to_string(times);  
    
}

vector <string> replaceRepeats(vector<string> vector_arg){
    //take the array
    // for each item, find anywhere it repeats, have a count, and remove it
    // any one that has an associated count of more than 1, get the right multiplier added
    // add the ones with only 1 back in first, then add the new strings with the "Xn" at the end

    vector<string> vector_copy = vector_arg;

    int current_instances;

    map <string, int> repeats;
    //loop through the vector-continue until we've removed all items, both duplicates and uniques
    while (vector_copy.size() != 0){
        //when we check each unique object, it should be the first one
        //even when we remove all instances, the next unique value should slide over to the first position
        // [2, 4, 2, 3, 6]
        // [4, 3, 6] when we remove all 2s, we get a new number that is guaranteed not to be a 2
        
        string current_item = vector_copy[0]; 
        vector_copy.erase(vector_copy.begin()); //remove the current item (which should be the first) right away, so we don't have to worry about removing it later
        current_instances = 1;

        // we already know the first item will always be unique
        // so to check all of them, we'll start from the next one- which will always be the second item (since we're always starting with the first item), or index 1
        // start i from 1, which will be the second item, so we can check the rest of the array
        // [2, 4, 2, 3, 6]
        // [2, 4, 2, 3, 6]
        //     ↑ start from the one right after
        // [2] Now we loop through the rest of the items
        //never mind, we already deleted the first item, so we should start i at 0
        // also the vector_copy size should update and get smaller automatically
        for (int i = 0; i < int(vector_copy.size()); i++){
            string item_to_compare = vector_copy[i]; 

            if (current_item == item_to_compare){
                current_instances += 1;
 
                vector_copy.erase(vector_copy.begin() + i); //erase where that item was
                
                i = i - 1; //we just removed an item, so we decrement i, so when it's incremented next loop it gets reset to the value it just was
            }
        }

        //after adding up all the instances, add a new entry, using the string itself as a key, to the repeats map
        repeats[current_item] = current_instances;

    }

    

    // [3] loop through the keys and their values. 
    // If they are greater than 1, add a new string with a multiplier to it.
    
    string name_to_add;
    // loop through the repeats map
    for (auto const&[key, value] : repeats){

        if (value == 1){
            name_to_add = key;

        } else if (value > 1){
            name_to_add = addMultiplier(key, value);

        } else {
            cout << "Something went wrong. A type somehow appeared 0 times.\n";
            vector<string> error = {"ERROR."};
            return error;
        }

        //add the name back into the now-empty vector
        vector_copy.push_back(name_to_add);
    }

 
    return vector_copy;

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
        new_weaknesses = replaceRepeats(new_weaknesses);

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
    std::map<string, PkmnType> types_map;
    /*
    types_map["Dragon"] = PkmnType Dragon({"Dragon"}, {"Steel"}, {"Fairy"}, {"Ice", "Dragon", "Fairy"}, {"Fire", "Water", "Grass", "Electric"}, {});
    types_map[];
    types_map[];
    types_map[];
    types_map[];
    types_map[];
    types_map[];
    types_map[];
    types_map[];
    types_map[];
    types_map[];
    types_map[];
    types_map[];
    types_map[];
    types_map[];
    types_map[];
    types_map[];
    types_map[];
    */

    vector<string> vec = {"Copy1", "Copy2", "Bob", "Copy1", "Copy2", "Mary"};
    vec = replaceRepeats(vec);
    for (int i = 0; i < int(vec.size()); i++){
        cout << vec[i] << "\n";
    }

    /* <!> UN COMMENT WHEN NEW FINDREPEATS FUNCTION COMPLETED
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
    */
    return 0;
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
        new_weaknesses = replaceRepeats(new_weaknesses);

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
    std::map<string, PkmnType> types_map;
    /*
    types_map["Dragon"] = PkmnType Dragon({"Dragon"}, {"Steel"}, {"Fairy"}, {"Ice", "Dragon", "Fairy"}, {"Fire", "Water", "Grass", "Electric"}, {});
    types_map[];
    types_map[];
    types_map[];
    types_map[];
    types_map[];
    types_map[];
    types_map[];
    types_map[];
    types_map[];
    types_map[];
    types_map[];
    types_map[];
    types_map[];
    types_map[];
    types_map[];
    types_map[];
    types_map[];
    */

    vector<string> vec = {"Copy1", "Copy2", "Bob", "Copy1", "Copy2", "Mary"};
    vec = replaceRepeats(vec);
    for (int i = 0; i < int(vec.size()); i++){
        cout << vec[i] << "\n";
    }

    /* <!> UN COMMENT WHEN NEW FINDREPEATS FUNCTION COMPLETED
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
    */
    return 0;
}
