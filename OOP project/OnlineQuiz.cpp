#include<iostream>
#include<conio.h>
using namespace std;

int main(){
string questions[10]{
"Who created C++?",
"C++ Language developed at _________?",
"Which one of the following is a keyword?",
" ____ is the smallest individual unit in a program.",
"Which of the following is a correct identifier in C++?",
"Which of the following is called address operator?",
" C++ is _______ type of programming language.?",
"Which of the following is used for comments in C++?",
" A C++ code line ends with ___",
"Which of the following escape sequence represents carriage return?"
};


string options[10][4]={
{ "Bjarne Stroustrup","Dennis Ritchie","Ken Thompson","Brian Kernighan"},
{ "AT & T's Bell Laboratories of USA in 1972","Sun Microsystems in 1973","Cambridge University in 1972","AT & T's Bell Laboratories of USA in 1979"},
{ " Size","Key","Jump","Switch"},
{ "Variable","Control","Character","Token"},
{ "7Var_name","7VARNAME","VAR_1234","$var_name"},
{ "*","&","_","%"},
{ "Object Oriented","Procedural","Bit level language","Functional"},
{ "//comment","/comment/","Both //comment or /comment/","none"},
{ "A Semicolon(;)","A Fullstop(.)","A Comma(,)","A Slash(/)"},
{ "\r","\n","\n\r","c"},
};
string correctOptions[10] ={ "Bjarne Stroustrup","AT & T's Bell Laboratories of USA in 1979","Switch","Token","VAR_1234","&","Object Oriented","Both //comment or /comment/",
"A Semicolon(;)","\r"};

int userOptions[10] ={0,0,0,0,0,0,0,0,0,0};
int totalQues =10;


//Conducting Quiz

for(int i=0;i<totalQues;i++){
cout<<"Question #"<<(i+1)<<endl;
cout<<questions[i]<<endl;
cout<<"1."<<options[i][0]<<endl;
cout<<"2."<<options[i][1]<<endl;
cout<<"3."<<options[i][2]<<endl;
cout<<"4."<<options[i][3]<<endl<<endl;

cout<<"Select Option(1-4) or 0 to SKIP and Press Enter: ";
cin>>userOptions[i];
cout<<endl<<"------------------------------------------------------------"<<endl<<endl;
}



//printing correct options

cout<<"******* ******* ******* *******"<<endl;
cout<<"******* CORRECT OPTIONS *******"<<endl;
cout<<"******* ******* ******* *******"<<endl;

for (int i=0 ;i<totalQues;i++)
{
cout<<"Question #"<<(i+1)<<endl;
cout<<questions[i]<<endl;
cout<<"1."<<options[i][0]<<endl;
cout<<"2."<<options[i][1]<<endl;
cout<<"3."<<options[i][2]<<endl;
cout<<"4."<<options[i][3]<<endl;


if(userOptions[i] ==0){
cout<<"You Skippes this Question."<<endl;
}
else{
cout<<"You Selected: "<<options[i][userOptions[i]-1]<<endl;
}
cout<<"Correct Option: "<<correctOptions[i]<<endl<<endl;
cout<<"Press any key to Continue......."<<endl;
getch();
cout<<endl<<"-----------------------------------------------"<<endl;
}



//printing Result

cout<<endl<<endl;
cout<<"******* ******* ******* *******"<<endl;
cout<<"******* *** RESULT **** *******"<<endl;
cout<<"******* ******* ******* *******"<<endl;

int correct =0;
int incorrect =0;
int skipped =0;
for(int i=0;i<totalQues;i++){
if(userOptions[i]!=0){
if(correctOptions[i]==options[i][userOptions[i]-1]){
correct++;
}
else{
incorrect++;
}
}
else{skipped++;
}
}
cout<<"Total Questions: "<<totalQues<<endl;
cout<<"Correct: "<<correct<<endl;
cout<<"In-Correct: "<<incorrect<<endl;
cout<<"Skipped: "<<skipped<<endl;
getch();
return 0;
}