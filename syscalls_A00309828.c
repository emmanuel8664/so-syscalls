#include <stdio.h>

#include <time.h>

#include <stdlib.h>



main() {
  
int p;
p = fork();
if (p == 0)
{
printf("Tiempo del sistema con precisión de segundos %d \n",time(NULL)); 
  
sleep(3);
  
}
printf("Tiempo del sistema con precisión de segundos %d \n",time(NULL)); 
  
else{
  
time_t current_time;
  
char* c_time_string;
  
current_time = time(NULL);
  
c_time_string = ctime(&current_time);
 
printf("time() convertido a formato de tiempo local GMT 0 %s", c_time_string);

}  
  
return 0;
  
}
