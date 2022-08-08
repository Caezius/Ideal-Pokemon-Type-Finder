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

        vector < vector <string> > all_interactions;

        PkmnType(string name, vector <string> strengths, vector <string> ineffectives, vector<string> for_naught, vector <string> weaknesses, vector <string> resistances, vector <string> immunities){
            this-> name = name;

            this-> strengths = strengths;
            this-> ineffectives = ineffectives;
            this-> for_naught = for_naught;

            this-> weaknesses = weaknesses;
            this-> resistances = resistances;
            this-> immunities = immunities;

            this-> all_interactions = {strengths, ineffectives, for_naught, weaknesses, resistances, immunities};

            
        }

        //returns the type matchups for a combination of two types
        PkmnType getCombo(PkmnType other_type){
            PkmnType returned_type("", {}, {}, {}, {}, {}, {});
            string combo_name = this -> name + "-" + other_type.name;

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

            
            returned_type = PkmnType(combo_name, new_strengths, new_ineffectives, new_naughts, new_weaknesses, new_resistances, new_immunities);

            vector<vector <string>> new_matchups = {new_strengths, new_ineffectives, new_naughts, new_weaknesses, new_resistances, new_immunities};
            return returned_type;
        }

        void printInteractions(){
            vector <string> interaction_names = {"Strong Against", "Ineffective Against", "Doesn't Affect", "Weak To", "Resistant To", "Immune To"};

            //should be 6 interactions between other types (weak against, ineffective against), so r, the number of rows, should be 6.
            for (int r = 0; r < 6; r++){
                cout << interaction_names[r] << ": \n";

            for (int c = 0; c < int(this->all_interactions[r].size()); c++){
                cout << this->all_interactions[r][c] << "\n";
            }

            cout << "\n";
            }

        }


};


void print1DVector(vector<string> vector1D){
    for (int i = 0; i < int(vector1D.size()); i++){
        cout << vector1D[i] << "\n";
    }
    cout << "\n";
}


