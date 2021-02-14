#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define LOWERLETTER_I 97
#define LOWERLETTER_F 122

#define UPPERLETTER_I 65
#define UPPERLETTER_F 90

#define Y 15
#define X 15

#define DICT_SIZE 15
#define WORD_LEN 10
#define LINE_LEN 18
char rand_char(int firstletter, int lastletter);
void show_puzzle_map(char puzzle_map[Y][X]);
////following 8 line declare compare between guess and on the puzzle
int east_check(char *guess,int length_of_guess,int guess_coord[2],char puzzle_map[Y][X],char *dict[DICT_SIZE], int coord[DICT_SIZE][4]);
int west_check(char *guess,int length_of_guess,int guess_coord[2],char puzzle_map[Y][X],char *dict[DICT_SIZE], int coord[DICT_SIZE][4]);
int north_check(char *guess,int length_of_guess,int guess_coord[2],char puzzle_map[Y][X],char *dict[DICT_SIZE], int coord[DICT_SIZE][4]);
int south_check(char *guess,int length_of_guess,int guess_coord[2],char puzzle_map[Y][X],char *dict[DICT_SIZE], int coord[DICT_SIZE][4]);
int south_east_check(char *guess,int length_of_guess,int guess_coord[2],char puzzle_map[Y][X],char *dict[DICT_SIZE], int coord[DICT_SIZE][4]);
int north_west_check(char *guess,int length_of_guess,int guess_coord[2],char puzzle_map[Y][X],char *dict[DICT_SIZE], int coord[DICT_SIZE][4]);
int north_east_check(char *guess,int length_of_guess,int guess_coord[2],char puzzle_map[Y][X],char *dict[DICT_SIZE], int coord[DICT_SIZE][4]);
int south_west_check(char *guess,int length_of_guess,int guess_coord[2],char puzzle_map[Y][X],char *dict[DICT_SIZE], int coord[DICT_SIZE][4]);
////following 8 lines necessary to print puzzle map
//actually ı did the 16 function as a function but ı got some errors so ı decided to convert them functions for each one
void east_print(int length_of_guess,int guess_coord[2],char puzzle_map[Y][X]);
void west_print(int length_of_guess,int guess_coord[2],char puzzle_map[Y][X]);
void north_print(int length_of_guess,int guess_coord[2],char puzzle_map[Y][X]);
void south_print(int length_of_guess,int guess_coord[2],char puzzle_map[Y][X]);
void south_east_print(int length_of_guess,int guess_coord[2],char puzzle_map[Y][X]);
void north_west_print(int length_of_guess,int guess_coord[2],char puzzle_map[Y][X]);
void north_east_print(int length_of_guess,int guess_coord[2],char puzzle_map[Y][X]);
void south_west_print(int length_of_guess,int guess_coord[2],char puzzle_map[Y][X]);
int canucomp(char guess[], char dirct[] );//compare function
int get_line_size(char *line) {
    char *ch_iter = line; // so as not to lose beginning of line
    int counter = 0;
    // go until you see new line or null char
    while(*ch_iter != '\n' && *ch_iter != '\0') {
        ch_iter++; // next char
        counter++; // increment counter
    }

    return counter;
}

void copy_string(char *source, char *destination) {
    // get iterators over original pointers
    char *src_iter = source;
    char *dst_iter = destination;
    // until null char
    while (*src_iter != '\0') {
        // copy pointers
        *dst_iter = *src_iter;
        // advance to next char
        src_iter++;
        dst_iter++;
    }
    // terminate string
    *dst_iter = '\0';
}

void remove_newline(char *line) {
    char *ch_iter = line;
    // go until you see new line
    while(*ch_iter != '\n') {
        ch_iter++; // next char
    }
    *ch_iter = '\0'; // overwrite new line
}

void print_dictionary(char *dict[]) {
    int i;
    for(i = 0 ; i < DICT_SIZE ; i++) {
        printf("%s\n", dict[i]);
    }
}

void print_coord(int coord[DICT_SIZE][4]) {
    int i, j;
    for(i = 0 ; i < DICT_SIZE ; i++) {
        for(j = 0 ; j < 4 ; j++) {
            printf("%d ", coord[i][j]);
        }
        printf("\n");
    }
}
int string_length(char guess[WORD_LEN]){//necessary to get size of string
    int counter=0,i=0;
    while(guess[i]!= '\0'){
        i++;
        counter++;
    }

    return counter;
}
//this function to check whether is the guess string in dictionary or not 
int compare_foo(char guess[], int length_of_guess, char *dict[DICT_SIZE] ){
    int result=0;
    int flag = 0;
    for (int k = 0 ; k < DICT_SIZE; ++k)
    {
        for (int i = 0 ; (guess[i]== dict[k][i]) && flag==0 ; ++i)
        {
            if(i==length_of_guess-1)
            {
                result=1;
                flag=1;
            }   
        }
    }
    return result;
}

