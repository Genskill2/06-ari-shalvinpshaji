#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

char a[20];

int num_alpha(char*);
int num_sentences(char*);
int num_words(char*);
char* ari(char*);

/* int main(){
    char s[2048];
    fgets(s, 2048, stdin);
    char* x = ari(s);
    printf("%s \n", x);
    return 0;

} */

int num_alpha(char* s){
    int count = 0;
    for (int i=0;i< strlen(s); i++){
        if (isalnum(s[i])){
            count += 1;
        }
    }
    return count;
}

int num_sentences(char* s){
    int count = 0;
    for (int i=0; i< strlen(s); i++){
        if (s[i] == '!' || s[i] == '.' || s[i] == '?'){
            count  += 1;
        }  
    }
    return count;
}
int num_words(char* s){
    int count = 0;
    for (int i =0;i< strlen(s); i++){
        if (s[i] == ' '){
            count += 1;
        }
    }
    return count;
}

char* ari(char* s){
    int alpha = num_alpha(s);
    int sen = num_sentences(s);
    int words = num_words(s);
    int score = ceil(4.71 * alpha/words + 0.5 * words/sen - 21.43);
    if (score > 14){
        score = 14;
    }
    if (score < 1){
        score = 1;
    }
    char list[14][20] = {"Kindergarten","First/Second Grade", "Third Grade","Fourth Grade",
                    "Fifth Grade", "Sixth Grade", "Seventh Grade","Eighth Grade",
                    "Ninth Grade", "Tenth Grade", "Eleventh Grade", "Twelfth grade", "College student", "Professor" };
    char* x = list[score - 1];
    /* printf("Characters : %i \nWords : %i \nSentences : %i\nScore : %i\nLevel : %s\n",alpha,words,sen, score, x); */
    return x;

}