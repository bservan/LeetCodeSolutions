static int mystrlen(char *s) {
    int len = 0;
    while (*s++ != '\0')
        ++len;
    return len;
}

int lengthOfLastWord(char * s){
    int i = mystrlen(s) - 1;
    int lenLastWord = 0;

    while (s[i] == ' ') --i;

    while (i >= 0 && s[i--] != ' ') ++lenLastWord;

    return lenLastWord;
}