//finds the type combo for a type, that has the most resistances
vector<string> findMostResistances(string type_name, map <string, PkmnType> types_map){
    PkmnType type("", {}, {}, {}, {}, {}, {});
    
    bool found_type = false;
    vector<string> error_vector;

    PkmnType combo("", {}, {}, {}, {}, {}, {});
    
    string other_type_name;
    PkmnType other_type("", {}, {}, {}, {}, {}, {});
    
    int num_resistances;
    int max_resistances = 0;
    
    
    vector < PkmnType > combo_holder;
    vector < string > combo_names;
    string title_string = "Resistances of " + type_name + "-Type Combinations: ";
    combo_names.push_back(title_string);

    
    
    string combo_with_count;
    

    //set the type object by finding its associated object in the map
    for (auto const &pair : types_map){

        if (pair.second.name == type_name){
            type = pair.second;
            found_type = true;
        }

    }

    //make sure the type name requested does belong to one of the types in the types map
    if (found_type == false){        
        error_vector.push_back("ERROR: No type named " + type_name);
        return error_vector;
    }

    //loop through the type map, test combos, and find the best one
    for (auto const &pair : types_map){
        other_type = pair.second;
        other_type_name = other_type.name;

        // make sure we're not checking the combination of a type with itself
        if (type_name != other_type_name){
            combo = type.getCombo(other_type);
            num_resistances = int(combo.resistances.size());
            
            if(num_resistances > max_resistances){
                max_resistances = num_resistances;
                
            }

            combo_holder.push_back(combo); 
        
        }
    }

    // now that we have the highest number of resistances of all the combinations,
    // start from that highest number of resistances, then go down to 0
    // for each number of resistances, find the combination that has that number of resistances we're checking, 
    // then add that combo's name (with the current number of resistances added to the end in parentheses) to the returned vector
    for (int current_r = max_resistances; current_r >= 0; current_r--){
        
        for (int i = 0; i < int(combo_holder.size()); i++){
            
            combo = combo_holder[i];
            
            num_resistances = int(combo.resistances.size());
            
            if (num_resistances == current_r){
                combo_with_count = combo.name;
                combo_with_count += "(" + to_string(num_resistances) + ")";
                combo_names.push_back(combo_with_count);
            }
        }
        
    }   
    
    return combo_names;
}
//prints the weaknesses of every combination of type type_name (not including the type and itself)
vector<string> findLeastWeaknesses(string type_name, map <string, PkmnType> types_map){
    PkmnType type("", {}, {}, {}, {}, {}, {});
    bool found_type = false;
    vector<string> error_vector;

    PkmnType combo("", {}, {}, {}, {}, {}, {});
    
    string other_type_name;
    PkmnType other_type("", {}, {}, {}, {}, {}, {});
    
    int num_weaknesses;
    bool num_weaknesses_set = false;
    int least_weaknesses;
    int max_weaknesses; //needed to set the upper limit when we print each combination by weaknesses
    
    vector < PkmnType > combo_holder;
    vector < string > combo_names;

    string title_string = "Weaknesses of " + type_name + "-Type Combinations:";
    combo_names.push_back(title_string);

    string combo_with_count;

    //set the type variable by finding type_name's associated object in the map
    for (auto const &pair : types_map){

        if (pair.second.name == type_name){
            type = pair.second;
            found_type = true;
        }

    }

    //make sure the type name requested does belong to one of the types in the types map
    if (found_type == false){
        cout << "ERROR: No type named " + type_name;
        error_vector.push_back("ERROR: No type named " + type_name);
        return error_vector;
    }

    //loop through the type map, test combos, and find the best one
    for (auto const &pair : types_map){
        other_type = pair.second;
        other_type_name = other_type.name;
        
        // make sure we're not checking the combination of a type with itself
        if (type_name != other_type_name){
            combo = type.getCombo(other_type);
            num_weaknesses = int(combo.weaknesses.size());
            
            //initialize num_weaknesses to the first tested combo's
            if (num_weaknesses_set == false){
                num_weaknesses = num_weaknesses;
                num_weaknesses_set = true;
            }

            // update least weaknesses if needed
            if(num_weaknesses < least_weaknesses){
                least_weaknesses = num_weaknesses;     
            }

            // update max weaknesses if needed
            if (num_weaknesses > max_weaknesses){
                max_weaknesses = num_weaknesses;
            }
            
            combo_holder.push_back(combo); 
            
        }
    }

    // now that we have the highest strength of all the combinations,
    // start from that highest strength, then go down to 0
    // for each strength, find the combination that has that number of strengths we're checking, 
    // then add that combo's name (with the current num_strengths added to the end in parentheses) to the returned vector
    for (int current_w = least_weaknesses; current_w <= max_weaknesses; current_w++){
        
        for (int i = 0; i < int(combo_holder.size()); i++){
            num_weaknesses = combo_holder[i].weaknesses.size();
            
            if (num_weaknesses == current_w){
                combo_with_count = combo_holder[i].name;
                combo_with_count += "(" + to_string(num_weaknesses) + ")";
                combo_names.push_back(combo_with_count);
            }
        }
        
    }

    return combo_names;
}

vector<string> findMostStrengths(string type_name, map <string, PkmnType> types_map){
    PkmnType type("", {}, {}, {}, {}, {}, {});
    
    bool found_type = false;

    vector<string> error_vector;

    PkmnType combo("", {}, {}, {}, {}, {}, {});
    
    string other_type_name;
    PkmnType other_type("", {}, {}, {}, {}, {}, {});
    
    int num_strengths;
    int max_strengths = 0;

    vector < PkmnType > combo_holder;
    vector < string > combo_names;
    string title_string = "Strengths of " + type_name + "-Type Combinations: "; 
    combo_names.push_back(title_string);

    string combo_with_count;

    //set the type object by finding its associated object in the map
    for (auto const &pair : types_map){

        if (pair.second.name == type_name){
            type = pair.second;
            found_type = true;
        }

    }

    //make sure the type name requested does belong to one of the types in the types map
    if (found_type == false){
        cout << "ERROR: No type named " + type_name;
        error_vector.push_back("ERROR: No type named " + type_name);
        return error_vector;
    }

    //loop through the type map, test combos, and find the best one
    for (auto const &pair : types_map){
        other_type = pair.second;
        other_type_name = other_type.name;

        // make sure we're not checking the combination of a type with itself
        if (type_name != other_type_name){
            combo = type.getCombo(other_type);
            num_strengths = int(combo.strengths.size());
            
            if(num_strengths > max_strengths){
                max_strengths = num_strengths;
                
            }

            combo_holder.push_back(combo); 
        
        }
    }

    // now that we have the highest strength of all the combinations,
    // start from that highest strength, then go down to 0
    // for each strength, find the combination that has that number of strengths we're checking, 
    // then add that combo's name (with the current num_strengths added to the end in parentheses) to the returned vector
    for (int current_s = max_strengths; current_s >= 0; current_s--){
        
        for (int i = 0; i < int(combo_holder.size()); i++){
            
            combo = combo_holder[i];
            
            num_strengths = int(combo.strengths.size());
            
            if (num_strengths == current_s){
                combo_with_count = combo.name;
                combo_with_count += "(" + to_string(num_strengths) + ")";
                combo_names.push_back(combo_with_count);
            }
        }
        
    }
    //had to figure out how to insert a value at the front of an array
    //https://www.geeksforgeeks.org/vector-insert-function-in-c-stl/   
    return combo_names;
}

