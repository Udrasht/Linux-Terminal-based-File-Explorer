#ifndef DIRECTORY_H
#define DIRECTORY_H
#include "message.h"
#include "impcommode.h"
void start(){
 getcwd(path,sizeof(path));
    ioctl(STDIN_FILENO,TIOCGWINSZ,&s1);

}
vector<string> div(string str,string str2){
  vector<string> v;
  string str3;
  size_t x1=0;
  
  while((x1=str.find(str2))!=string::npos){
    str3=str.substr(0,x1);
    int l4=str2.size();

    v.push_back(str3);
     string str4=str3;
    str.erase(0,x1+str2.length());

  }
  v.push_back(str);
  return v;
}


int getch(void){
       struct termios a1;
       tcgetattr(0,&a1);
       struct termios a2;
       a2=a1;
       a2.c_lflag &=~(ICANON|ECHO);
       tcsetattr(0, TCSANOW, &a2);
       int u1=cin.get();
       auto u4=tcsetattr(0, TCSANOW, &a1);
       if(u4){
            fprintf(stderr,"!! failed !!");
        exit(1);
       }
    
      return u1;

}


void sizecal(double len){
  
      if(len<1000){
         printf("%8.2fB\t",len);
      }
      else{
      len=len/1000;
      
      double len2=len;
       if(len2>1000){
        len2=len2/1000;
         printf("%8.2fMB\t",len2);
       }
       else{
       printf("%8.2fkB\t",len2);}
      }

}
void present(string str1,int u1){
 // cout<<str1<<"udrasht";
  vector<string> v;
         
  //cout<<"hello";
  v=div(str1,"/");
  string str2=v[0];
  int z=1;
  int z1=v.size()-2;
  while(z<z1){
    str2=str2+"/"+v[z];
    z++;
  }
  noDirectory(str2.c_str(),u1);
}



void show(string str3){

    struct stat edon;
   // cout<<str3<<"  ";

    vector<string> filname=div(str3, "/");
     string rm;
     rm="";
     cout<<"\033[4;36m"<<">";
     cout<<"\033[0m";
     stat((str3).c_str(),&edon);
     
     rm=rm+(S_ISDIR(edon.st_mode)?"d":"-");


     rm=rm+((edon.st_mode & S_IRUSR)?"r":"-");


	   rm=rm+((edon.st_mode & S_IWUSR)?"w":"-");


      string a1;
	   rm=rm+((edon.st_mode & S_IXUSR)?"x":"-");


	   rm=rm+((edon.st_mode & S_IRGRP)?"r":"-");


	   rm=rm+((edon.st_mode & S_IWGRP)?"w":"-");
     string a2;
	   rm=rm+((edon.st_mode & S_IXGRP)?"x":"-");
     rm=rm+((edon.st_mode & S_IROTH)?"r":"-");


     char min[60];
	   rm=rm+((edon.st_mode & S_IWOTH)?"w":"-");


	   rm=rm+((edon.st_mode & S_IXOTH)?"x":"-");
        

        
      printf("%s\t",rm.c_str());
      
      
      
        a1=getpwuid(edon.st_uid)->pw_name;   
        a2=getgrgid(edon.st_gid)->gr_name;
       cout<<"\033[0;32m";

        printf("%s\t",a1.c_str());
        printf("%s\t",a2.c_str());
        cout<<"\033[0m";
        

        
        
        time_t s_time;
        strcpy(min,ctime(&edon.st_mtime));
        struct tm time;
        
        s_time = edon.st_mtime;
        localtime_r(&s_time, &time);
        double len=edon.st_size;
        strftime(min, sizeof min, "%b %d %H:%M",&time);
        
         cout<<"\033[0;35m";
         printf("%10s\t",min);
         cout<<"\033[0m";

         
         
         sizecal(len);
         int l21=filname.size();
         l21=l21-1;

        cout<<"\033[0;34m"<<filname[l21];
        cout<<"\033[0m";
        cout<<endl;


     
}






