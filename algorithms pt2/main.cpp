#include <iostream>
#include <vector>
#include <map>
#include <optional>
#include <string>
#include <string.h>
#include <array>
#include <stdlib.h>
#include <iomanip>
#include <algorithm>
#include <stack>
#include "SortingAlgorithm.h"
using namespace std;


#pragma region structs
struct Grid{
    int row;
    int col;

    Grid(int _row , int _col){
        row = _row;
        col = _col;
    }

    void NewGrid(int _row , int _col){
        row = _row;
        col = _col;
    }

    bool isOneByOne(){
        if (row == 1 && col == 1 ) return true;
        return false;
    }
    bool RealGrid(){
        if (col == 0 || row == 0) return false;
        return true;
    }

    bool operator == (const Grid& grid2) const {
        return (row == grid2.row && col == grid2.col);
    }



    bool operator<(const Grid &o)  const {
        return row < o.row || (row == o.row && col < o.col);
    }

};

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int _data){
        data = _data;
        left = nullptr;
        right = nullptr;
    }

};

struct ListNode{
    int cost;
    int gas;
    ListNode* next;

    ListNode(int _gas, int _cost){
        gas = _gas;
        cost = _cost;
        next = nullptr;
    }
};

struct BinaryTree{
    TreeNode* Root;
    BinaryTree(int _data){
        Root = new TreeNode(_data);
    }

    void MakeTree(){
        Root->left = new TreeNode(5);
        Root->right = new TreeNode(5);

        Root->left->left = new TreeNode(2);
        Root->left->right = new TreeNode(8);

        Root->right->left = new TreeNode(8);
        Root->right->right = new TreeNode(2);

        Root->left->right->left = new TreeNode(1);
        Root->right->left->right = new TreeNode(1);

        Root->right->right->right = new TreeNode(9);
        Root->right->right->left = new TreeNode(4);

        Root->left->left->left = new TreeNode(9);
        Root->left->left->right = new TreeNode(7);

        Root->left->left->left->left = new TreeNode(3);
        Root->left->left->left->right = new TreeNode(0);

        Root->left->left->right->right = new TreeNode(6);

        Root->right->right->right->right = new TreeNode(3);
        Root->right->right->right->left = new TreeNode(0);

        Root->right->right->left->left = new TreeNode(6);
    }

};

struct CircularLinkedList{
    ListNode* head;
    ListNode* tail;

    CircularLinkedList(int _gas, int _cost){
        head = new ListNode(_gas,_cost);
        LinkLastNode();
    }

    void LinkLastNode(){
        ListNode* tempNode = head;
        while(tempNode->next != nullptr){
            tempNode = tempNode->next;
        }
        tail = tempNode;
        tail->next = head;
    }

    void AddNode(int _gas, int _cost){
        ListNode* tempNode = head;
        while(tempNode->next != nullptr){
            tempNode = tempNode->next;
        }
        tempNode->next = new ListNode(_gas, _cost);
        LinkLastNode();
    }

    void AddNode(int _gas, int _cost, int pos){

        try{
            if (pos < ListSize()){
                ListNode* tempNode = head;
                ListNode* newNode = new ListNode(_gas, _cost);
                for (int i = 0; i < pos - 1; ++i) {
                    tempNode = tempNode->next;
                }
                newNode->next = tempNode->next;
                tempNode->next = tempNode;
            } else{
                throw pos;
            }
        }catch (int x){
            cerr << "Error: Out Of Bounds" << endl;
        }

        LinkLastNode();
    }

    int ListSize(){
        int size = 1;
        ListNode* tempNode = head;
        while(tempNode->next != nullptr){
            size++;
            tempNode = tempNode->next;
        }
        size++;
        return size;
    }
    void PrintList(){
        ListNode* tempNode = head;
        while(tempNode != nullptr){
            printf("|The gas is %d -> The cost is %d ", tempNode->gas, tempNode->cost);
            tempNode = tempNode->next;
            if (tempNode == tail){
                break;
            }
        }
    }

};

#pragma endregion

#pragma region DynamicProgramming

