#include <iostream>
#include <string>
using namespace std;

void swap(string& s,int i,int j){
	if(i>=0&&j>=0&&i<s.length()&&j<s.length()){
		char bfr = s[i];
		s[i] = s[j];
		s[j] = bfr;
	}
}

void leftrotate(string& s,int ind,int i){
	for(int it=ind;it<i;it++){
		swap(s,it,it+1);	
	}	
}

void rightrotate(string& s,int ind,int i){
	for(int it=i-1;it>=ind;it--){
		swap(s,it,it+1);	
	}	
}

bool nrpt(string s,int ind,int i)//auxiliary
{
	for(int it=ind;it<i;it++){
		if(s[it]==s[i]) return false;
	}
	return true;
}

void perm(string s,int ind=0){
	if(ind==s.length()){
		cout<<s<<endl;
	}
	else{
		for(int i=ind;i<s.length();i++){
			if(i==ind || nrpt(s,ind,i)){
				rightrotate(s,ind,i);
				perm(s,ind+1);
				leftrotate(s,ind,i);
			}	
		}
	}
}

string str;

int main(int argc,char* argv[]){
	if(argc==1){
		cout<<"Type sth: ";cin>>str;
		perm(str);
	}
	else{
		for(int i=1;i<argc;i++){
			str =	std::string(argv[i]); 
			perm(str);
		}
	}
	return 0;
}

