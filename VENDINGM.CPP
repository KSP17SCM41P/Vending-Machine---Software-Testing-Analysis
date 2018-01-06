#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std; 
class VendingMachine {

public:
	VendingMachine() ;
	int coin();
	int small_cup() ;
	int large_cup();
	int sugar();
	int tea();
	int insert_large_cups(int);
	int insert_small_cups(int);
	int set_price(int p);
	int cancel() ;
	int dispose() ;
	void showvariable();
	

private:
int x;
int price;
int k;
int k1;
int t;
int s;

};

VendingMachine::VendingMachine() {
	k1=0;
	k=0;
	t=0;
	price=0;
	x=1;
}


int VendingMachine::coin() {
	if (x==1) {
		if ((t+25>=price)&&(price>0)) {
			s=0;
			t=0;
			x=2;
			return 1;
		}
		else if(t+25<price) {
			t=t+25;
			return 1;
		}
	}
	else if ((x>1)&&(x<6)) {
		std::cout<<"RETURN COIN"<<std::endl;
		return 1;
	}
	return 0;
}


int VendingMachine::small_cup() {
	if ((x==2)||(x==3)) {
		s=2;
		return 1;
	}
	return 0;
}

int VendingMachine::large_cup() {
	if ((x==2)||(x==3)) {
		s=1;
		return 1;
	}
	return 0;
}

int VendingMachine::sugar() {
	if ((x==2)||(x==3)) {
		if(x==2) x=3;
		else x=2;
		return 1;
	}
	return 0;
}


int VendingMachine::tea() {
	if ((x==2)||(x==3)) {
		if((x==2)&&(k1>1)&&(s==2)) {
			std::cout<<"DISPOSE SMALL CUP OF TEA"<<std::endl;
			k1=k1-1;
			x=1;
			return 1;
		}
		else if ((x==2)&&(k>1)&&(s==1)) {
			std::cout<<"DISPOSE LARGE CUP OF TEA"<<std::endl;
			k=k-1;
			x=1;
			return 1;
		}
		else if ((x==2)&&(k==1)&&(s==1)) {
			std::cout<<"DISPOSE LARGE CUP OF TEA"<<std::endl;
			k=k-1;
			x=5;
			return 1;
		}
		else if ((x==2)&&(k1==1)&&(s==2)) {
			std::cout<<"DISPOSE SMALL CUP OF TEA"<<std::endl;
			k1=k1-1;
			x=4;
			return 1;
		}
		else if ((x==3)&&(k1==1)&&(s==2)) {
			std::cout<<"DISPOSE SMALL CUP OF TEA WITH SUGAR"<<std::endl;
			k1=k1-1;
			x=4;
			return 1;
		}
		else if ((x==3)&&(k==1)&&(s==1)) {
			std::cout<<"DISPOSE LARGE CUP OF TEA WITH SUGAR"<<std::endl;
			k=k-1;
			x=5;
			return 1;
		}
		if((x==3)&&(k1>1)&&(s==2)) {
			std::cout<<"DISPOSE SMALL CUP OF TEA WITH SUGAR"<<std::endl;
			k1=k1-1;
			x=1;
			return 1;
		}
		else if ((x==3)&&(k>1)&&(s==1)) {
			std::cout<<"DISPOSE LARGE CUP OF TEA WITH SUGAR"<<std::endl;
			k=k-1;
			x=1;
			return 1;
		}
		return 0;
	}
	return 0;
}

int VendingMachine::insert_large_cups(int n) {
	if ((x==1)&&(n>0)) {
		k=k+n;
		return 1;
	}
	else if ((x==5)&&(n>0)) {
		k=n;
		x=1;
		return 1;
	}
	return 0;
}

int VendingMachine::insert_small_cups(int n) {
	if ((x==1)&&(n>0)) {
		k1=k1+n;
		return 1;
	}
	else if ((x==4)&&(n>0)) {
		k1=n;
		x=1;
		return 1;
	}
	return 0;
}