#pragma region Memoization
long long Fib(long long n);
long long Fib2(long long n);
long long gridTraveller(Grid grid);
bool CanSum(int targetSum, vector<int> &vec);
bool howsum(int n,int m,vector<int>a);
optional<vector<int>> BestSum(int targetSum,vector<int>a);
optional<vector<int>>HowSum(int targetSum, const std::vector<int>& numbers);
bool CanConstruct(string target, vector<string> wordbank, int size);

map<long long, long long> memoFib;
map<Grid, long long> memoGrid;
map<int, bool> memoSum;
map<string, bool> memoConstruct;
map<int, vector<int>> memoBestSum;
int check[10000];
vector<int> v;// vector where you store the results if the sum exists (basically the numbers that sum up to the target number)
#pragma endregion

#pragma region Tabulation
long long FibTab(long long n);
long long gridTravellerTab(int m, int n);
bool CanSumTab(int targetSum, vector<int> &vec);
optional<vector<int>> BestSumTab(int n,vector<int>a);
optional<vector<int>>HowSumTab(int n, const vector<int>& a);
bool CanConstructTab(string target, vector<string> wordbank, int size);
#pragma endregion

void CallFib();
void CallGridTravellers();
void CallCanSum(vector<vector<int>> &canSumVect, vector<int> &targetSums);
void CallHowSum(vector<vector<int>> &canSumVect, vector<int> &targetSums);
void CallBestSum(vector<vector<int>> &canSumVect, vector<int> &targetSums);
void CallCanConstruct(vector<vector<string>> &wordbanks, vector<string> &targets);

#pragma endregion

#pragma region InterviewProblems

bool AreAnagrams(string s1, string s2);
bool AreAnagrams2(string s1, string s2);
void convertToLower(string* InputString);

vector<int> FirstAndLastIndex(vector<int> arr, int target);

int KthLargestElement(vector<int> arr, int k);
int KthLargestElement2(vector<int> arr, int k);

bool AreSymmetric(TreeNode* root1, TreeNode* root2);
bool IsSymmetric(BinaryTree* baseRoot);
//generate parentheses
bool IsValid(vector<char> combination);
bool IsValid2(vector<char> combination);
//...
//...
int GasStation(vector<int> gas, vector<int> cost);
bool CanTraverse(vector<int> gas, vector<int> cost, int start);


void CallAnagrams();
void CallFirstAndLastIndex();
void CallKthLargestElements();
void CallIsSymmetric();
void CallGasStation();


#pragma endregion



int main() {

#pragma region DynamicArrays
    vector<vector<int>> canSumVect {
            {2,3},
            {5,3,4,7},
            {2,4,},
            {2,3,5},
            {7,14},
            {1,4,5},
            {1,2,5,25}
    };
    vector<int> targetSums = {7,7,7,8,300,100};


    vector<vector<string>> wordbanks{
            {"ab","abc","cd","def","abcd",},
            {"bo","rd","ate","t","ska","sk", "boar"},
            {"a","p","ent","enter","ot","o", "t"},
            {"e","ee","eee","eeee","eeeee","eeeeee"}
    };
    vector<string> targets = {"abcdef", "skateboard", "enterapotentpot", "eeeeeeeeeeeeeeeeeeeeeeeeeeef"};
#pragma endregion

    /*
    CircularLinkedList* Road = new CircularLinkedList(1,1);

    for (int i = 2; i < 5; ++i) {
        Road->AddNode(i,i);
    }
    //Road->PrintList();
     */
    //CallGasStation();

    int arr[] = {3,2,5,1,4};
    int size = sizeof(arr)/ sizeof(arr[0]);


    SortingAlgorithms::BubbleSort(arr,size);

    for (int i = 0; i < size; ++i) {
        cout << arr[i] << endl;
    }

    return 0;
}

