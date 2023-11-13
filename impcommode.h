#ifndef IMPCOMMAND_H
#define IMPCOMMAND_H

#include "message.h"
#include "directory.h"


vector<string> glo;




mode_t mode(string str){




struct stat nod;
mode_t m1=0;
stat(str.c_str(),&nod);

    m1=m1|((nod.st_mode & S_IROTH)?0004:0);
    m1=m1|((nod.st_mode & S_IWOTH)?0002:0);
    int l2=str.size();
    m1=m1|((nod.st_mode & S_IXOTH)?0001:0);
    m1=m1|((nod.st_mode & S_IRUSR)?0400:0);
    m1=m1|((nod.st_mode & S_IWUSR)?0200:0);
    int l3=str.size();
    m1=m1|((nod.st_mode & S_IXUSR)?0100:0);
    m1=m1|((nod.st_mode & S_IRGRP)?0040:0);
    int l4=str.size();
    m1=m1|((nod.st_mode & S_IWGRP)?0020:0);
    m1=m1|((nod.st_mode & S_IXGRP)?0010:0);

     return m1;
}



int dirornot(string str1){
    struct stat nod;
    if(stat(str1.c_str(),&nod)!=0){
        return 0;
    }
    else if(S_ISDIR(nod.st_mode)){
        return 1;

    }
    else{
        return 0;
    }
}
string right_path(string str){
    
    if(str[0]=='/'){
        string str2="";
      str2=str2+str;
     return str2;
    }
    else if(str[0]=='~'){
        string str2="";
        int u1=str.length();
        str2=string(path)+str.substr(1,u1);
        return str2;
    }
    else if(str[0]=='.'&&str[1]=='/'){
        string str2="";
        int u1=str.length();
        str2=present_dir+str.substr(1,u1);
        return str2;

    }
    else{
        string str2="";
         str2=present_dir+"/"+str;
        return str2;
    }
}

void move_opt(vector<string> str){
    int l1=str.size();
    if(l1>=3){
        copy_opt(str);
        int i=1;
        while(i<l1-1){
            string s=right_path(str[i]);
            int t1=dirornot(s);
            if(t1==1){
                deleteimp(s);
                int t2=rmdir(s.c_str());
                if(t2==-1){
                    printf("can't move directory");
                }

            }
            else if(unlink(s.c_str())==-1){
                printf("can't move the file");

            }
            
            i++;
        }
         noDirectory(present_dir.c_str(),line-3);
    }
    if(l1<3){
        printf("Invalid command");
    }
}

void deleteimp(string s){
    DIR *dr;
    dr=opendir(s.c_str());
    if(dr==NULL){
        cout<<"can't open error in opening directory"<<s.c_str();
        exit(1);
    }
    struct  dirent *ss;
    string str1,des1;
   while((ss=readdir(dr))!=NULL) 
   {
    if(!strcmp(ss->d_name,".")){
        continue;
    }
    if(!strcmp(ss->d_name,"..")){
        continue;
    }
    des1=ss->d_name;
    str1=s+"/"+des1;
    int t1=dirornot(str1);
   // cout<<string(str1.c_str())<<"   "<<str1<<t1<<"   hanuman   ";
    if(!t1){
        
    if(unlink(str1.c_str())==-1){
        cout<<"file not delete "<<s.c_str();
        return;

        }}
    
      else{
        deleteimp(str1);
        int t3=rmdir(str1.c_str());
        if(t3==-1){
           // cout<<string(str1.c_str())<<"   ";
            cout<<"  can't delete"<<str1.c_str();
        }
      }
   }
        
    
    
   
}


/*------------------------------------------Command mode ---------------------------------------*/
void copy_fopt(string str1,string dest){
   
   int f1=open(str1.c_str(),O_RDONLY);
              mode_t m=mode(str1);
            
              if(f1==-1){
                 printf("error in opening file");
              }
                int f2=open(dest.c_str(),O_CREAT|O_WRONLY,m);
              if(f2==-1){
                printf("already exist");
                return ;


              }
              char ch;
              while(read(f1,&ch,1)){
                write(f2,&ch,1);
              }
              close(f1);
              close(f2);


}


void search_opt(string str1,vector<string> v){
    int l1=v.size();
    if(l1==2){
        string str2=str1+"/"+v[1];
        DIR *dr;
        dr=opendir(str1.c_str());
        if(dr==NULL){
            cout<<"Error";
        }
        struct dirent *s;
        while((s=readdir(dr))!=NULL){
            
            if(!strcmp(s->d_name,"."))
                continue;
            
            if(!strcmp(s->d_name,".."))
                continue;
            string del=string(s->d_name);
            string d=str1+"/"+del;
         
            int l2=strcmp(str2.c_str(),d.c_str());
            if(!l2){
                glo.push_back(d);
            }
            int l3=dirornot(d);
            if(l3==1){
            search_opt(d,v);}



        }

    }
    else{
       cout<<"Incorrect command";

    }



}



