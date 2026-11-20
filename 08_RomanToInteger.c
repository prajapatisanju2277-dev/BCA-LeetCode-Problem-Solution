int romanToInt(char* s) {
    int total = 0;

    for(int i = 0; s[i] != '\0'; i++) {
        int current = 0, next = 0;

        switch(s[i]) {
            case 'I': current = 1; break;
            case 'V': current = 5; break;
            case 'X': current = 10; break;
            case 'L': current = 50; break;
            case 'C': current = 100; break;
            case 'D': current = 500; break;
            case 'M': current = 1000; break;
        }

        if(s[i+1] == 'V') next = 5;
        else if(s[i+1] == 'X') next = 10;
        else if(s[i+1] == 'L') next = 50;
        else if(s[i+1] == 'C') next = 100;
        else if(s[i+1] == 'D') next = 500;
        else if(s[i+1] == 'M') next = 1000;

        if(current < next)
            total -= current;
        else
            total += current;
    }

    return total;
}