#pragma region CallDynamicProgramming
void CallFib(){
    cout <<  setw(25) << "Memoization" << endl;
    cout << Fib(6) <<endl;
    cout << Fib(7) <<endl;
    cout << Fib(8) <<endl;
    cout << Fib(20) <<endl;
    cout << Fib(70) <<endl;

    cout <<  setw(25) << "Tabulation" << endl;
    cout << FibTab(6) << endl;
    cout << FibTab(7) << endl;
    cout << FibTab(8) << endl;
    cout << FibTab(50) << endl;
}
void CallGridTravellers(){
    cout <<  setw(25) << "Memoization" << endl;
    Grid grid(1,1);

    cout << gridTraveller(grid) <<endl;
    grid.NewGrid(2,3);

    cout << gridTraveller(grid) <<endl;
    grid.NewGrid(3,2);

    cout << gridTraveller(grid) <<endl;
    grid.NewGrid(3,3);

    cout << gridTraveller(grid) <<endl;
    grid.NewGrid(18,18);

    cout << gridTraveller(grid) <<endl;

    cout <<  setw(25) << "Tabulation" << endl;
    cout << gridTravellerTab(1,1) <<endl;
    cout << gridTravellerTab(2,3) <<endl;
    cout << gridTravellerTab(3,2) <<endl;
    cout << gridTravellerTab(3,3) <<endl;
    cout << gridTravellerTab(18,18) <<endl;

}
void CallCanSum(vector<vector<int>> &canSumVect, vector<int> &targetSums){
    cout <<  setw(25) << "Memoization" << endl;
    if (CanSum(targetSums[0], canSumVect[0])){
        cout << "true " << endl;
    }else{
        cout << "false" << endl;
    }

    cout <<  setw(25) << "Tabulation" << endl;

    for (int i = 0; i < 5; ++i) {
        if (CanSumTab(targetSums[i], canSumVect[i])){
            cout << "true " << endl;

        }else{
            cout << "false" << endl;
        }

    }
}
void CallHowSum(vector<vector<int>> &canSumVect, vector<int> &targetSums){
    cout <<  setw(25) << "Memoization" << endl;
    if(howsum(targetSums[3],canSumVect[3].size(),canSumVect[3])==true){
        cout<<"yes"<<endl;
        for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
        cout<<endl;
    }
    else
        cout<<"no ans"<<endl;

    cout <<  setw(25) << "Optional Memoization" << endl;
    optional<vector<int>> sum = HowSum(targetSums[3], canSumVect[3]);
    for (int i = 0; i < sum->size(); ++i) {

        cout << sum->at(i) << " ";
    }

    cout << endl;

    cout <<  setw(25) << "Tabulation" << endl;
    optional<vector<int>> sumTab = HowSumTab(targetSums[3], canSumVect[3]);
    for (int i = 0; i < sumTab->size(); ++i) {

        cout << sumTab->at(i) << " ";
    }
    cout << endl;

}
void CallBestSum(vector<vector<int>> &canSumVect, vector<int> &targetSums){

    cout <<  setw(25) << "Optional Memoization" << endl;
    optional<vector<int>> bestSum = BestSum(targetSums[5], canSumVect[6]);
    for (int i = 0; i < bestSum->size(); ++i) {

        cout << bestSum->at(i) << endl;
    }

    cout <<  setw(25) << "Optional Tabulation" << endl;
    optional<vector<int>> bestSumTab = BestSumTab(targetSums[5], canSumVect[6]);
    for (int i = 0; i < bestSumTab->size(); ++i) {
        cout << bestSumTab->at(i) << " ";
    }
}
void CallCanConstruct(vector<vector<string>> &wordbanks, vector<string> &targets){

    cout <<  setw(25) << "Memoization" << endl;
    for (int i = 0; i < 4; ++i) {
        if (CanConstruct(targets[i], wordbanks[i], wordbanks[i].size())){
            cout << "you can construct" << endl;
        }else{
            cout << "you cant" << endl;
        }
    }

    cout <<  setw(25) << "Tabulation" << endl;
    for (int i = 0; i < 4; ++i) {
        if (CanConstructTab(targets[i], wordbanks[i], wordbanks[i].size())){
            cout << "you can construct" << endl;
        }else{
            cout << "you cant" << endl;
        }
    }
}
#pragma endregion

#pragma region DynamicProgrammingFunctions
long long Fib(long long n){
    if (memoFib.count(n) > 0) {

        return memoFib.at(n);
    }
    if (n <= 2 ) return 1;
    memoFib.emplace(n, Fib(n - 1) + Fib(n - 2));
    return memoFib.at(n);
}

long long Fib2(long long n){

    if (n <= 2 ) return 1;

    return Fib(n - 1) + Fib(n - 2);
}