int main(){
    char *dict[DICT_SIZE];
    int coord[DICT_SIZE][4];
    char line[LINE_LEN];
    char puzzle_map[Y][X];
    int i=0,j=0,elementh=0,fill;
    char a='.';
    int guess_coord[2]={0};
    char guess[WORD_LEN]={0};
    int length_of_guess;
    char strexit[9]="exit game";//name of exit game string
    int exit=0;//necessary to check while loop
    srand(time(NULL));//get seed value for random characters
    FILE *fp = fopen("word_hunter.dat", "r");

    int line_counter = 0;
    int dict_counter = 0;
    while(fgets(line, LINE_LEN, fp) != NULL) {
        if(line_counter%5 == 0) {
            dict[dict_counter] = (char*) malloc(sizeof(char) * get_line_size(line));
            remove_newline(line);
            copy_string(line, dict[dict_counter]);
        } else if (line_counter%5 == 1){
            coord[dict_counter][0] = atoi(line);
        } else if (line_counter%5 == 2){
            coord[dict_counter][1] = atoi(line);
        } else if (line_counter%5 == 3){
            coord[dict_counter][2] = atoi(line);
        } else if (line_counter%5 == 4){
            coord[dict_counter][3] = atoi(line);
            dict_counter++;
        }
        line_counter++;
    }

    fclose(fp);
    //print_dictionary(dict);
    //print_coord(coord);

    // WRITE HERE...
    for (i = 0; i <Y ; ++i)
    {
        for (j = 0; j < X; ++j)
        {

            puzzle_map[i][j]=rand_char(LOWERLETTER_F, LOWERLETTER_I);
        }
    }
    //to fill puzzle 2d array-it s like parallel array I get the coordinates of same string 
    for (elementh = 0; elementh < DICT_SIZE; ++elementh)
    {
        if (coord[elementh][1]==coord[elementh][3])
        {
            //if (coord[elementh][2]>coord[elementh][0])
            //{
            for (fill = 0; fill < (coord[elementh][2]-coord[elementh][0]+1); ++fill)
            {
                puzzle_map[coord[elementh][0]+fill][coord[elementh][1]]=*(*(dict+elementh)+fill);
            }

            //}
        }
        if (coord[elementh][2]==coord[elementh][0])
        {
            //if (coord[elementh][3]>coord[elementh][1])
            //{
            for (fill = 0; fill < (coord[elementh][3]-coord[elementh][1]+1); ++fill)
            {
                puzzle_map[coord[elementh][0]][coord[elementh][1]+fill]=*(*(dict+elementh)+fill);
            }
            //}
        }
        if((coord[elementh][0]!=coord[elementh][2]) && (coord[elementh][1]!=coord[elementh][3]))
        {
            //if (coord[elementh][2]>coord[elementh][0])
            //{
            for (fill = 0; fill < (coord[elementh][2]-coord[elementh][0]+1); ++fill)
            {
                //printf("xx%d \n",fill );
                puzzle_map[coord[elementh][0]+fill][coord[elementh][1]+fill]=*(*(dict+elementh)+fill);
            }

            //}
        }
    }



//firstly we have to print puzzle which is name puzzle map
    show_puzzle_map(puzzle_map);
    do
    {
 
  
        printf("enter a word(type exit game to quit)\n");
//this scanf command gets the string until user enter 'enter' character
        scanf(" %[^\n]s",guess);
        length_of_guess=string_length(guess);
       
        if(1==(canucomp(guess,strexit)))
            exit=1;
        else{
            printf("enter y & x\n");
            scanf("%d",&guess_coord[0]);
            scanf("%d",&guess_coord[1]);
                
            
                //these are the conditions if the check function works succesfully it returns 1 
                if(east_check(guess,length_of_guess,guess_coord,puzzle_map,dict,coord)==1)
                    east_print( length_of_guess,guess_coord,puzzle_map);
                
                else if(west_check(guess,length_of_guess,guess_coord,puzzle_map,dict,coord)==1)
                    west_print( length_of_guess,guess_coord,puzzle_map);
                
                else if (north_check(guess,length_of_guess,guess_coord,puzzle_map,dict,coord)==1)
                    north_print( length_of_guess, guess_coord,puzzle_map);
                
                else if(south_check(guess,length_of_guess,guess_coord,puzzle_map,dict,coord)==1)
                    south_print( length_of_guess, guess_coord,puzzle_map);
                
                else if (south_east_check(guess,length_of_guess,guess_coord,puzzle_map,dict,coord)==1)
                    south_east_print( length_of_guess, guess_coord,puzzle_map);
                
                else if(north_east_check(guess,length_of_guess,guess_coord,puzzle_map,dict,coord)==1)
                    north_east_print( length_of_guess, guess_coord,puzzle_map);
                
                else if(south_west_check(guess,length_of_guess,guess_coord,puzzle_map,dict,coord)==1)
                    south_west_print( length_of_guess, guess_coord, puzzle_map);
                
                else if(north_west_check(guess,length_of_guess,guess_coord,puzzle_map,dict,coord)==1)
                    north_west_print( length_of_guess, guess_coord,puzzle_map);
                
                   else
                        printf("We can not return a word like that\n");
        }           
    } while (exit!=1);







    return 0;


}
char rand_char(int lastletter, int firstletter){
    char out;
    out=(rand()%(lastletter-firstletter+1))+firstletter;//the basic random generater which is the in absolute values
    return out;
}

