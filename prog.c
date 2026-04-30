#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define SIZE 6
typedef struct{
char buffer[SIZE];
int head;
int tail;
int count;
}CircularBuffer;
void init(CircularBuffer *cb){
cb->head=0;
cb->tail=0;
cb->count=0;
}
bool isFull(CircularBuffer *cb){
return cb->count==SIZE;
}
bool isEmpty(CircularBuffer *cb){
return cb->count==0;
}
void write(CircularBuffer *cb,char data){
if(isFull(cb)){
printf("Buffer Overflow! لا يمكن كتابة '%c'\n",data);
return;
}
cb->buffer[cb->tail]=data;
cb->tail=(cb->tail+1)%SIZE;
cb->count++;
}
char read(CircularBuffer *cb){
if(isEmpty(cb)){
printf("Buffer Underflow! لا توجد بيانات للقراءة\n");
return '\0';
}
char data=cb->buffer[cb->head];
cb->head=(cb->head+1)%SIZE;
cb->count--;
return data;
}
int main(){
CircularBuffer cb;
init(&cb);
char name[100]="hadeel";
char toAppend[]="CE-ESY";
strcat(name,toAppend);
printf("\nالنص المراد تخزينه: %s\n",name);
printf("حجم المخزن: %d\n",SIZE);
printf("طول النص: %zu\n\n",strlen(name));
for(int i=0;i<strlen(name);i++){
write(&cb,name[i]);
}
printf("\n-- قراءة البيانات من المخزن --\n");
while(!isEmpty(&cb)){
char ch=read(&cb);
if(ch!='\0')
printf("%c",ch);
}
printf("\n\nالمخزن الآن فارغ (isEmpty = %d)\n",isEmpty(&cb));
return 0;
}