long long gridTraveller(Grid grid){

    map<Grid, long long>::iterator it;


    it = memoGrid.find(grid);
    if (it != memoGrid.end())
        return memoGrid.at(grid);

    if (grid.isOneByOne()) return 1;
    if (!grid.RealGrid()) return 0;

    Grid grid1(grid.row-1,grid.col);
    Grid grid2(grid.row,grid.col-1);

    memoGrid.emplace(grid, gridTraveller(grid1) + gridTraveller(grid2));

    return gridTraveller(grid1) + gridTraveller(grid2);
}

bool CanSum(int targetSum, vector<int> &vec) {
    int remainder;
    if (memoSum.count(targetSum) > 0)
        return memoSum[targetSum];
     if (targetSum == 0)
        return true;
     if (targetSum < 0)
        return false;

        for (auto i : vec) {
            remainder = targetSum - i;
            if (CanSum(remainder, vec)) {
                memoSum.emplace(remainder, true);
                return true;
            }
        }
    memoSum.emplace(remainder, false);
    return false;
}

bool howsum(int n,int m,vector<int>a)
{
    if(n==0)
    {
        cout<<"hurrah"<<endl;
        return true;
    }
    if(n<0)return false;
    if(check[n]==1)return true;
    if(check[n]==-1)return false;
    for(int i=0; i<m; i++)
    {
        int r=n-a[i];
        if(howsum(r,m,a)==true)
        {
            v.push_back(a[i]);
            check[n]=1;
            return true;
        }
        else
        {
            check[n]=-1;
        }
    }
    return false;
}

optional<vector<int>>HowSum(int targetSum, const std::vector<int>& numbers) {
    if (targetSum == 0)
        return std::vector<int>{};
    if (targetSum < 0)
        return std::nullopt;
    for (auto numer : numbers) {
        const auto remainder = targetSum - numer;
        auto remainderResult = HowSum(remainder, numbers);
        if (remainderResult) {
            remainderResult->push_back(numer);
            return remainderResult;
        }
    }
    return std::nullopt;
}

optional<vector<int>> BestSum(int targetSum,vector<int>a){
    if (memoBestSum.count(targetSum) > 0){
        return memoBestSum[targetSum];
    }
    if (targetSum == 0)
        return vector<int>{};
    if (targetSum < 0)
        return nullopt;

    optional<vector<int>> shortestCombination = nullopt;

    for (int num : a) {
        int remainder = targetSum - num;
        auto SumResults = BestSum(remainder,a);
        if (SumResults){
           optional<vector<int>> combination = SumResults;
           combination->push_back(num);
           //if the combination is shorter than the current shortest
            if (combination->size() < shortestCombination->size() || shortestCombination == nullopt){
                shortestCombination = combination;
            }
        }
    }
    memoBestSum.emplace(targetSum, *shortestCombination);
    return shortestCombination;
}

bool CanConstruct(string target, vector<string> wordbank, int size){

    if (memoConstruct.count(target) > 0){
        return memoConstruct[target];
    }
    if (target.empty()){
        return true;
    }

    for (int i = 0; i < size; ++i) {
        int found=target.find(wordbank[i]);
        if(found==0) {
            string s;
            s=target;
            s.erase(0,wordbank[i].size());
            if ( CanConstruct(s, wordbank, size)){
                memoConstruct.emplace(target, true);

                return true;
            }
        }

    }
    memoConstruct.emplace(target, false);
    return false;

}

long long FibTab(long long n) {
    long long table[n+1];
    for (int i = 0; i <= n; ++i) {
        table[i] = 0;
    }
    table[1] = 1;

    for (int i = 2; i <= n; ++i) {
        table[i] = table[i-1] + table[i-2];
    }
     /*
    for (int i = 0; i <= n; i++) {
        table[i +1] += table[i];
        table[i +2] += table[i];
    }
    */
    return table[n];
}


long long gridTravellerTab(int m, int n){
    long long table[m+1][n+1];
    memset( table, 0, sizeof(table) );// this fills the 2d array with 0s
    table[1][1] = 1;
    for (int r = 0; r <= m; r++) {
        for (int c = 0; c <= n; c++) {

            auto current = table[r][c];
            if (c+1 <= n){
                table[r][c+1] += current;
            }
            if (r+1 <= m){
                table[r+1][c] += current;
            }

            //cout<< table[r][c] << " ";
        }
        //cout << endl;
    }
    cout << endl;
    return table[m][n];
}

