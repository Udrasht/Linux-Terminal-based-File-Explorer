#ifndef MESSAGE_H
#define MESSAGE_H
#include <bits/stdc++.h>
#include<iostream>
#include <pwd.h>
#include <fcntl.h>
#include<sys/wait.h>
#include<unistd.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <dirent.h>
#include <grp.h>
#include<set>
#include<stdlib.h>
#include<dirent.h>
#include<string.h>
#include <termios.h>
#include <stdio.h>
#include<time.h>
#include<sys/types.h>
using namespace std;
#define print_divider()  cout<<"\033[0;31m"<<"% % % % % % % % % % % % % % % % Normar Mode % % % % % % % % % % % % % % % %"<<"\033[0m";
char path[PATH_MAX];
string userhome="/home";
struct winsize s1;
void start();
int line;
vector <string> noDirectory(const char*,int);
string present_dir;
vector<string> div(string,string);
int cmode;
void movment(vector<string>,int);
void cmdmode(vector<string>,int);
int getch(void);
stack<string> back;
stack<string> front;
void present(string,int);
void sizecal(double);
void goto_opt(vector<string>);
string right_path(string);
void copy_opt(vector<string>);
mode_t mode(string);
void copy_fopt(string, string);
void copy_dopt(string,string);
int dirornot(string);
void rename_opt(vector<string>);
void search_opt(string,vector<string>);
void create_fopt(vector<string>);
void create_dopt(vector<string>);
void delete_fopt(vector<string>);
void delete_dopt(vector<string>);
void deleteimp(string);
void move_opt(vector<string>);
#endif