vector<string> removeRepeats(vector<string> string_vector){
    vector<string> copy_vec = string_vector;
    vector<string> returned_vec;
    returned_vec.push_back(string_vector[0]);

    string current_item;
    bool repeated;
    
    // for each item in the copy vector
    for (int i = 0; i < int(copy_vec.size()); i++){
        current_item = copy_vec[i];
        repeated = false;

        //check if the item is already in the returned vector
        for (int j = 0; j < int(returned_vec.size()); j++){
            if (returned_vec[j] == current_item){
                repeated = true;
            }
        }

        // if the current item is not already in the returned vector, add it
        if (repeated == false){
            returned_vec.push_back(current_item);
        }

    }

    return returned_vec;
}

//takes a number, one of the findMost/findLeastInteraction functions, and the types map
// returns an array with all the combinations that have the desired number when running the given function
// ex: all the type combinations that have 2 resistances
vector<string> returnAll(int desired_count, map<string, PkmnType> types_map, vector<string> (*findInteraction)(string, map<string, PkmnType>) ){
    PkmnType type("", {}, {}, {}, {}, {}, {});
    vector<string> combo_vector;
    vector<string> all_combos;
    vector<string> returned_combos = {};
    string combo_str;
    //string type_name;
    
    //loop through each type and get the counts for all the combos with that type
    for (auto const &pair : types_map){
        const string type_name = pair.second.name;
        cout << type.name << "\n";
        combo_vector = findInteraction(type_name, types_map);
        
        //add each string in the combo vector to the all_combos vector
        for (int i = 0; i < int(combo_vector.size()); i++){
            all_combos.push_back(combo_vector[i]); 
        }
    } 
    
    //loop through the entire array and for each combo string, see if its count is equal to the desired count. 
    //If so, add that entire combo string to the returned_combos vector
    for (int i = 0; i < int(all_combos.size()); i++){
        combo_str = all_combos[i];

        auto count = combo_str[combo_str.length() - 2]; //the count should be the second to last character in the string - "type-combo(c)"
        
        //https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-c
        if (count - '0' == desired_count){
            returned_combos.push_back(combo_str);
        }

    }
    

    //removeRepeats(returned_combos); //make sure we don't have the same combination more than once    
    return returned_combos;
}

/*
void findCombosWith(int num, string interaction, map<string, PkmnType> types_map){
    vector<string> choices = {"'s' for strengths", "'w' for weaknesses", "'r' for resistances", "'num' to get all the combinations with a certain number of a category-\n    ex: get all the combinations with exactly 3 weaknesses"};
    
    vector<string> printed_combos;
    string type_name;

    if (interaction == "s"){
        cin << type_name;
        printed_combos = findMostStrengths(type_name);

    } else if (interaction == "w"){
        returnAll


    } else if (interaction == "r"){

    
    } else if (interaction == "num"){
        string interaction_name;
        cin << interaction_name;

        int count; 
        cin << count;

        <string>
        if (interaction_name == "s"){
            
        }

        printed_combos = returnAll(count, func, types_map);

    } else {
        cout << "ERROR: only ";
        print1DVector(choices);
        cout << "are allowed";
    }
}
*/

