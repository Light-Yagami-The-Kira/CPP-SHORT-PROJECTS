#include <iostream>
#include <vector>

using namespace std;

template <class T>
int permutation_finder(vector<T> &main,vector<T> &elem)
{
    int counter = 0;
    int elem_size = size(elem);
    int main_size = size(main);
    bool truth_val[elem_size] = {};
    for (int i=0; i<=(main_size - elem_size); i++)  //THIS LOOP IS FOR THE POINTER GOING THROUGH THE MAIN ARRAY ELEMENTS
    {
        bool truth_val_all_true = true;  // IT HELPS TO KEEP TRACK IF THE ALL VALUES OF TRUTH ARRAY ARE EITHER TRUE OR FALSE
// IF ALL VALUES ARE TRUE IT MEANS ALL ELEMENTS ARE IN THE PERMUTATIONS        
        for (int i=0; i<elem_size; i++) // BY DEFAULT ASSIGNS FALSE VALUES TO TRUTH 
        {
            truth_val[i] = false;
        }
        for (int j=i; j<=i+3; j++) // TAKES A SELECTED PIECE OF ARRAY AND CHECKS IT
        {
            for (int k=0; k<elem_size; k++)
            {
                if (main[j]==elem[k]) // IF VALUE IS MATHCED IT ALTERS THE TRUTH VALUE
                {
                    truth_val[k] = not truth_val[k];
                }
            }
        }
        for (int m=0; m<elem_size; m++)  // GOES THROUGH TRUTH ARRAY AND IF ANY TRUTH VALUE IS FALSE IT SETS TRUTH_VAL_ALL_TRUE TO FALSE
        {
            if(truth_val[m]==false)
            {
                truth_val_all_true = false;
                break;
            }
        }
        if (truth_val_all_true == true) // IF TRUTH_VAL_ALL_TRUE = TRUE WHICH MEANS ALL VALUES OF TRUTH ARRAY ARE TRUE IT INCREASES THE COUNTER THAT ALL PERMUTATION VALUES ARE FOUND
        {
            ++counter; 
        }
    }
    return counter;
}
int main(){
    vector<int> main = {1,3,2,4,5,453,564,1,2,3,4,4,4,4,3,2,1,2,3,4};
    vector<int> elem = {1,3,4,2};
    cout<<permutation_finder(main, elem);
    return 0;
}