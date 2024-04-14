#include <iostream>
#include <algorithm>
using namespace std;

#define max 5
int data[max];
int top = 0;

bool isEmpty(){
    if(top == 0){
        return true;
    } else {
        return false;
    }
}

bool isFull(){
    if(top >= max){
        return true;
    } else {
        return false;
    }
}

void display(){
    if(!isEmpty()){
        cout << "Data Tersimpan :" << endl;
        for(int a =0; a< top; a++){
            cout << a+1 << ". " << data[a] << endl;
        }
    } else {
        cout << "Data tidak tersedia" << endl;
    }
    
    if(isFull()){
        cout << "stack Penuh" << endl;
    }
    cout << endl;
}

void push(){
    if(!isFull()){
        cout << "Masukkan Data : ";
        cin >> data[top];
        top++;
    }
}

void pop(){
    if(!isEmpty()){
        top--;
    }
}

void rata(){
    if(!isEmpty()){
        int total = 0;
        for(int a =0; a<top; a++){
            total += data[a];
        }
        cout << "Nilai rata-rata: " << total / top << endl;
    }
}

void modus(){
    if(!isEmpty()){
        sort(data, data + top);
        int counter = 1;
        int max_count = 0;
        int mode = data[0];
        for (int i = 1; i < top; i++){
            if (data[i] == data[i-1]){
                counter++;
            } else {
                if (counter > max_count){
                    max_count = counter;
                    mode = data[i-1];
                }
                counter = 1;
            }
        }
        if (counter > max_count){
            max_count = counter;
            mode = data[top-1];
        }
        cout << "Nilai modus: " << mode << endl;
    }
}

void median(){
    if(!isEmpty()){
        sort(data, data + top);
        int mid = top / 2;
        if (top % 2 == 0){
            cout << "Nilai median: " << (data[mid-1] + data[mid]) / 2 << endl;
        } else {
            cout << "Nilai median: " << data[mid] << endl;
        }
    }
}

int main(){
    int pil;
    int isi;
    
    stack :
        system("cls");
        display();
        cout << "Menu utama\n1. Push\n2. Pop\n3. Rata-rata, Modus, Median\nPilih: ";
        cin >> pil;
        if(!cin){
            cin.clear();
            cin.ignore();
            goto stack;
        }
        else if(pil == 1){
            system("cls");
            push();
            goto stack;
        } else if (pil == 2){
            system("cls");
            pop();
            goto stack;
        } else if (pil == 3){
            cout << "Cari rata-rata" << endl;
            
                rata();

            if(!isEmpty()){
            modus();  
            median();
            }else {
                cout << "Belum mencapai data maksimum" << endl;

            }
        }else {
    
        }
}
