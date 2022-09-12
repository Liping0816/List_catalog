#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;
	void Hash();
	void push();
	void sort();
	void search();
	void show();
	void delcat();

#define tablesize 7

struct Node{
	string word;
	Node *next;
};

Node *Covid[tablesize];
	
		
int main(){
	
Hash();
	cout << "---------- COVID-19's Catalog ----------\n";
	cout << "\nAdd new word(P)   Sort(S)            Search(F) " << endl;
	cout << "\nShow/Display(D)   Delete/Remove(R)   End program(E)" << endl;
	
char choose;
	do{
		cout << "\nchoose your operation : " ;
		cin >> choose;
		switch(choose){
			case 'P':
				push();
				break;
			
			case 'S':
				sort();
				break;
			
			case 'F':
				search();
				break;
			
			case 'D':
				show();
				break;
			
			case 'R':
				delcat();
				break;
			
			default:
				cout<<"\nDefault. Please enter correct option\n";
		}
		
	}while(choose != 'E');

return 0;
}


void Hash(){
	for(int i = 0; i< tablesize; i++){
		Covid[i] = new Node;
		Covid[i]->word = "empty";
		Covid[i]->next = NULL;
	}
}


void push(){
	
	string Test;
	
	cin.ignore();
	cout << "Please enter a word to be inserted :";
	getline(std::cin, Test);

	
	//convert string into char
	char k[Test.size()+1];
	std::copy(Test.begin(),Test.end(),k);
	k[Test.size()]='\0';
	
	//cout << "\n" << k[0];
	
	int index;
	index = k[0] % 7;
	//cout << index;
	
	
	//store into Covid
	if (Covid[index]->word == "empty"){
		
		Covid[index]->word = Test;
	}
	
	else{
		Node *ptr = Covid[index];
		
		Node *n = new Node;
		n->word = Test;
		n->next = NULL;
		
		while(ptr->next != NULL){
			ptr = ptr->next;
		}
		
		ptr->next = n;
	}
}


void show(){
	
	cout << "\n------------ Display List ------------\n\n";
	int index = 0;
	Node *ptr = Covid[index];
	
	for(index = 0; index<tablesize; index++){
		
		Node *ptr = Covid[index];
		
		if(ptr->word == "empty"){
			cout << "Bucket " << index << " is empty." << endl;
			
		}
		
		else{
			cout << "Bucket " << index << " : ";
			while(ptr!=NULL){
				cout << ptr->word <<"   ";
				ptr = ptr->next;
			}
			cout << "\n";
		}
	}
	cout <<"\n------------ End of List ------------\n";
}


void delcat(){
	
	Node *pDel, *P1, *P2;
	string Del;
	
	cin.ignore();
	cout << "\nEnter the word you want to delete : ";
	getline(std::cin, Del);
	
	//count index number
	char k[Del.size()+1];
	std::copy(Del.begin(),Del.end(),k);
	k[Del.size()]='\0';
	
	
	int index;
	index = k[0] % 7;

	
	//case 1: bucket is empty
	if(Covid[index]->word == "empty"){
		
		cout << Del << " was not found in the hashtable.\n\n" ;
	}
	
	//case 2:first item in bucket match
	//and there are more item in bucket
	else if(Covid[index]->word == Del){
		
		pDel = Covid[index];
		
		Covid[index] = Covid[index]->next;
		delete pDel;
		cout << Del << " was removed from the hashtable.\n\n" ;

	}
	
	//case 3:first item not match, but there are others item
	else{
		P1 = Covid[index]->next;
		P2 = Covid[index];
		
		while(P1!=NULL && P1->word!=Del){
			P2 = P1;
			P1 = P1->next;
		}
		
		//case 3.1 : not found
		if(P1 == NULL){
			
			cout << Del << " was not found in the hashtable.\n\n";
		}
		
		//case 3.2 : found
		else{
			pDel = P1;
			P1 = P1->next;
			P2->next = P1;
			
			delete pDel;
			cout << Del << " was removed from the hashtable.\n\n";
		}
	}
	
}


void search(){
	
	Node *P1;
	string Test;
	
	cin.ignore();
	cout << "Enter the word you want to search: ";
	getline(std::cin, Test);
	
	//count index number
	char k[Test.size()+1];
	std::copy(Test.begin(),Test.end(),k);
	k[Test.size()]='\0';
	
	int index;
	index = k[0] % 7;
	
	
	//if bucket is empty, just stop
	if(Covid[index]->word =="empty"){
		
		cout << Test << " was not found in the hashtable.\n\n";
	}
	
	//bucket is not empty
	else{
		
		P1 = Covid[index];
	
		while(P1!=NULL && P1->word!=Test){
			P1 = P1->next;
		}
		
		if(P1 == NULL){
			cout << Test << " was not found in the hashtable.\n\n";
		}
		
		else{
			cout << P1->word << " was found.\n\n";
		}
	}
}


void sort(){
	
	int index = 0;
	Node *pCur, *pCur2;

	for(index = 0; index < tablesize; index++){
		
		pCur2 = Covid[index];
		if(pCur2->word == "empty")continue;  //skip if bucket is blank
		
		else{
			
			//makesure while loop repeat N times
			while (pCur2->next != NULL) {
				
				pCur = Covid[index];
				while (pCur->next != NULL) {
				
					//exchange position when cur > next data
					if (pCur->word > pCur->next->word) {
						string temp = pCur->word;						
						pCur->word = pCur->next->word;		
						pCur->next->word = temp;				
					}
				
					pCur = pCur->next;
				}
				
			pCur2 = pCur2->next;	
			}
		}
	}
	cout << "\nLists have been sorted." << endl;
}