int east_check(char *guess,int length_of_guess,int guess_coord[2],char puzzle_map[Y][X],char *dict[DICT_SIZE], int coord[DICT_SIZE][4]){
    int result=0;//ı have to give  zero values for the variables
    int i,flag=0;
    for (i = 0; i < length_of_guess &&flag==0; ++i)
    {//ı compare the guess characters and puzzle characters one by one
       if(guess[i]!=puzzle_map[guess_coord[0]][guess_coord[1]+i])
            flag=1;//if ı get different characters flag one behaves like break 
          
    }
     if (i==length_of_guess && flag==0)//this line for safety otherwise we can get some errors and they are not compile time errors 
    {
        result=1;
    }
   
        return result;


}
int west_check(char *guess,int length_of_guess,int guess_coord[2],char puzzle_map[Y][X],char *dict[DICT_SIZE], int coord[DICT_SIZE][4]){
    int result=0;
    int i,flag=0;
    int l=length_of_guess-1;
    for (i = 0; i < length_of_guess &&flag==0; ++i)
    {
       if(guess[l]!=puzzle_map[guess_coord[0]][guess_coord[1]-i])
            flag=1;
       
        l--;        
    }
     if (i==length_of_guess && flag==0)
    {
        result=1;
    }

        return result;


}
int north_check(char *guess,int length_of_guess,int guess_coord[2],char puzzle_map[Y][X],char *dict[DICT_SIZE], int coord[DICT_SIZE][4]){
    int result=0;
    int i,flag=0;
    int l=length_of_guess-1;
    for (i = 0; i < length_of_guess &&flag==0; ++i)
    {
       if(guess[l]!=puzzle_map[guess_coord[0]-i][guess_coord[1]])
            flag=1;
      
        l--;//ıt compares the last character of guess so we can check the reverse strings if the user enters last coordinates        
    }
     if (i==length_of_guess && flag==0)
    {
        result=1;
    }

        return result;


}
int south_check(char *guess,int length_of_guess,int guess_coord[2],char puzzle_map[Y][X],char *dict[DICT_SIZE], int coord[DICT_SIZE][4]){
    int result=0;
    int i,flag=0;
    for (i = 0; i < length_of_guess &&flag==0; ++i)
    {
       if(guess[i]!=puzzle_map[guess_coord[0]+i][guess_coord[1]])
            flag=1;
           
    }
     if (i==length_of_guess && flag==0)
    {
        result=1;
    }

        return result;

}
int south_east_check(char *guess,int length_of_guess,int guess_coord[2],char puzzle_map[Y][X],char *dict[DICT_SIZE], int coord[DICT_SIZE][4]){
    int result=0;
    int i,flag=0;
    for (i = 0; i < length_of_guess &&flag==0; ++i)
    {
       if(guess[i]!=puzzle_map[guess_coord[0]+i][guess_coord[1]+i])
            flag=1;
          
    }
     if (i==length_of_guess && flag==0)
    {
        result=1;
    }
        return result;

}
int north_west_check(char *guess,int length_of_guess,int guess_coord[2],char puzzle_map[Y][X],char *dict[DICT_SIZE], int coord[DICT_SIZE][4]){
    int result=0;
    int i,flag=0,l;
    l=length_of_guess-1;
    for (i = 0; i < length_of_guess &&flag==0; ++i)
    {
       if(guess[l]!=puzzle_map[guess_coord[0]-i][guess_coord[1]-i])
            flag=1;
         
        l--;      
    }
     if (i==length_of_guess && flag==0)
    {
        result=1;
    }

    return result;


}
int north_east_check(char *guess,int length_of_guess,int guess_coord[2],char puzzle_map[Y][X],char *dict[DICT_SIZE], int coord[DICT_SIZE][4]){
    int result=0;
    int i,flag=0;
    for (i = 0; i < length_of_guess &&flag==0; ++i)
    {
       if(guess[i]!=puzzle_map[guess_coord[0]-i][guess_coord[1]+i])
            flag=1;
          
    }
     if (i==length_of_guess && flag==0)
    {
        result=1;
    }
    return result;

}    
int south_west_check(char *guess,int length_of_guess,int guess_coord[2],char puzzle_map[Y][X],char *dict[DICT_SIZE], int coord[DICT_SIZE][4]){
    int result=0;
    int i,flag=0;
    for (i = 0; i < length_of_guess &&flag==0; ++i)
    {
       if(guess[i]!=puzzle_map[guess_coord[0]-i][guess_coord[1]+i])
            flag=1;    
    }
    if (i==length_of_guess && flag==0)
    {
        result=1;
    }

    
    return result;

}        
//compare fuction to check whether wors in dictionary or not
int canucomp(char guess[], char dirct[] ){
    int result=0;
    int i=0;
    int flag=0;
    while(guess[i]==dirct[i] && flag==0){
        if(guess[i]==0 || dirct[i]==0)
            flag=1;
        i++;

    }
    if(guess[i]=='\0' && guess[i]== '\0')
        result=1;
    else
        result=0;

    return result;
}
//to print puzzle array ı have to substract 32 for each character to convert uppercase
void east_print(int length_of_guess,int guess_coord[2],char puzzle_map[Y][X]){
int i=0;
    for (i = 0; i < length_of_guess; ++i)
    {//first array is Y axis other is X axis so ı can declare the directions 
        puzzle_map[guess_coord[0]][guess_coord[1]+i]=puzzle_map[guess_coord[0]][guess_coord[1]+i]-32;
 
    }
 
            show_puzzle_map(puzzle_map);
}
void west_print(int length_of_guess,int guess_coord[2],char puzzle_map[Y][X]){
    int i=0;
    for (i = 0; i < length_of_guess; ++i)
    {
        puzzle_map[guess_coord[0]][guess_coord[1]-i]=puzzle_map[guess_coord[0]][guess_coord[1]-i]-32;
        
    }

            show_puzzle_map(puzzle_map);
}
void north_print(int length_of_guess,int guess_coord[2],char puzzle_map[Y][X]){
    int i=0;
    for (i = 0; i < length_of_guess; ++i)
    {
        puzzle_map[guess_coord[0]-i][guess_coord[1]]=puzzle_map[guess_coord[0]-i][guess_coord[1]]-32;
    
    } 

            show_puzzle_map(puzzle_map);
}
void south_print(int length_of_guess,int guess_coord[2],char puzzle_map[Y][X]){
    int i=0;
    for (i = 0; i < length_of_guess; ++i)
    {
        puzzle_map[guess_coord[0]+i][guess_coord[1]]=puzzle_map[guess_coord[0]+i][guess_coord[1]]-32;
     
    }

            show_puzzle_map(puzzle_map);
 
}
void south_east_print(int length_of_guess,int guess_coord[2],char puzzle_map[Y][X]){
    int i=0;
    for (i = 0; i < length_of_guess; ++i)
    {
        puzzle_map[guess_coord[0]+i][guess_coord[1]+i]=puzzle_map[guess_coord[0]+i][guess_coord[1]+i]-32;
    
    }

            show_puzzle_map(puzzle_map);
 
}
void north_west_print(int length_of_guess,int guess_coord[2],char puzzle_map[Y][X]){
    int i=0;
    for (i = 0; i < length_of_guess; ++i)
    {
        puzzle_map[guess_coord[0]-i][guess_coord[1]-i]=puzzle_map[guess_coord[0]-i][guess_coord[1]-i]-32;
      
    } 

            show_puzzle_map(puzzle_map);
}
void north_east_print(int length_of_guess,int guess_coord[2],char puzzle_map[Y][X]){
    int i=0;
    for (i = 0; i < length_of_guess; ++i)
    {
        puzzle_map[guess_coord[0]-i][guess_coord[1]+i]=puzzle_map[guess_coord[0]-i][guess_coord[1]+i]-32;

    }

            show_puzzle_map(puzzle_map);
}
void south_west_print(int length_of_guess,int guess_coord[2],char puzzle_map[Y][X]){
    int i=0;
    for (i = 0; i < length_of_guess; ++i)
    {
        puzzle_map[guess_coord[0]-i][guess_coord[1]+i]=puzzle_map[guess_coord[0]-i][guess_coord[1]+i]-32;
       
    }

            show_puzzle_map(puzzle_map);
}
void show_puzzle_map(char puzzle_map[Y][X]){
    int i=0,j=0,elementh,fill;
    printf("0 1 2 3 4 5 6 7 8 9 0 1 2 3 4\n");//this line auxilary to see number of lines and rows

    for (i = 0; i <Y ; ++i)
    {
        for (j = 0; j < X; ++j)
        {
            printf("%c ",puzzle_map[i][j]);
        }
        printf("%d",i );
        printf("\n");
    }
    
}
