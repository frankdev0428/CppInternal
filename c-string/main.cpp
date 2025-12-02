
#include <iostream>
using namespace std;


#include <iostream>

using namespace std;





void interleave(char s[], char t[], char buffer[]);




int main() {

    char s[40], t[40], b[80];

    for (int i = 0; i < 10; i++) {

       cout << "Enter s: ";

       cin >> s;

       cout << "Enter t: ";

       cin >> t;

       interleave(s, t, b);

       cout << "Here is the interleave of s and t: ";

       cout << b << endl;
    }

    return 0;

}

/*

void interleave(char s[], char t[], char buffer[]) {

    while (*s != '\0' && *t != '\0')

    {
        *buffer++ = *s++ ;

        *buffer++ = *t++ ;

    }

    while (*s != '\0')

         *buffer++ = *s++;

    while (*t != '\0')

         *buffer++ = *t++; 

    *buffer = '\0';

    

}

*/








/*

void interleave(char s[], char t[], char buffer[]) {
    int i = 0, k = 0;
    while (s[i] != '\0' && t[i] != '\0')
    {
        buffer[k++] = s[i];
        buffer[k++] = t[i];
        i++;
    }
    // Why do we need the if-else ? (THINK)
    if (s[i] != '\0')
        while (s[i] != '\0')
            buffer[k++] = s[i++];
    else       
        while (t[i] != '\0')
            buffer[k++] = t[i++];
    buffer[k] = '\0';
    
}



*/




/*

void interleave(char s[], char t[], char buffer[]) {

    int i = 0, j = 0,  k = 0;

    while (s[i] != '\0' || t[j] != '\0')

    {

        if (s[i] != '\0')

            buffer[k++] = s[i++];

        if (t[j] != '\0')

            buffer[k++] = t[j++];   

    }

    buffer[k] = '\0';

    

}

*/





/*

void interleave(char s[], char t[], char buffer[]) {

    while (*s && *t)

    {

        *buffer++ = *s++ ;

        *buffer++ = *t++ ;

    }

    while (*s)

         *buffer++ = *s++;

    while (*t)

         *buffer++ = *t++; 

    *buffer = '\0';

    

}
*/

void interleave(char s[], char t[], char buffer[]){
   while (*s != '\0' & *t != '\0')
   {
    *buffer++ =
   }
}