void movment(vector<string> nod,int len){
     int l1;
     int l2=nod.size();
     if(len>=l2){
        l1=l2;
     }
     else{
        l1=len;
     }
     string parentdir=path;
     struct stat edon;
      printf("%c[%d;%dH",27,l1+3,0);
      print_divider();
     printf("%c[%d;%dH",27,0,0);
     
     int cur=0;
     int q1=0,q2=len;
    
     int k=1,r;
     for(;k=1;){
        r=0;
        switch ((r=getch()))
        {
        case 66: 
                if(cur<l1-1){
                 cout<<"\033[1B";
                 
                 cur=cur+1;
                // cout<<string(path)<<"  "<<string(present_dir);
              
                 
                    }
                    
             
                else  if(l2>line-3&&cur>=l1-1&&cur+q1<l2&&q2<l2){
                 
                  
                       q1++;q2++;
          
                
                   cout <<"\33c";
                        int v9=q1;
                        while(v9<q2&&v9<l2){
                            show(nod[v9]);
                            v9++;
                            
                        }
                      
                         printf("%c[%d;%dH",27,l1+3,0);
                         print_divider();
                          printf("%c[%d;%dH",27,l1,0);
                          
                }
             
                   
                    
                 
            break;
        case 65: if(cur>0){
                 cout<<"\033[1A";
                  cur=cur-1;
                 //cout<<cur;
                 }
                 else if(q1>0){
                  if(q2<=nod.size()&&q1>=0){
                    q1--;
                        q2--;
                   
                        cout <<"\33c";
                        int v=q1;
                        while(v<q2){
                            show(nod[v]);
                            v++;
                        }
                        
                           printf("%c[%d;%dH",27,l1+3,0);
                           print_divider();
                           printf("%c[%d;%dH",27,0,0);
                         cur=0;
                    
                 }}
            break;
        case 67: if(!front.empty()){
                 back.push(present_dir);
                 string g1=front.top();
                 front.pop();
                 noDirectory(g1.c_str(),len);
                 }
            break;
        case 68: if(!back.empty()){
                 front.push(present_dir);
                 string g1=back.top();
                 back.pop();
                 noDirectory(g1.c_str(),len);
                 }
            break;
        case 81:
        case 113: 
                  printf("%c[%d;%dH",27,l1+5,0);
                 exit(1);
                break;
        case 58:
               cmdmode(nod,len);  
                 
             break;
        case 10:
            if(q1>0){
                cur=cur+q1;
            } 
            if(cur!=0){
                stat((nod[cur]).c_str(),&edon);
                if(S_ISDIR(edon.st_mode))
                {
               
                    back.push(present_dir);
                    for(;!front.empty();){
                        front.pop();
                    }
                    if(cur!=1){
                        noDirectory((nod[cur]).c_str(),len);
                    }
                    else{
                      //cout<<"sahjdgjhasfdhjgasf"<<endl;
                 
                        present(nod[0],len); 
                    }
                }
                else{
                  
                    if(fork()==0){
                      const char *ud=(nod[cur]).c_str();
                         
		                      execl("/usr/bin/xdg-open", "xdg-open",ud, (char *)0);
		                   exit(1);
	                    
                    }
                }

            }    
            break;
        case 72:
        case 104:
            while(!front.empty()){
                front.pop();
            }
            back.push(present_dir);
               // string userhome="/home";
            noDirectory(userhome.c_str(),len);
            
           break;
        case 127:
              while(!front.empty()){
                front.pop();
            }
            back.push(present_dir);
              
             noDirectory((nod[1]).c_str(),len);
            break;
       
            
        }

     }




}


void cmdmode(vector<string> nod,int len){
    int c1,c2=0;
      if(len>=nod.size()){
        c1=nod.size()+3;
       
      }
      else{
        c1=len+3;
      }
      
      cmode=1;
     //void setCommand(int n, int *y);
   printf("%c[%d;%dH",27,c1,c2);
   printf("\e[0J");
   printf("command mode:"); 
  // cout<<"hello";
   c2=14;
  
  printf("%c[%d;%dH",27,c1,c2);
  char cle=0;
  string dr="";
  vector<string> ord;
       while(1){

               switch(cle=getch()){
                 case 27: 
                          cmode=0;
                           printf("%c[%d;%dH",27,c1+3,0);
                           printf("\e[0J");
                           movment(nod,len);
               case 10: 
                      c2=0;
                      
                      printf("%c[%d;%dH",27,c1,c2);
                      printf("\e[0J");
                      printf("command mode:"); 
                      c2=14;
                      ord=div(dr," ");
                      dr="";
                      if(ord[0]=="create_file"){
                           create_fopt(ord);
                      }
                      else if(ord[0]=="create_dir"){
                        create_dopt(ord);
                      }
                      else if(ord[0]=="copy"){
                        copy_opt(ord);
                      }
                      else if(ord[0]=="delete_file"){
                        delete_fopt(ord);
                      }
                       else if(ord[0]=="delete_dir"){
                        delete_dopt(ord);
                      }
                       
                       else if(ord[0]=="search"){
                        glo.clear();
                        search_opt(present_dir,ord);
                        
                        if(glo.size()){
                          cout<<"true";
                        }
                        else{
                          cout<<"false";
                        }

                      }
                       else if(ord[0]=="rename"){
                        rename_opt(ord);
                      }
                      else if(ord[0]=="goto"){
                        goto_opt(ord);
                      }
                       else if(ord[0]=="move"){
                        move_opt(ord);
                      }
                       else if(ord[0]=="quit"){
                        exit(1);
                      }
                      
                    break;
           
            
            case 127:
            if(c2>14){
                c2=c2-1;
                  printf("%c[%d;%dH",27,c1,c2);
            }
            printf("\x1b[0K");
            dr=dr.substr(0,dr.length()-1);
            break;
            default:
            cout<<cle;
            c2=c2+1;
              printf("%c[%d;%dH",27,c1,c2);
            dr=dr+cle;




               }

       }
           



}




vector<string> noDirectory(const char *c,int n){

   DIR *dr;
   
   //DIR *dr;
   dr=opendir(c);
   if(dr==NULL){
    cout<<"\033[0;31m"<<"can't open directory"<<endl;
	cout<<"\033[0m";
    exit(1);
	
   }

   vector<string> str1;
   struct dirent *pg;
   while(1){
    if((pg=readdir(dr))==NULL){
        break;
    }
    else{
        string u2=pg->d_name;
        string up=c;
        u2=up+'/'+u2;
        //u2=u2+c;
        str1.push_back(u2);

    }
   }
    int n1=str1.size();
   sort(str1.begin(),str1.end());
   auto k=0;
   int n3;

   present_dir=str1[0].substr(0,str1[0].length()-2) ;
   
   
   
   closedir(dr);
   if(n1<n){
     n3=n1;
   }
   else{
    n3=n;
   }


   printf("\33c");
   while(k<n3){
    show(str1[k]);
    k++;
   }
   
    if(cmode==0){
        movment(str1,n);
        }
        
    else {
      cmdmode(str1,n);
        }
        
    return str1;

}

#endif