bool keyIsIn(string key, map <string, PkmnType> types_map){
    if (types_map.find(key) == types_map.end()){
        return false;
    } else {
        return true;
    }
}
/*
void askUser(map <string, PkmnType> types_map){
    string actions[] = {"1: Get all the stats of a single type combination", "2: The strengths, of each combination with a given type", "3: The weaknesses, of each combination with a given type", "4: The resistances, of each combination with a given type"};

    for (int i = 0; i < int(sizeof(actions)/sizeof(actions[0])); i++){
        cout << actions[i] << "\n";
    }
    cout << "\n";

    string action;
    cout << "Enter a single number for what you'd like to choose.";
    cin >> action;

    string type_name1;
    string type_name2;
        
    PkmnType type1("", {}, {}, {}, {}, {}, {});
    PkmnType type2("", {}, {}, {}, {}, {}, {});

    if (action == "1"){
        cout << "please enter a type: \n";
        cin >> type_name1;
        cout << "please enter a second type: \n";
        cin >> type_name2;

        if (keyIsIn(type_name1, types_map) && keyIsIn(type_name2, types_map) ){
            type1 = types_map.find(type_name1)->second;
            type2 = types_map.find(type_name2)->second;
        }

        PkmnType combo = type1.getCombo(type2);

    } else if (action == "2"){
        cout << "please enter a type: \n";
        cin >> type_name1;
        findMostStrengths(type_name1, types_map);

    } else if (action == "3"){
        cout << "please enter a type: \n";
        cin >> type_name1;
        findLeastWeaknesses(type_name1, types_map);

    } else if (action == "4"){
        cout << "please enter a type: \n";
        cin >> type_name1;
        findMostResistances(type_name1, types_map);

    } else {
        cout << "ERROR-you haven't entered a number for one of the possible actions.";
        cout << "Please enter a single number representing one of the given actions.";
    }

}*/