bool CanSumTab(int targetSum, vector<int> &vec){
    bool table[targetSum + 1];
    memset(table, false, sizeof (table));

    table[0] = true;
    for (int i = 0; i <= targetSum; ++i) {
        if (table[i]){
            for (int num:vec) {
                table[i+num] = true;
            }
        }

    }

    return table[targetSum];
}

optional<vector<int>>HowSumTab(int n, const vector<int>& a){
    vector<optional<vector<int>>> table3(n+1);
    for (int i = 0; i < n+1; ++i) {
        table3[i] = nullopt;

    }
    vector<int> temp = { };
    table3[0] = temp;
    for (int i = 0; i < n+1; i++) {
        if (table3[i] != nullopt){

            for (int j = 0; j < a.size(); j++) {

                if (i + a[j] < n+1) {

                    table3[i + a[j]] = table3[i];
                    table3[i + a[j]]->push_back(a[j]);
                }
            }
        }
    }

    return table3[n];
}

optional<vector<int>> BestSumTab(int n,vector<int>a){
    vector<optional<vector<int>>> table3(n+1);
    for (int i = 0; i < n+1; ++i) {
        table3[i] = nullopt;

    }
    vector<int> temp = { };
    table3[0] = temp;
    for (int i = 0; i < n+1; i++) {
        if (table3[i] != nullopt){
            for (int j = 0; j < a.size(); j++) {
                if (i + a[j] < n+1) {
                    auto combination = table3[i];
                    combination->push_back(a[j]);
                    if (!table3[i +a[j]] || table3[i + a[j]]->size() > combination->size()){
                        table3[i + a[j]] = combination;

                    }
                }
            }
        }
    }

    return table3[n];
}

bool CanConstructTab(string target, vector<string> wordbank, int size){
    bool table[target.size() +1];
    memset(table, false, sizeof (table));
    table[0] = true;

    for (int i = 0; i < target.size() +1; ++i) {
        if (table[i] == true){

            for (string word : wordbank) {
                if (i + word.size() < target.size() + 1){

                if (strcmp( target.substr(i,word.size()).c_str(), word.c_str()) == 0){

                        table[i + word.size()] = true;
                    }

                }
            }
        }
    }
    return table[target.size()];
}
#pragma endregion

#pragma region CallInterviewProblemsFunctions

void CallAnagrams(){
    string s1 = "nameless";
    string s2 = "salesman";

    if (AreAnagrams(s1,s2)){
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }

    if (AreAnagrams2(s1,s2)){
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }
}

void CallFirstAndLastIndex(){
    vector<int> arr{2,4,5,5,5,5,5,7,9,9};

    vector<int> result = FirstAndLastIndex(arr,5);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

}

void CallKthLargestElements(){
    vector<int> arr { 4,2,9,7,5,6,7,1,3};
    int k =4;
    int KthElement = KthLargestElement(arr,k);
    printf("the %dth largest element is %d(if we dont include duplicate numbers as a position)\n",k , KthElement);

    KthElement = KthLargestElement2(arr,k);
    printf("the %dth largest element is %d",k , KthElement);
}

void CallIsSymmetric(){

    BinaryTree* binaryTree = new BinaryTree(4);
    binaryTree->MakeTree();
    if (IsSymmetric(binaryTree)){
        cout << "Binary tree is symmetric" << endl;

    }else{
        cout << "Binary tree is NOT symmetric" << endl;
    }

}

