#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

char* ari(char* s){

    int count_alpha = 0;
    int count_word = 0;
    int count_sentence = 0;

    for (int i=0;i< strlen(s); i++){
        if (isalnum(s[i])){
            count_alpha += 1;
        }
        else if (s[i] == '!' || s[i] == '.' || s[i] == '?'){
            count_sentence += 1;
        }
        else if (s[i] == ' '){
            count_word += 1;
        }
    }
    int score = ceil(4.71 * count_alpha/count_word + 0.5 * count_word/count_sentence - 21.43);
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