int VendingMachine::set_price(int p) {
	if ((x==1)&&(p>0)) {
		price=p;
		return 1;
	}
	return 0;
}


int VendingMachine::cancel() {
	if ((x==2)||(x==3)) {
		std::cout<<"RETURN COINS"<<std::endl;
		x=1;
		return 1;
	}
	return 0;
}

int VendingMachine::dispose() {
	if ((x==1)) {
		std::cout<<"SHUT DOWN"<<std::endl;
		x=6;
		return 1;
	}
	return 0;
}


void VendingMachine::showvariable()
{ 
std::cout<<"x ="<< VendingMachine::x <<"\n" ;
std::cout<<"k =" << k <<"\n";
std::cout<<"k1 =" << k1<<"\n";
std::cout<<"t =" << t <<"\n";
std::cout<<"price =" << price <<"\n" ;
std::cout<<"s =" << s <<"\n"; 
}
 
 int main()
 {
   int i,n,p;
   char ch,op;
   VendingMachine vm;
   do
   {
   //system("cls");  
   std::cout<<" \t	-----VENDING MACHINE MENU -----	"<<"\n";
   std::cout<<"-------------------------------------"<<"\n";
   std::cout<<"|| \t  1. Coin inserted "<<"\n";
   std::cout<<"|| \t  2. Small_cup()"<<"\n";
   std::cout<<"|| \t  3. Large_cup()"<<"\n";
   std::cout<<"|| \t  4. Sugar()	"<<"\n";
   std::cout<<"|| \t  5. Tea()"<<"\n";
   std::cout<<"|| \t  6. Inset_small_cup()"<<"\n";
   std::cout<<"|| \t  7. Insert_large_cup()"<<"\n";
   std::cout<<"|| \t  8. Set_Price"<<"\n";
   std::cout<<"|| \t  9. Dispose"<<"\n";
   std::cout<<"|| \t  0. Cancel()"<<"\n";
   std::cout<<"|| \t  s. Show variables()"	<<"\n";
   std::cout<<"---------------------------------------"<<"\n";
   std::cout<<"Please enter your choice: ";
   std::cin>>ch;
   switch(ch)
   { case '1': n= vm.coin();
		std::cout<<" The value returned by method is:"<<n <<"\n";
		break;
    
	 case '2':
		n=vm.small_cup();
		std::cout<<" The value returned by method is:"<<n<<"\n";
		break;

     case '3': n=vm.large_cup();
		std::cout<<" The value returned by method is:"<<n<<"\n";
		break;

     case '4':  n=vm.sugar();
		std::cout<<" The value returned by method is:"<<n<<"\n";
		break;
    
	 case '5' : n=vm.tea();
		std::cout<<" The value returned by method is:"<<n<<"\n";
		break;
    
	 case '6':
		std::cout<<" Enter the no of small cups:";
		std::cin>>i;
		n = vm.insert_small_cups(i);
		std::cout<<" The value returned by method is:"<<n<<"\n";
		break;
    
	 case '7': std::cout<<" Enter the no of large cups: ";
		std::cin>>i;
		n=vm.insert_large_cups(i);
		std::cout<<" The value returned by method is:"<<n<<"\n";
		break;
    
	 case '8': std::cout<<"Enter the price to be set: ";
		std::cin>>p;
		n=vm.set_price(p);
		std::cout<<" The value returned by method is:"<<n <<"\n";
		break;
    
	 case 's': std::cout<<"\n"; 
	          vm.showvariable();
	   break;
    
	 case '0': n= vm.cancel();
		std::cout<<" The value returned by method is:"<<n <<"\n";
		break;
     case '9': 
	    n = vm.dispose();
		std::cout<<" The value returned by method is:"<<n <<"\n";
		break;
		default: std::cout<<"\n"<<"Please enter valid option... !!!!"<<"\n";
	
   }
   std::cout<<"\n Press (y/n) to continue :" <<"\t";
   std::cin>>op;
}while(op=='y');

return 0;
 }