void copy_dopt(string str1,string dest){


 /* copy dir */
                DIR *dr;
                dr=opendir(str1.c_str());
                if(dr==NULL){
                    printf("error in opening directory");
                 return;
                  }
                  struct dirent* s1;
                  string str5,res;
                  while((s1=readdir(dr))!=NULL){
                    
                    if(!strcmp(s1->d_name,".")){
                        continue;
                    }
                    if(!strcmp(s1->d_name,"..")){
                        continue;
                    }
                    str5=s1->d_name;
                    res=str1+"/"+str5;
                    str5=dest+"/"+str5;
                   int t1=dirornot(res);
                    if(t1==1){
                           mode_t m1=mode(res);
                           if(mkdir(str5.c_str(),m1)==-1){
                            printf("can't create directory");
                            return;
                           }
                           else{
                               copy_dopt(res,str5);
                           }
                    }
                    else{
                    copy_fopt(res,str5);

                  }
                  
                  
  }
                  
                  
    }

void goto_opt(vector<string> str){
    int l=str.size();
    if(l==2){
        vector<string> v;
        string str2=right_path(str[1]);
        v=div(str2, "/");
         int t1=v.size();
         t1=t1-1;
        if(v[t1]=="."){
            return;
        }
        back.push(present_dir);
        if(v[t1]==".."){
            int t2=str2.size();
            t2=t2-1;

            present(str2.substr(0,str2.length()-1),line-3);

        }
        else{
            noDirectory(str2.c_str(),line-3);
        }
        

    }
    else{
        printf("incorrect command");
    }


}

void copy_opt(vector<string> str)
{
    int u1= str.size();
    if(u1>=3){
        string destination=right_path(str[u1-1]);
        int t1=dirornot(destination);
           if(t1==0){
            printf("Invalid destination");
            return;
           }
        int i=1;
        while(i<u1-1){
            
            vector<string> str2=div(str[i],"/");
            string str1=right_path(str[i]);
              int t2=dirornot(str1);
            string dest=destination+"/"+str2[str2.size()-1];
            /* copy file */
                

            if(t2==0){
                copy_fopt(str1,dest);
              
            }
            else{
                mode_t m1=mode(str1);
               if(mkdir(dest.c_str(),m1)==-1)
                {
                    printf("can't ctrate directory");
                    return;
                }
               copy_dopt(str1,dest);
            }
            i++;
        }
    }
    else{
        cout<<"Invalid command";
    }
}
void rename_opt(vector<string> str1){
    int l1=str1.size();
    string s,d;
    vector<string> so,de;
    if(l1==3){
         s=right_path(str1[1]);
         d=right_path(str1[2]);
         so=div(s,"/");
         de=div(d,"/");
         int l2=so.size();
         l2=l2-1;
         int l3=de.size();
         l3=l3-1;
         so[l2]=de[l3];
         string res=so[0];
         int i=1;
         while(i<=l2){
             res=res+"/"+so[i];
            i++;
         }
         int t1=rename(s.c_str(),res.c_str());
         if(t1!=-1){
                noDirectory(present_dir.c_str(),line-3);
         }
           else{
            cout<<path<<"   "<<res<<"   "<<s<<"   "<<"  "<<d;
            printf(" couldn't rename the file or directory");

           }



    }
    else{
        cout<<"command is not correct";
    }
}
void create_fopt(vector<string> str1){

     string df;
     
    int l1=str1.size();
    
    if(l1>=3){
     
       df=right_path(str1[l1-1]);
       int i=1;
       while(i<l1-1){
            string f=str1[i];
            string d=df+"/"+f;
            int t=creat(d.c_str(),0600);
             if(t==-1){
             printf("file not create");
       }
        i++;
       }
       
    
        noDirectory(present_dir.c_str(),line-3);
        }
    else{

          cout<<"command not found";
    }
       
    

}


void create_dopt(vector<string> str1){
     string df;
     
    int l1=str1.size();
    
    if(l1>=3){
       
       df=right_path(str1[l1-1]);
       unsigned int i=1;
       while(i<l1-1){
            string f=str1[i];
            string d=df+"/"+f;
            int t=mkdir(d.c_str(),0755);
             if(t==-1){
             printf("file not create");
       }
        i++;
       }
       
    
        noDirectory(present_dir.c_str(),line-3);}
    else{

          cout<<"command not found";
    }
       
    

}
void delete_fopt(vector<string> str1){
    int l1=str1.size();
    string s;
    if(l1>=2){
        for(int i=1;i<l1;i++){
          s=right_path(str1[i]);
          int t=unlink(s.c_str());
          if(t==-1){
            cout<<"file not delete ";
          }}
          
            noDirectory(present_dir.c_str(),line-3);
          
    }
    else{
        cout<<"incorrect command";
    }
}
void delete_dopt(vector<string> v){

    int l1=v.size();
    string s;
    if(l1==2){
        s=right_path(v[1]);
        int t=dirornot(s);
        if(t==1){
            deleteimp(s);
            int t2=rmdir(s.c_str());
            if(t2==-1){
                cout<<"can't delete";
            }
            else{
                noDirectory(present_dir.c_str(),line-3);
            }

        }

    }
    else{
          printf("Incorrect command");
    }
}
#endif