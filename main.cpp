//  main.cpp
//  Created by lindsey anne on 5/2/16.
//  Copyright © 2016 lindsey anne. All rights reserved.

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    int m = 0; // counter for rows
    
    // open the file containing the matrix
    ifstream inStream;
    inStream.open("test.txt");
    
    if(inStream.fail()){ // always test to be sure file opens
        cout << "Test file does not exist." << endl << endl;
    }
    
    else{
        // use a vector to determine the size of the matrix
        string line;
        vector<char> vector;
        
        while(!inStream.eof()){
            getline(inStream, line);
            for(int i = 0; i < line.length(); i++){
                // ignore any spaces in the line
                if(!((line.at(i) >= 'a') && (line.at(i) <= 'z'))){
                    continue;
                }
                else{
                    vector.push_back(line.at(i));
                }
            }
            m++; // add a row everytime a line is read
        }
        
        // now make it into a matrix that we can use
        int n = (int)vector.size() / m; // n columns
        
        char matrix[m][n];
        int i, j; // min indices for row & column
        int k; // iterator for counting
        
        for(j = 0; j<m ; j++){
            for(i = 0; i<n; i++){
                matrix[j][i] = vector[i + j*n];
            }
        }
        
        i = 0;
        j = 0;
        
        // printing in spiral form by treating matrix as a series of nested boxes
        while(j<m && i<n){
            // print first row
            for(k = i; k < n; k++){
                cout << matrix[j][k];
            }
            j++;
            
            // print last column
            for(k = j; k < m; k++){
                cout << matrix[k][n-1];
            }
            n--;
            
            // print last row
            for(k = n-1; k >= i; k--){
                cout << matrix[m-1][k];
            }
            m--;
            
            // print first column
            for(k = m-1; k >= j; k--){
                cout << matrix[k][i];
            }
            i++;
        }
    }
    cout << endl;
    return 0;
} // end main
