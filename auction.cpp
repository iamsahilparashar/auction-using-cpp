#include<bits/stdc++.h>
using namespace std;

#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define init(a) int a;cin>>a;
#define vi vector<int>
#define pi pair<int,int>
#define que queue<int>
#define sta stack<int>
#define ll long long
#define lb cout<<endl
#define mod 1000000007
#define cin(a) int i;for(auto &i:a)cin>>i
#define cout(a) int j;for(auto &j:a)cout<<j

void auction_start(void);

class product {
    int pID;
    char name[50];
    float price , qty , tax ,dis;
    char diss[100];

    public:
    void create_product(){
        cout<<"\n   Please Enter The Product ID -> ";
        cin>>pID;

        cout<<"\n   Please Enter The Name Of The Product -> ";
        cin.ignore();
        cin.getline(name,50);

        cout<<"\n   Please Enter The Price Of The Product -> ";
        cin>>price;

        cout<<"\n   Please Enter The Description -> ";
        cin.ignore();
        cin.getline(diss,100);

    } 

    void show_product(){
        cout<<"\nProduct ID : "<<pID;lb;
        cout<<"\nProduct Name : "<<name;lb;
        cout<<"\nProduct Price : "<<price;lb;
        cout<<"\nProduct Description : "<<diss;lb;
        cout<<"-------------------------";lb;
    }

    int getpID(){
        return pID;
    }

    char* getname(){
        return name;
    } 

    float getprice(){
        return price;
    }

    char*  getdiss(){
        return diss;
    }
};

vector<product>all_products;

void buying_product(int id){
    for(auto i : all_products){
        if(i.getpID() == id){
            cout<<"\n----------CONGRATULATIONS! you have successfully bought..."<<i.getname()<<endl;
        }
        else{
            cout<<"\n----------ERROR! no product with this ID was found----------\n";
        }
    }
}

void Customer(){
    cout<<"\n\n======================WELCOME SIR/MAM==========================\n";
    cout<<"\n\n             1. DISPLAY ALL PRODUCTS";
    cout<<"\n\n             2. BUY A PRODUCT";
    cout<<"\n\n             3. RETURN TO MAIN MENU";
    cout<<"\n\n            Please Select Your Option (1-3)     ";

    int choice;
    cin >> choice;

    if(choice == 1){
        for(auto i : all_products){
            i.show_product();
        }
        Customer();
    }

    else if(choice == 2){
        cout<<"\n Enter THE PRODUCT ID -> ";
        int pID;
        cin >> pID;
        buying_product(pID);
        Customer();

    }
    else if(choice == 3){
        auction_start();
    }

}

void Adminstration(){
    cout<<"\n\n==============================================================\n";
    cout<<"\n                        ADMIN MENU\n";
    cout<<"\n\n             1. CREATE PRODUCT";
    cout<<"\n\n             2. DISPLAY ALL PRODUCTS";
    cout<<"\n\n             3. RETURN TO MAIN MENU";
    cout<<"\n\n            Please Select Your Option (1-3)     ";

    int choice;
    cin >> choice;

    if(choice == 1){
        product pr;
        pr.create_product();
        all_products.push_back(pr);
        cout<<"\nProduct created successfully!\n";
        Adminstration();
    }
    else if(choice == 2){
        for(auto i : all_products){
            i.show_product();
        }
        Adminstration();
    }
    else if(choice == 3){
        auction_start();
    }

}

void auction_start(){
    cout<<"\n<----------------------- MAIN MENU ----------------------->\n";
    cout<<"\n\n             1. ADMINISTRATOR             ";
    cout<<"\n\n             2. CUSTOMER        ";
    cout<<"\n\n             3. EXIT                 ";
    cout<<"\n\n            Please Select Your Option (1-3)     ";

    int choice;
    cin >> choice;

    if(choice == 1){
        Adminstration();
    }
    else if(choice == 2){
        Customer();
    }
    else if(choice == 3){
        cout<<"\n            Successfully Exit! \n";
        return ;
    }
}
int main()
{
    auction_start();
    return 0;
}