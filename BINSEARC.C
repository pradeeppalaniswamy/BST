#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct bsnode
{
char data[20];
struct bsnode* left;
struct bsnode* right ;
};
struct bsnode* root;
//bsnode* createnode(int);
void printelementsinorder(struct bsnode* root)
{
if (root==NULL)
return;
printelementsinorder(root->left);
printf(" %s ",root->data);
printelementsinorder(root->right);
}
 void printelementspreorder(struct bsnode* root)
{
if (root==NULL)
return;
printf(" %s ",root->data);
printelementspreorder(root->left);
printelementspreorder(root->right);
}
  void printelementspostorder(struct bsnode* root)
{
if (root==NULL)
return;
printelementspostorder(root->left);
printelementspostorder(root->right);
printf(" %s ",root->data);
}



struct bsnode* findmin(struct bsnode* root )
{if (root!=NULL)
root=root->left;
return root;
}


struct bsnode* Delete( struct bsnode* root,char data[])
{

 if(root==NULL)
 return root;
 else if (toint(root->data)>toint(data))
 root->left= Delete(root->left,data);
 else if (toint(root->data)<toint(data))
 root->right=Delete(root->right,data);
 else
 {
 if(root->right==NULL && root->left==NULL)
 //free root;
 root=NULL;
 else if (root->right==NULL)
 {
 struct bstree* temp=root;
root = root->left;
//free temp;
 }
 else if (root->left==NULL)
 {
 struct bstree* temp1=root;
root= root->right;}

   else
   {
   struct bsnode* temp=findmin(root->right );
  strcpy( root->data,temp->data);
   root->right=Delete(root->right,temp->data);
    }
    }
 return root;
}

struct bsnode* createnode(char data[])
{
 struct bsnode* newnode=(struct bsnode*)malloc(sizeof(struct bsnode));
newnode->left=NULL;
newnode->right=NULL;
strcpy(newnode->data,data);
//printf("\nadrees %x",newnode);
//printf("%s",data);
return newnode;

}
int toint(char datachar[])
{
int tointeger;
{
if(atoi(datachar)!=0)
tointeger=atoi(datachar);
else
tointeger=datachar[0];
}
//printf("string is %s and number is %d",datachar,tointeger);
return tointeger;

}

struct bsnode* insert(struct bsnode* root,char data[])
{
//printf("insert");
if(root==NULL)
{
root= createnode(data);
//printf("\n",root->data);
 }
else if(toint(root->data) >=toint(data))
{
root->left=insert(root->left,data);
// printf("\nleft%d",root->data);
printf("\n");

}
else
{
root->right=insert(root->right,data);
//printf("\nRIGHT");
//printf("\n\t");
}

//printf("inseted data %s",data);
 return root;
}


int  search(struct bsnode* root,char data[])
{
//printf("searching");
//printf("\nthe data thats searched %d",root->data);
//printf("\N the ADRESS THAT IS BEING SEARCHED%x",root);
//getch();
if(root==NULL)
{
return 0;
}
else if (toint(root->data)==toint(data) )
return(1);

 else if (toint(root->data) >=toint(data))
 {
return search(root->left,data);
      }
else
return (search(root->right,data));
}


void main()
{
int found=0;
char choice ='Y';
char del[20];
char str[20];
char srch[20];
int temp1;
int a,k;
char ch;
//struct bsnode* root;
struct bsnode* mainnode;
//printf("hi");
getch();
root=NULL;
//root=insert(root,10);

do
{
printf("\nplease specify the option to perform\n1 view elements(in order) \n2 view elements (pre order)\n 3 view elements (post order)\n 4 input elements\n 5 search \n 6 Delete elements \n");
scanf("%d",&ch);
switch(ch)
{
case 1:
 printelementsinorder(root);
 break;
 case 2:
 printelementspreorder(root);
 break;
 case 3:
 printelementspostorder(root);
  break;
case 4:
  printf("\n Enter the element to be inserted ");
  scanf ("%s",&str);
  // if((atoi(str)!=0))
   {
root=insert(root,str);
   }
   break;

case 5:

 printf("\n Enter the element to be searched");
 scanf("%s",&srch);
 found=search(root,srch);
 if(found)
 {printf("element found in list ");
 }
 else
 {
 printf("element not found");
 }

 break;

default:
printf("enter the element to be deleted");
scanf("%s",&del);
root=Delete(root,del);
break;
}
printf("\n \nDo you want to continue? Y||N ");
choice=getch();
printf("%c",choice);
getch();
}
while(choice=='y'||choice=='Y');

printf("\n Printing elements finally present ");
printelementsinorder(root);
 getch();
 clrscr();
 }
//printf("\n INITIAL ROOT %x",root);
/*mainnode=root;
root=insert(root,15);
root=insert(root,11);
root=insert(root,4);
root=insert(root,8);


//printf("\n%x IS ROOT AFTER 15",root);
//printf("\ndone");
getch();
printf("\nprinting");
printelementsinorder(root);

root=insert(root,1);
//Printf("\n aDDRESS TO BE ROOT NOW IS %x",root);
printf("eNTER THE NUMBER TO SEARCH ");
scanf("%d",&k);
a=search(root,k);
printf("element found %d",a);
printf("\nenter the number to be deleted ");
scanf("%d",&k);
 root=Delete(root,k);
 printf("\nelements after deletion\n");

 printelementsinorder(root);

getch();
clrscr();
}

*/