map <string, PkmnType> loadTypesMap(){
    std::map <string, PkmnType> types;
    // https://www.javatpoint.com/post/cpp-map-find-function
    PkmnType Grass("Grass", {"Water", "Ground", "Rock"}, {"Fire", "Grass", "Poison", "Flying", "Bug", "Dragon", "Steel"}, {}, {"Fire", "Ice", "Poison", "Flying", "Bug"}, {"Water", "Grass", "Electric", "Ground"}, {});
    PkmnType Fire ("Fire", {"Ice", "Bug", "Grass", "Steel"}, {"Fire", "Water", "Rock", "Dragon"}, {}, {"Water", "Ground", "Rock"}, {"Fire", "Grass", "Ice", "Bug", "Steel", "Fairy"}, {});
    PkmnType Water("Water", {"Fire", "Rock", "Ground"}, {"Water", "Grass", "Electric"}, {}, {"Electric", "Grass"}, {"Water", "Ice", "Fire"}, {});
    
    PkmnType Normal("Normal", {}, {"Rock", "Steel"}, {"Ghost"}, {"Fighting"}, {}, {"Ghost"});

    PkmnType Bug ("Bug", {"Grass", "Psychic", "Dark"}, {"Fire", "Fighting", "Poison", "Flying", "Ghost", "Steel", "Fairy"}, {}, {"Fire", "Flying", "Rock"}, {"Grass", "Fighting", "Ground"}, {});

    PkmnType Flying("Flying", {"Grass", "Fighting", "Bug"}, {"Electric", "Rock", "Steel"}, {}, {"Rock", "Ice", "Electric"}, {"Grass", "Fighting", "Bug"}, {"Ground"});
    PkmnType Electric("Electric", {"Water", "Flying"}, {"Grass", "Electric", "Dragon"}, {"Ground"}, {"Ground"}, {"Electric", "Flying", "Steel"}, {});

    PkmnType Rock ("Rock", {"Fire", "Ice", "Flying", "Bug"}, {"Fighting", "Ground", "Steel"}, {}, {"Water", "Grass", "Fighting", "Ground", "Steel"}, {"Normal", "Fire", "Poison", "Flying"}, {});
    PkmnType Ground("Ground", {"Fire", "Electric", "Poison", "Rock", "Steel"}, {"Grass", "Bug"}, {"Flying"}, {"Water", "Grass", "Ice"}, {"Poison", "Rock"}, {"Electric"});
    
    PkmnType Fighting("Fighting", {"Normal", "Ice", "Rock", "Dark", "Steel"}, {"Poison", "Flying", "Psychic", "Bug", "Fairy"}, {"Ghost"}, {"Flying", "Psychic", "Fairy"}, {"Bug", "Rock", "Dark"}, {});
    PkmnType Psychic("Psychic", {"Fighting", "Poison"}, {"Psychic", "Steel"}, {"Dark"}, {"Bug", "Ghost", "Dark"}, {"Fighting", "Psychic"}, {});
    PkmnType Dark("Dark", {"Psychic", "Ghost"}, {"Fighting", "Dark", "Fairy"}, {}, {"Fighting", "Bug", "Fairy"}, {"Ghost", "Dark"}, {"Psychic"});
    PkmnType Ghost("Ghost", {"Psychic", "Ghost"}, {"Dark"}, {"Normal"}, {"Ghost", "Dark"}, {"Poison", "Bug"}, {"Normal", "Fighting"});

    PkmnType Ice ("Ice", {"Grass", "Ground", "Flying", "Dragon"}, {"Fire", "Water", "Ice", "Steel"}, {}, {"Fire", "Fighting", "Rock", "Steel"}, {"Ice"}, {});
    PkmnType Steel("Steel", {"Ice", "Rock", "Fairy"}, {"Fire", "Water", "Electric", "Steel"}, {}, {"Fire", "Fighting", "Ground"}, {"Normal", "Grass", "Ice", "Flying", "Psychic", "Bug", "Rock", "Dragon", "Steel", "Fairy"}, {"Poison"});
    PkmnType Poison("Poison", {"Grass", "Fairy"}, {"Poison", "Ground", "Rock", "Ghost"}, {"Steel"}, {"Ground", "Psychic"}, {"Grass", "Fighting", "Poison", "Bug", "Fairy"}, {});
    
    PkmnType Fairy("Fairy", {"Fighting", "Dragon", "Dark"}, {"Fire", "Posion", "Steel"}, {}, {"Poison", "Steel"}, {"Fighting", "Bug", "Dark"}, {"Dragon"});
    PkmnType Dragon("Dragon", {"Dragon"}, {"Steel"}, {"Fairy"}, {"Ice", "Dragon", "Fairy"}, {"Fire", "Water", "Grass", "Electric"}, {});

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

    return types;
}

int main() {
    std::map <string, PkmnType> types;
    types = loadTypesMap();
    // https://www.javatpoint.com/post/cpp-map-find-function
    PkmnType Grass = types.find("Grass")->second;
    PkmnType Fire = types.find("Fire")->second;
    PkmnType Water = types.find("Water")->second;
    PkmnType Normal = types.find("Normal")->second;
    PkmnType Bug = types.find("Bug")->second;
    PkmnType Flying = types.find("Flying")->second;
    PkmnType Rock = types.find("Rock")->second;
    PkmnType Ground = types.find("Ground")->second;
    PkmnType Fighting = types.find("Fighting")->second;
    PkmnType Psychic = types.find("Psychic")->second;
    PkmnType Dark = types.find("Dark")->second;
    PkmnType Ghost = types.find("Ghost")->second;
    PkmnType Ice = types.find("Ice")->second;
    PkmnType Steel = types.find("Steel")->second;
    PkmnType Poison = types.find("Poison")->second;
    PkmnType Electric = types.find("Electric")->second;
    PkmnType Fairy = types.find("Fairy")->second;
    PkmnType Dragon = types.find("Ghost")->second;

    PkmnType some_combo = Fairy.getCombo(Ghost);
    
    //https://www.javatpoint.com/post/cpp-map-find-function
    //https://www.techiedelight.com/print-keys-values-map-cpp/

    vector<string> normal_strengths = findMostStrengths("Fighting", types);
    print1DVector(normal_strengths);
    print1DVector(findLeastWeaknesses("Fighting", types));
    print1DVector(findMostResistances("Fighting", types));
    
    print1DVector(returnAll(2, types, &findLeastWeaknesses));


    return 0;
}
