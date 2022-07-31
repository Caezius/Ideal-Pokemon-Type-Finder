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

// adds the word " BOTH" to the end of a given string (should be the name of a type)
string addBOTH(string type_name){
    return type_name + " (BOTH)";
}

// replaces repeat types with that type's name, but with a " X2" or "X4" multiplier at the end
// because it's already listed by "weak against", we already know all the types there are already X2
// so we'll only add if it's listed twice, which will add a " X4"
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
    // learned how to loop through a map from this:
    // https://stackoverflow.com/questions/26281979/c-loop-through-map
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

//same replaceRepeats function, but replaces repeats, but the replacement concatenated with the string " BOTH"
vector <string> replaceRepeats2(vector<string> vector_arg){
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
    // learned how to loop through a map from this:
    // https://stackoverflow.com/questions/26281979/c-loop-through-map
    for (auto const&[key, value] : repeats){

        if (value == 1){
            name_to_add = key;

        } else if (value > 1){
            name_to_add = addBOTH(key);

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

        string name;

        PkmnType(string name, vector <string> strengths, vector <string> ineffectives, vector<string> for_naught, vector <string> weaknesses, vector <string> resistances, vector <string> immunities){
            this-> name = name;

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
            new_strengths = replaceRepeats2(new_strengths);

            vector<string> new_resistances = getUniques(combined_resistances, combined_weaknesses);
            new_resistances = getUniques(new_resistances, combined_immunities);
            new_resistances = replaceRepeats(new_resistances);
            
            vector<string> new_ineffectives = combineVectors(ineffectives, other_type.ineffectives);
            new_ineffectives = replaceRepeats2(new_ineffectives);

            vector<string> new_immunities = combined_immunities;
            new_immunities = replaceRepeats2(new_immunities);

            vector<string> new_naughts = combineVectors(this->for_naught, other_type.for_naught);
            new_naughts = replaceRepeats2(new_naughts);

            vector<vector <string>> new_matchups = {new_strengths, new_ineffectives, new_naughts, new_weaknesses, new_resistances, new_immunities};
            return new_matchups;
        }

};

//prints a vector line by line
void print2DVector(vector< vector<string> > vector2D){
    
}

void print1DVector(vector<string> vector1D){
    for (int i = 0; i < int(vector1D.size()); i++){
        cout << vector1D[i] << "\n";
    }
}

//asks the user for the type names
void askForCombo(auto types){
    string type_name1;
    string type_name2;

    cout << "Enter one type: " << "\n";
    cin >> type_name1;
    cout << type_name1 << "\n";

    cout << "Enter a second type: " << "\n";
    cin >> type_name2;
    cout << type_name2 << "\n" << "\n";

    PkmnType type1("type1", {},{},{},{},{},{});
    PkmnType type2("type2", {},{},{},{},{},{});

    if (checkKeyIn(type_name1, types) == true && checkKeyIn(type_name2, types) == false){
        cout << "ERROR: One or more type names passed to 'askForCombo()' is not in the map of known types.";
        return;
    }

    for (auto const &pair : types){
        if (pair.first == type_name1){
            type1 = pair.second;
            break;
        }
    }

    for (auto const &pair : types){
        if (pair.first == type_name2){
            type2 = pair.second;
            break;
        }
    }

    vector <string> details = {"Strong Against", "Ineffective Against", "Doesn't Affect", "Weak To", "Resistant To", "Immune To"};

    auto combo = type1.getCombo(type2);
    
    
    //should be 6 interactions between other types (weak against, ineffective against), so r, the number of rows, should be 6.
    for (int r = 0; r < 6; r++){
        cout << details[r] << ": \n";

        for (int c = 0; c < int(combo[r].size()); c++){
            cout << combo[r][c] << "\n";
        }

        cout << "\n";
    }


}
//returns a true if a key is in a given map, or false if the key is not.
bool checkKeyIn(auto key, auto map){

    for (auto const &pair : map){
        
        if (key == pair.first){
            return true;
        }
    }

    return false;

}

//finds the type combo for a type, that has the most resistances
void findMostResistances(string type_name, auto types_map){
    int num_resistances;
    int highest_r = 0;
    vector <string> best_combos;
    PkmnType type("", {},{},{},{},{},{});
    PkmnType other_type("", {},{},{},{},{},{});
    
    if (checkKeyIn(type_name, types_map) == false ){
        cout << "ERROR: No type named " + type_name;
        return;
    };

    //loop through the types map and find the type object associated with this name
    for (auto const &pair : types_map){
    
        if (pair.first == type_name){
            type = pair.second;
        }

    }
    
    //loop through the map and test the given type with every other type in the map
    for (auto const &pair : types_map){
        //don't check the combination if it's the same type
        if (pair.first != type_name){
            other_type = pair.second;
            vector <vector <string> > combo = type.getCombo(other_type);
            
            //the vector containing the resistances should be the 5th one
            num_resistances = int(combo[4].size());
            if (num_resistances > highest_r){
                highest_r = num_resistances;
            }
        }

    }

    //loop back through the other types again
    //but this time add those that have the highest number of resistances variable that we found

    for (auto const &pair : types_map){
        if (pair.first != type_name){
            other_type = pair.second;
            vector <vector <string> > combo = type.getCombo(other_type);
            
            num_resistances = int(combo[4].size());
            //if it's one of the types that has that highest resistance we found, add a string with both names to the returned vector
            if (num_resistances == highest_r){
                best_combos.push_back(type.name + "-" + other_type.name + "(" + to_string(highest_r) + ")");
            }
        }

    }

    print1DVector(best_combos);
}

int main() {
    std::map <string, PkmnType> types;
    
    PkmnType Dragon("Dragon", {"Dragon"}, {"Steel"}, {"Fairy"}, {"Ice", "Dragon", "Fairy"}, {"Fire", "Water", "Grass", "Electric"}, {});
    PkmnType Water("Water", {"Fire", "Rock", "Ground"}, {"Water", "Grass", "Electric"}, {}, {"Electric", "Grass"}, {"Water", "Ice", "Fire"}, {});
    PkmnType Fire ("Fire", {"Ice", "Bug", "Grass", "Steel"}, {"Fire", "Water", "Rock", "Dragon"}, {}, {"Water", "Ground", "Rock"}, {"Fire", "Grass", "Ice", "Bug", "Steel", "Fairy"}, {});
    PkmnType Ice ("Ice", {"Grass", "Ground", "Flying", "Dragon"}, {"Fire", "Water", "Ice", "Steel"}, {}, {"Fire", "Fighting", "Rock", "Steel"}, {"Ice"}, {});
    PkmnType Flying("Flying", {"Grass", "Fighting", "Bug"}, {"Electric", "Rock", "Steel"}, {}, {"Rock", "Ice", "Electric"}, {"Grass", "Fighting", "Bug"}, {"Ground"});
    PkmnType Grass("Grass", {"Water", "Ground", "Rock"}, {"Fire", "Grass", "Poison", "Flying", "Bug", "Dragon", "Steel"}, {}, {"Fire", "Ice", "Poison", "Flying", "Bug"}, {"Water", "Grass", "Electric", "Ground"}, {});
    PkmnType Steel("Steel", {"Ice", "Rock", "Fairy"}, {"Fire", "Water", "Electric", "Steel"}, {}, {"Fire", "Fighting", "Ground"}, {"Normal", "Grass", "Ice", "Flying", "Psychic", "Bug", "Rock", "Dragon", "Steel", "Fairy"}, {"Poison"});
    PkmnType Fighting("Fighting", {"Normal", "Ice", "Rock", "Dark", "Steel"}, {"Poison", "Flying", "Psychic", "Bug", "Fairy"}, {"Ghost"}, {"Flying", "Psychic", "Fairy"}, {"Bug", "Rock", "Dark"}, {});
    PkmnType Ghost("Ghost", {"Psychic", "Ghost"}, {"Dark"}, {"Normal"}, {"Ghost", "Dark"}, {"Poison", "Bug"}, {"Normal", "Fighting"});
    PkmnType Normal("Normal", {}, {"Rock", "Steel"}, {"Ghost"}, {"Fighting"}, {}, {"Ghost"});
    PkmnType Psychic("Psychic", {"Fighting", "Poison"}, {"Psychic", "Steel"}, {"Dark"}, {"Bug", "Ghost", "Dark"}, {"Fighting", "Psychic"}, {});
    PkmnType Poison("Poison", {"Grass", "Fairy"}, {"Poison", "Ground", "Rock", "Ghost"}, {"Steel"}, {"Ground", "Psychic"}, {"Grass", "Fighting", "Poison", "Bug", "Fairy"}, {});
    PkmnType Electric("Electric", {"Water", "Flying"}, {"Grass", "Electric", "Dragon"}, {"Ground"}, {"Ground"}, {"Electric", "Flying", "Steel"}, {});
    PkmnType Fairy("Fairy", {"Fighting", "Dragon", "Dark"}, {"Fire", "Posion", "Steel"}, {}, {"Poison", "Steel"}, {"Fighting", "Bug", "Dark"}, {"Dragon"});
    PkmnType Rock ("Rock", {"Fire", "Ice", "Flying", "Bug"}, {"Fighting", "Ground", "Steel"}, {}, {"Water", "Grass", "Fighting", "Ground", "Steel"}, {"Normal", "Fire", "Poison", "Flying"}, {});
    PkmnType Ground("Ground", {"Fire", "Electric", "Poison", "Rock", "Steel"}, {"Grass", "Bug"}, {"Flying"}, {"Water", "Grass", "Ice"}, {"Poison", "Rock"}, {"Electric"});
    PkmnType Dark("Dark", {"Psychic", "Ghost"}, {"Fighting", "Dark", "Fairy"}, {}, {"Fighting", "Bug", "Fairy"}, {"Ghost", "Dark"}, {"Psychic"});
    PkmnType Bug ("Bug", {"Grass", "Psychic", "Dark"}, {"Fire", "Fighting", "Poison", "Flying", "Ghost", "Steel", "Fairy"}, {}, {"Fire", "Flying", "Rock"}, {"Grass", "Fighting", "Ground"}, {});
    
    // used these to learn how to place an object into a map (types["Dragon"] = Dragon didn't work)
    // https://stackoverflow.com/questions/30956780/c-how-to-add-objects-to-maps-and-return-reference-to-new-created-object-inside
    // https://en.cppreference.com/w/cpp/container/map/emplace
    types.emplace(std::make_pair("Dragon", Dragon) );
    types.emplace(std::make_pair("Water", Water) );
    types.emplace(std::make_pair("Fire", Fire) );
    types.emplace(std::make_pair("Ice", Ice) );
    types.emplace(std::make_pair("Flying", Flying) );
    types.emplace(std::make_pair("Grass", Grass) );
    types.emplace(std::make_pair("Steel", Steel) );
    types.emplace(std::make_pair("Fighting", Fighting) );
    types.emplace(std::make_pair("Ghost", Ghost) );
    types.emplace(std::make_pair("Normal", Normal) );
    types.emplace(std::make_pair("Psychic", Psychic) );
    types.emplace(std::make_pair("Poison", Poison) );
    types.emplace(std::make_pair("Electric", Electric) );
    types.emplace(std::make_pair("Fairy", Fairy) );
    types.emplace(std::make_pair("Rock", Rock) );
    types.emplace(std::make_pair("Ground", Ground) );
    types.emplace(std::make_pair("Dark", Dark) );
    types.emplace(std::make_pair("Bug", Bug) );


    vector <vector<string>> Some_combo = Ice.getCombo(Steel);

    //askForCombo(types);
    //types["Steel"];

    findMostResistances("Steel", types);

    

    return 0;
}