void CallGasStation(){
    vector<vector<int>> gas{
            {2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
            {1, 5, 3, 3, 5, 3, 1, 3, 4, 5}
    };
    vector<vector<int>> cost{
        {1,1,1,1,1,1,1,1,1,50},
        {5,2,2,8,2,4,2,5,1,2}
    };

    cout << "The gas station to start at is " + GasStation(gas[0], cost[0]);

}


#pragma endregion

#pragma region InterviewProblemsFunctions
bool AreAnagrams(string s1, string s2){
    if (strlen(s1.c_str()) != strlen(s2.c_str())) return false;
    convertToLower(&s1);
    convertToLower(&s2);
    map<char, int> anagram1;
    map<char, int> anagram2;
    for (char c: s1) {
        if (anagram1.count(c) > 0){
            anagram1[c]++;
        } else{
            anagram1.emplace(c,1);
        }
    }

    for (char c: s2) {
        if (anagram2.count(c) > 0){
            anagram2[c]++;
        } else{
            anagram2.emplace(c,1);
        }
    }

/*
    for (auto entry : anagram1) {
        auto k = entry.first;
        auto x = entry.second;

        if (anagram2.count(k) >=0 || anagram1[k] != anagram2[k]) {
            return false;
        }
    }
*/

    if (anagram1 == anagram2){
        return true;
    } else{
        return false;
    }

    return true;
}
bool AreAnagrams2(string s1, string s2){
    if (strlen(s1.c_str()) != strlen(s2.c_str())) return false;
    convertToLower(&s1);
    convertToLower(&s2);

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    if(strcmp(s1.c_str(),s2.c_str())){
        return true;
    }
    return false;

}
void convertToLower(string* InputString){
    for (char c: *InputString) {
        c = tolower(c);
    }
}

vector<int> FirstAndLastIndex(vector<int> arr, int target){
    //the array should be sorted
    int startIndex;
    int lastIndex;
    vector<int> indices;
    if (arr.size() == 0 || arr[0] > target || arr[arr.size()-1] < target) return vector<int> {-1,-1};
    //the array has no elements, the 1st element is greater than target
    //and the last element is less than target

    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == target){
            //startIndex = i;
            indices.push_back(i);
            while ((i+1 < arr.size()) && arr[i+1] == target){
                i += 1;
            }
            //lastIndex = i;
            indices.push_back(i);
            return indices;
        }
    }

    indices = {-1,-1};
    return indices;
}

int KthLargestElement(vector<int> arr, int k){
    //this is in the event you dont want to include the duplicate number
    for (int i = 0; i < k-1; ++i) {
        remove(arr.begin(), arr.end(), *max_element(arr.begin(),arr.end()));
    }

    return *max_element(arr.begin(),arr.end());
}
int KthLargestElement2(vector<int> arr, int k){
    //this is in the event you do want to include the duplicate number
    int n = arr.size();
    sort(arr.begin(),arr.end());

    return arr[n-k];
}

bool AreSymmetric(TreeNode* root1, TreeNode* root2){
    if (root1 == nullptr && root2 == nullptr){
        return true;
    } else if((root1 != nullptr && root2 == nullptr) || (root1 == nullptr && root2 != nullptr) ){
        return false;
    }
    else if (root1->data != root2->data){
        return false;
    }else{
        return (AreSymmetric(root1->left, root2->right) && AreSymmetric(root1->right, root2->left));
    }

}
bool IsSymmetric(BinaryTree* baseRoot){
    if (baseRoot->Root == nullptr){
        return true;
    }
    return AreSymmetric(baseRoot->Root->left, baseRoot->Root->right);
}

bool IsValid(vector<char> combination){
    stack<char> Parentheses;
    for (char par:combination) {
        if (par == '('){
            Parentheses.push(par);
        }else{
            if (Parentheses.size() == 0){//we dont perform the stack when its empty
                return false;
            } else{
                Parentheses.pop();
            }
        }
    }
    return Parentheses.size() == 0;//stack must be empty at the end otherwise it means we dont have a
    //proper parentheses
}
bool IsValid2(vector<char> combination){
    int diff = 0;
    for (char par:combination) {
        if (par == '('){
            diff++;
        }else{
            if (diff == 0){//we dont perform the stack when its empty
                return false;
            } else{
                diff--;
            }
        }
    }
    return diff == 0;//stack must be empty at the end otherwise it means we dont have a
    //proper parentheses
}

int GasStation(vector<int> gas, vector<int> cost){
    for (int i = 0; i < gas.size(); ++i) {
        if (CanTraverse(gas,cost,i)){
            return i;
        }
    }
    return -1;
}
bool CanTraverse(vector<int> gas, vector<int> cost, int start){
    int n = gas.size();
    int remaining = 0;
    int i = start;
    bool started = false;
    while(i != start || !started){
        started = true;
        remaining += gas[i] - cost[i];
        if (remaining < 0){
            return false;
        }
        i = (i+1)%n;
    }
}

#pragma endregion